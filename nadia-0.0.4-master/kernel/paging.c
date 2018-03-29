/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */
#define __PAGE_DIRECTORY__
#include "../drivers/vram/display.h"
#include "../include/string.h"
#include "../include/paging.h"
#include "../include/panic.h"
#include "../include/alloc.h"
#include "../include/mem.h"
#include "../include/bitmap.h"

page_directory_t *page_dir;


page_t *get_page(uint32_t frame,uint32_t build, page_directory_t* dir){
    uint32_t n_frame = FRAME_NUMBER(frame);
    uint32_t index = n_frame/PAGE_DIRECTORY_SIZE;
    uint32_t offset = n_frame%PAGE_DIRECTORY_SIZE;
    if(dir->tables[index]){
        return &dir->tables[index]->pages[offset];
    }
    else if(build){
        uint32_t tmp;
        uint8_t* str;
        dir->tables[index] = (page_table_t*) mem_kmalloc_phy_aligned(sizeof(page_table_t), &tmp);
        dir->tables_physical[index] = tmp | 0x7;// present | rw | user
        return &dir->tables[index]->pages[offset];
    }
    else{
        return 0;
    }
}


__void__ kfree_page(page_t* page){
    uint32_t frame;
    if (!(frame=page->frame))
    {
        return;
    }
    else
    {
        
        clear_bit_frame(bitmap,frame);
        page->frame = 0x0;
    }
}

__void__ kalloc_identy_page(uint32_t addr, uint32_t kernel, uint32_t rw){
    page_t* page = get_page(addr,1,current_page_dir);
    if(page->frame != 0){
        panic("this page is allocated!");
        return; // this page is allocated
    }
    else{
        addr = FRAME_NUMBER(addr);
        if (test_bit_frame(bitmap, addr)){
            panic("this page is reserved!\n");
            return;
        }
        set_bit_frame(bitmap, addr);
        page->present = 1;
        page->user = (kernel)?1:0;
        page->rw = (rw)?0:1;
        page->frame = addr;
    }
}

__void__ kalloc_page(page_t *page, uint32_t kernel, uint32_t rw){
    uint8_t* str;
    if(page->frame != 0){
        return; // this 
    }
    else{
        uint32_t index = get_free_frame(bitmap);
        if(index == (uint32_t)-1){
            panic("no free page unavailable!\n");
        }
        set_bit_frame(bitmap,index);
        page->present = 1;
        page->user = (kernel)?1:0;
        page->rw = (rw)?0:1;
        page->frame = index;
    }
}

__void__ __init_paging__(__void__){
    uint32_t st_h = memory_info_system.mem_info_heap_frame_start;
    uint32_t size_h = memory_info_system.mem_info_heap_addr_size;
    //init page directory
    //init page table
    //able paging and swicth page directory
    

    //get page directory

    page_dir = (page_directory_t*) mem_kmalloc_aligned(sizeof(page_directory_t));
    __memset__((uint8_t*)page_dir, 0, sizeof(page_directory_t));

    current_page_dir = page_dir;
    //define addressing memory
    for(uint32_t i= st_h;i<st_h+size_h;i+=0x1000){
        get_page(i,1,current_page_dir);
    }

    uint32_t i=0;
    while(i < current_addr_frame){
        kalloc_identy_page(i, 1, 1);
        i+=PAGE_SIZE;
    }
    switch_page_directory(page_dir);

    __kprint_video__("\npaging initialize --- [ ok ] \n");
}


__void__ switch_page_directory(page_directory_t* dir){
    current_page_dir = dir;
    uint32_t cr0;
    __asm__ __volatile__("mov %0, %%cr3"::"r"(&dir->tables_physical));
    __asm__ __volatile__("mov %%cr0, %0":"=r"(cr0):);
    cr0 |= 0x80000000;
    __asm__ __volatile__("mov %0, %%cr0"::"r"(cr0));
}


#define __PAGING_H__
#define __MEMORY_H__
#include "../include/paging.h"
#include "../include/panic.h"
#include "../drivers/graphics/display.h"

uint32_t* frames;
page_directory_t* page_dir, *current_page_dir;
uint32_t n_frames;
uint32_t start_addr = (uint32_t) LOW_MEMORY; // address allocation start in &end


 
__void__ __init_paging__(__void__){
    __kprint_video__("paging initialize --- [ ok ] \n");
    //init page directory
    //init page table
    //able paging and swicth page directory
    
    n_frames = HIGH_MEMORY/PAGE_SIZE;
    frames = (uint32_t*) kmalloc(INDEX_FROM_BIT(n_frames));
    __memset__((uint8_t*)frames, 0, INDEX_FROM_BIT(n_frames));

    //get page directory

    page_dir = (page_directory_t*) kmalloc_align(sizeof(page_directory_t));
    __memset__((uint8_t*)page_dir, 0, sizeof(page_directory_t));
    current_page_dir = page_dir;
    uint32_t i=0;
    uint32_t cur_addr = start_addr;
    while(i < start_addr){
        __alloc_frame__(__get_page__(i, 1, page_dir), 0, 0);
        i+=PAGE_SIZE;
    }
    switch_page_directory(page_dir);
}

 __static__ __void__ __set_frame__(uint32_t frames_addr){
    uint32_t frame = frames_addr/PAGE_SIZE;
    uint32_t index_bit = INDEX_FROM_BIT(frame);
    uint32_t offset_bit = OFFSET_FROM_BIT(frame);
    frames[index_bit] |= (1 << offset_bit);
 }
__static__ uint32_t __get_frame__(__void__){
    uint32_t i,j;
    for(i=0;i<INDEX_FROM_BIT(n_frames);i++){
        if(frames[i] != 0xFFFFFFFF){
            for(j=0; j<FBYTE; j++){
                if(!(frames[i]&(1 << j))){
                    return i*FBYTE+j;
                }
            }
        }
    }
    return (uint32_t) -1;
}
__static__ __void__ __clear_frame__(uint32_t frames_addr){
    uint32_t frame = frames_addr/PAGE_SIZE;
    uint32_t index_bit = INDEX_FROM_BIT(frame);
    uint32_t offset_bit = OFFSET_FROM_BIT(frame);
    frames[index_bit] &= ~(1 << offset_bit);
}
__static__ uint32_t __test_frame__(uint32_t frames_addr){
    uint32_t frame = frames_addr/PAGE_SIZE;
    uint32_t index_bit = INDEX_FROM_BIT(frame);
    uint32_t offset_bit = OFFSET_FROM_BIT(frame);
    return (frames[index_bit] & (1 << offset_bit));
}
__void__ __alloc_frame__(page_t *page, uint32_t isKernel, uint32_t isWriteable){
    if(page->frame != 0){
        return;
    }
    else{
        uint32_t index_bit = __get_frame__();
        if(index_bit == (uint32_t) -1){
            panic("No free frames!");
        }
        __set_frame__(index_bit*PAGE_SIZE);
        page->present = 1;
        page->rw = (isWriteable)?0:1;
        page->user = (isKernel)?1:0;
        page->frame = index_bit;
    }
}
__void__ __free_frame__(page_t *page){
    uint32_t frame;
    if(!(frame = page->frame)){
        return;
    }else{
        __clear_frame__(frame);
        page->frame = 0x0;
    }
}

__void__ switch_page_directory(page_directory_t* dir){
    current_page_dir = dir;
    uint32_t cr0;
    __asm__ __volatile__("mov %0, %%cr3"::"r"(&dir->tables_physical));
    __asm__ __volatile__("mov %%cr0, %0":"=r"(cr0):);
    cr0 |= 0x80000000;
    __asm__ __volatile__("mov %0, %%cr0"::"r"(cr0));
}

page_t* __get_page__(uint32_t addr, int32_t make,page_directory_t* dir){
    addr /= PAGE_SIZE;
    uint32_t table_entry = addr/1024;
    if(dir->tables[table_entry]){
        return &dir->tables[table_entry]->pages[addr%1024];
    }
    else if(make){
        uint32_t tmp;
        dir->tables[table_entry] = (page_table_t*) kmalloc_phy_align(sizeof(page_table_t), &tmp);
        __memset__((uint8_t*)dir->tables[table_entry], 0,sizeof(page_table_t));
        dir->tables_physical[table_entry] = tmp|0x7;
        return &dir->tables[table_entry]->pages[addr%1024];
    }
}

uint32_t kmalloc_main (uint32_t size, int32_t align, uint32_t* physical_addr){
    if(align == 1 && (start_addr & 0xFFFFF000)){
        start_addr &= 0xFFFFF000;
        start_addr += PAGE_SIZE;
    }
    if(physical_addr){
        *physical_addr = start_addr;
    }
    uint32_t addr_p = start_addr;
    start_addr += size;
    return addr_p;
}

uint32_t kmalloc (uint32_t size){
    return kmalloc_main(size, 0,0);
}
uint32_t kmalloc_align (uint32_t size){
    return kmalloc_main(size, 1,0);
}
uint32_t kmalloc_phy (uint32_t size, uint32_t* physical_addr){
    return kmalloc_main(size, 0,physical_addr);
}
uint32_t kmalloc_phy_align (uint32_t size, uint32_t* physical_addr){
    return kmalloc_main(size, 1,physical_addr);
}

/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#define __POS_FRAME__
#include "../include/alloc.h"
#include "../drivers/vram/display.h"



//Allow to reserve space in memory
uint32_t mem_kmalloc_real(size_t size,uint32_t page_aligned, uint32_t* frame){
    
    
    if(page_aligned == 1 && (0xFFFFF000 & current_addr_frame)){
        // take position of next page
        current_addr_frame &= 0xFFFFF000;
        current_addr_frame += PAGE_SIZE;
    }
    if(frame){
        *frame = current_addr_frame;
    }
    uint32_t tmp = current_addr_frame;
    current_addr_frame += size;
    return tmp;
    
}

uint32_t mem_kmalloc(size_t size){
    return mem_kmalloc_real(size, 0,0);
}

uint32_t mem_kmalloc_aligned(size_t size){
    return mem_kmalloc_real(size, 1,0);
}

uint32_t mem_kmalloc_phy(size_t size, uint32_t* frame){
    return mem_kmalloc_real(size, 0,frame);
}

uint32_t mem_kmalloc_phy_aligned(size_t size,uint32_t* frame){
    return mem_kmalloc_real(size, 1,frame);
}
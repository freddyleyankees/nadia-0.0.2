/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#define __MEMORY_INFO__
#include "../include/kernel.h"
#include "../include/alloc.h"
#include "../include/paging.h"
#include "../include/bitmap.h"
#include "../include/heap.h"

__extern__ uint32_t end;

__void__ init_mem_kernel(__void__){
    memory_info_system.mem_info_upper = 0x40000000;
    memory_info_system.mem_info_lower = 0x100000;
    memory_info_system.mem_info_bit_per_int_page = 0x20;
    memory_info_system.mem_info_heap_sect_int = 0x4;
    memory_info_system.mem_info_page_size = 0x1000;
    memory_info_system.mem_info_cur_pos_frame = (uint32_t) &end;
	memory_info_system.mem_info_nb_page = memory_info_system.mem_info_upper/memory_info_system.mem_info_page_size;
	memory_info_system.mem_info_heap_frame_start = 0xC0000000;
	memory_info_system.mem_info_heap_addr_size = 0x10000000;
	memory_info_system.mem_info_heap_size_default = 0xa*memory_info_system.mem_info_page_size;
	memory_info_system.mem_info_heap_nb_block = memory_info_system.mem_info_heap_addr_size/memory_info_system.mem_info_heap_sect_int;
    memory_info_system.mem_info_all_mem_avail = memory_info_system.mem_info_heap_addr_size;

    
    //init address position
    
    current_addr_frame  = (uint32_t) memory_info_system.mem_info_cur_pos_frame;
    
    init_mem_bitmap();
    mem_heap_init();
    __init_paging__();
}

uint32_t page_size_used (__void__){
	for(;;);
}

uint32_t all_mem_size_used (__void__){
	for(;;);
}

uint32_t all_mem_size_avail (__void__){
	for(;;);
}

uint32_t all_kernel_mem_size_used (__void__){
	for(;;);
}

uint32_t all_user_mem_size_used (__void__){
	for(;;);
}
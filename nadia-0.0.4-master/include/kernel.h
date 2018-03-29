/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __NADIA_KERNEL_H__
#define __NADIA_KERNEL_H__

#include "types.h"

__void__ init_mem_kernel(__void__);
uint32_t page_size_used (__void__);
uint32_t all_mem_size_used (__void__);
uint32_t all_mem_size_avail (__void__);
uint32_t all_kernel_mem_size_used (__void__);
uint32_t all_user_mem_size_used (__void__);

    #ifdef __USER_MEMORY__
        uint32_t cur_page_avail = 0;
    #else
        __extern__ uint32_t cur_page_avail;
    #endif
#endif
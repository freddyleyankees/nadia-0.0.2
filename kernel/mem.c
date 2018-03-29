/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#define __MEMORY_H__
#include "../include/mem.h"

__void__ __memset__ (uint8_t* dest,uint8_t value,uint32_t size){
	uint8_t *temp = (uint8_t *)dest;
    for ( ; size != 0; size--) *temp++ = value;
}

__void__ __memcpy__ (uint8_t* dest,uint8_t* src, uint32_t size){
	uint8_t *temp = (uint8_t *)dest;
    for ( ; size != 0; size--) *temp++ = *src++;
}

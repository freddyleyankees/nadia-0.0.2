#define __MEMORY_H__
#include "../include/segment.h"

__void__ __memset__ (uint8_t* dest,uint8_t value,uint32_t size){
	uint8_t *temp = (uint8_t *)dest;
    for ( ; size != 0; size--) *temp++ = value;
}

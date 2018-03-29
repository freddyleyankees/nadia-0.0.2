/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "types.h"
#ifndef __MEMORY_H__
#define __MEMORY_H__

	__void__ __memset__ (uint8_t*,uint8_t,uint32_t);
	__void__ __memcpy__ (uint8_t*,uint8_t*, uint32_t);
	__void__ __pagecpy__ (uint32_t,uint32_t,uint8_t);
	__void__ __tablecpy__ (uint32_t,uint32_t,uint8_t);
	__void__ __get_double_word__ (uint32_t,uint32_t,uint8_t);
	__void__ __get_word__ (uint32_t,uint32_t,uint8_t);
	__void__ __get_byte__ (uint32_t,uint32_t,uint8_t);
#endif


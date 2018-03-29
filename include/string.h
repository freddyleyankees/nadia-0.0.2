/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __STRING_H__
#define __STRING_H__ 

#include "types.h" 

typedef int list_argv_t;

int32_t __atoi__(uint8_t*);

int32_t __atoib__(uint8_t*, uint8_t);

uint8_t* __itoa__(int32_t);

uint8_t* __itoab__(int32_t, uint8_t);

uint32_t __strlen__(uint8_t*);

uint32_t __strcpy__(uint8_t*, uint8_t*);

uint32_t __strsrch__(uint8_t*, uint8_t*);

uint32_t __strcmp__(uint8_t*, uint8_t*);

uint32_t __stroccur__(uint8_t*, uint8_t*);

uint32_t __strmem__(uint8_t*);

uint8_t __isDigit__(__void__);

uint8_t __isString__(__void__);

uint8_t __getChar__(__void__);

__void__ __putChar__(uint8_t);
__void__ test(__void__);

uint8_t* str_buffer;
#endif

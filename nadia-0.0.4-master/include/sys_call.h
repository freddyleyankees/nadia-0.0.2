/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __SYS_CALL_H__
#define __SYS_CALL_H__
#include "types.h"
#include "handler.h"
#define INT_SYS_CALL 96
__void__ syscall_callback(registers_t);
__void__ write_sys_console(uint8_t* );
__void__ write(uint8_t fd, uint8_t* buffer,uint32_t size, uint32_t count);
const uint8_t* read(uint8_t fd,uint32_t size, uint32_t count);

#endif
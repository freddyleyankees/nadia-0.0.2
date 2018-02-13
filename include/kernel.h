/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __NADIA_KERNEL_H__
#define __NADIA_KERNEL_H__

#ifndef __CONSOLE_H__
#define __CONSOLE_H__
#include "../include/types.h"
#include "../include/string.h"


__extern__ __void__ __kprint_video__(uint8_t* str);

uint8_t console_buffer;
typedef __void__ (*__console_t__)(uint8_t*, ...);
typedef __void__ (*__console_v_t__)(__void__);
typedef struct terminal
{
	__console_t__ write;
	__console_t__ error;
	__console_t__ trace;
	__console_t__ emergeny;
	__console_t__ critical;
	__console_t__ warning;
	__console_t__ assert;
	__console_v_t__ clear;
} term_t;

__void__ console_write(uint8_t*, ...);
__void__ console_error(uint8_t*, ...);
__void__ console_assert(uint8_t*, ...);
__void__ console_emergeny(uint8_t*, ...);
__void__ console_warning(uint8_t*, ...);
__void__ console_critical(uint8_t*, ...);
__void__ console_trace(uint8_t*, ...);
__void__ console_clear(__void__);

__static__ __void__ setHandlerConsoleWrite(__console_t__);
__static__ __void__ setHandlerConsoleClear(__console_v_t__);
__static__ __void__ setHandlerConsoleError(__console_t__);
__static__ __void__ setHandlerConsoleTrace(__console_t__);
__static__ __void__ setHandlerConsoleAssert(__console_t__);
__static__ __void__ setHandlerConsoleWarning(__console_t__);
__static__ __void__ setHandlerConsoleEmergeny(__console_t__);
__static__ __void__ setHandlerConsoleCritical(__console_t__);
__void__ initHandlerConsole(__void__);

uint32_t* argvPtr;

__static__ uint32_t* getAgrv(uint8_t*, list_argv_t*);

#endif

#endif
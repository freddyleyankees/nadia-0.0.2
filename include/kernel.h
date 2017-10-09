#ifndef __NADIA_KERNEL_H__
#define __NADIA_KERNEL_H__

#ifndef __CONSOLE_H__
#define __CONSOLE_H__
#include "../include/types.h"
#include "../include/string.h"


__extern__ __void__ __kprint_video__(const char* str);

uint8_t console_buffer;
typedef __void__ (*__console_t__)(uint8_t*, ...);
typedef struct terminal
{
	__console_t__ write;
	__console_t__ error;
} term_t;

__void__ console_write(uint8_t*, ...);
__static__ __void__ setHandlerConsoleWrite(__console_t__);
__static__ __void__ setHandlerConsoleError(__console_t__);
__void__ initHandlerConsole(__void__);

uint32_t* argvPtr;

__static__ uint32_t* getAgrv(uint8_t*, list_argv_t*);

#endif

#endif
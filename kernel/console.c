/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/kernel.h"
#include "../drivers/keyboard/keyboard.h"
#include "../drivers/graphics/display.h"

term_t console;

__static__ __inline__ uint32_t* getAgrv(uint8_t* str, list_argv_t* list){
	 
}

__void__ console_write(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__void__ console_error(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__void__ console_trace(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__void__ console_assert(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__void__ console_emergeny(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__void__ console_critical(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__void__ console_clear(__void__){
	__cleanterm__();
}

__void__ console_warning(uint8_t* str, ...){
	list_argv_t argv[1024];
	uint32_t count = 0;

	__kprint_video__(str);
}

__static__ __void__ setHandlerConsoleWrite(__console_t__ handler){
	console.write = handler;
}

__static__ __void__ setHandlerConsoleError(__console_t__ handler){
	console.error = handler;
}

__static__ __void__ setHandlerConsoleAssert(__console_t__ handler){
	console.assert = handler;
}

__static__ __void__ setHandlerConsoleEmergeny(__console_t__ handler){
	console.emergeny = handler;
}

__static__ __void__ setHandlerConsoleTrace(__console_t__ handler){
	console.trace = handler;
}

__static__ __void__ setHandlerConsoleCritical(__console_t__ handler){
	console.critical = handler;
}

__static__ __void__ setHandlerConsoleWarning(__console_t__ handler){
	console.warning = handler;
}

__static__ __void__ setHandlerConsoleClear(__console_v_t__ handler){
	console.clear = handler;
}
__void__ initHandlerConsole(__void__){
	setHandlerConsoleWrite(&console_write);
	setHandlerConsoleClear(&console_clear);
	setHandlerConsoleError(&console_error);
	setHandlerConsoleTrace(&console_trace);
	setHandlerConsoleAssert(&console_assert);
	setHandlerConsoleWarning(&console_warning);
	setHandlerConsoleEmergeny(&console_emergeny);
	setHandlerConsoleCritical(&console_critical);
	console.clear();
}

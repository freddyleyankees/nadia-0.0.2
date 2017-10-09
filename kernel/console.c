
#include "../include/kernel.h"

term_t console;

__static__ __inline__ uint32_t* getAgrv(uint8_t* str, list_argv_t* list){
	 
}


__void__ console_write(uint8_t* str, ...){
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

__void__ initHandlerConsole(__void__){
	setHandlerConsoleWrite(&console_write);
	setHandlerConsoleError(&console_write);
}


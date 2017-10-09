#include "../include/types.h"
#ifndef __DESCR_TABLE_H__
#define __DESCR_TABLE_H__
#define __FREQ__	100
#endif
#include "../include/io.h"
#include "../include/segment.h"
#include "../include/pit.h"
#include "../include/kernel.h"
#include "../drivers/keyboard/keyboard.h"

__extern__ term_t console;

__extern__ __void__ __kprint_video__(const char* str);

__extern__ __void__ __cleanterm__();

__extern__ __void__ __pci_detect_device__(__void__);

__extern__ __void__ main(__void__* multiboot_struct){
	/* code */
	__cleanterm__();
	__kprint_video__("System is starting --- \n");
	__init_table_descr__();
	__kprint_video__("-------------------------------------------------------------------------------\n");
	__init_timer__(__FREQ__);
	__init_keyboard_driver__();
	__pci_detect_device__();
	initHandlerConsole();
	console.write("test console \n");
	while(1);
}

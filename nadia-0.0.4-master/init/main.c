/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/types.h"
#ifndef __DESCR_TABLE_H__
#define __DESCR_TABLE_H__
#define __FREQ__	100
#endif
#include "../include/io.h"
#include "../include/int.h"
#include "../include/mem.h"
#include "../include/segment.h"
#include "../include/panic.h"
#include "../include/pit.h"
#include "../include/heap.h"
#include "../include/kernel.h"
#include "../drivers/keyboard/keyboard.h"
#include "../drivers/vram/display.h"

__extern__ __void__ __pci_detect_device__(__void__);

__void__ main(__void__* multiboot_struct){
	/* code */
	uint8_t* str;
	enable_cursor(0x0, 0xc);
	__cleanterm__();
	__init_table_descr__();
	init_int();
	init_mem_kernel();
	__kprint_video__("\nSystem is starting --- \n");
	__kprint_video__("-------------------------------------------------------------------------------\n");
	__init_timer__(__FREQ__);
	__init_keyboard_driver__();
	while(1);
}




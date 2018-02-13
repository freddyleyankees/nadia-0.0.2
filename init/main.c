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
#include "../include/segment.h"
#include "../include/paging.h"
#include "../include/pit.h"
#include "../include/kernel.h"
#include "../sys/terminal.h"
#include "../drivers/keyboard/keyboard.h"

__extern__ term_t console;

uint16_t* tmpTermheader;
uint16_t* tmpTermbody;
uint16_t* tmpTermfooter;

interface_t headerScreen;
interface_t bodyScreen;
interface_t footerScreen;

__extern__ __void__ start_console(__void__);
__extern__ __void__ __kprint_video__(uint8_t* str);

__extern__ __void__ __cleanterm__();

__extern__ __void__ __pci_detect_device__(__void__);

__void__ main(__void__* multiboot_struct){
	/* code */
	enable_cursor(0,15);
	__cleanterm__();
	__init_paging__();
	__kprint_video__("System is starting --- \n");
	__init_table_descr__();
	init_int();
	__kprint_video__("-------------------------------------------------------------------------------\n");
	__init_timer__(__FREQ__);
	__init_keyboard_driver__();
	initHandlerConsole();
	start_console();

	while(1);
}

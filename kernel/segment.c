/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#define __DESCR_TABLE_H__
#include "../include/idt.h"
#include "../include/handler.h"

__extern__ __void__ __init_gdt__(__void__);
__extern__ __void__ __init_idt__(__void__);
__extern__ __void__ __INIT_PIC__(__void__);
__extern__ __void__ __kprint_video__(const char* str);

__extern__ __isr_t__ int_handler[];

__void__ __init_table_descr__(){
	__init_gdt__();
	__kprint_video__("GDT is initialized --- [ ok ]\n");
	__INIT_PIC__();
	__init_idt__();
	__kprint_video__("IDT is initialized --- [ ok ]\n");
	__memset__((uint8_t*) &int_handler,0,sizeof(__isr_t__)*256);
	__activate_All_int__();
	__kprint_video__("All interrupts are actived --- [ ok ]\n");
}
/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */


#include "../include/idt.h"
#include "../include/segment.h"
#include "../include/mem.h"
#include "../include/handler.h"

__extern__ __void__ __init_gdt__(__void__);
__extern__ __void__ __init_idt__(__void__);
__extern__ __void__ __INIT_PIC__(__void__);

__extern__ __isr_t__ int_handler[];

__void__ __init_table_descr__(){
	__init_gdt__();
	__INIT_PIC__();
	__init_idt__();
	__memset__((uint8_t*) &int_handler,0,sizeof(__isr_t__)*256);
	__activate_All_int__();
}
/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/pit.h"
#include "../include/io.h"
#include "../include/string.h"
#include "../drivers/vram/display.h"

__static__ __void__ __timer_callback__(registers_t reg){
	__static__ uint32_t tic = 0;
	uint8_t* str;
	++tic;
	if(tic%10 == 0){
		
	}
}

__void__ __init_timer__(uint32_t freq){
	__register_int_handler__(IRQ0,&__timer_callback__);
	uint32_t divid = 1193180/freq;

	outb(0x43, 0x36);/* channel 0 -> 00 11 x11 0*/
	outb(0x43, 0x54);/* channel 1 -> 01 10 x10 0*/
	outb(0x43, 0xB6);/* channel 2 -> */

	outb(0x40, 0x00);
	outb(0x40, 0x00);

	outb(0x41, 0x12);

	outb(0x40, 0xd1);
	outb(0x40, 0x11);

	uint8_t l = (uint8_t)(divid & 0xFF);
	uint8_t h = (uint8_t)((divid>>8) & 0xFF); 

	outb(0x43, 0x36);/* channel 0 -> 00 11 x11 0*/
	outb(0x40, l);
	outb(0x40, h);
	__kprint_video__("Timer is initialized --- [ ok ] \n");
}
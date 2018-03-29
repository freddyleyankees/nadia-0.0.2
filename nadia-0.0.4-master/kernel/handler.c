/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __ISR_H__
#define __ISR_H__
#endif
#include "../include/handler.h"
#include "../include/io.h"

__isr_t__ int_handler[256];

__void__ __register_int_handler__(uint32_t n, __isr_t__ handler){
	int_handler[n] = handler;
}

__extern__ __void__ __isr_handler__(registers_t reg){
	if (int_handler[reg.num_int] != 0)
    {
        __isr_t__ handler = int_handler[reg.num_int];
        handler(reg);
    }
}

__extern__ __void__ __irq_handler__(registers_t reg){
	if (reg.num_int >= 40)
	{
		/* code */
		outb(0xA0, 0x20);
	}
	outb(0x20, 0x20)
	if (int_handler[reg.num_int] != 0)
	{
		/* code */
		__isr_t__ handler = int_handler[reg.num_int];
		handler(reg);
	}
}
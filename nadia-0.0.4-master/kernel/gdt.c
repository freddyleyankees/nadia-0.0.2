/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/gdt.h"

gdt_entry_t gdt_entry[5];
gdt_ptr_t gdt_ptr;

__extern__ __void__ __init_gdt__(__void__){
	gdt_ptr.limit = 8*5-1;
	gdt_ptr.base = (uint32_t) &gdt_entry;

	__set_gdt__(0,0x0,0x0,0x0,0x0);
	__set_gdt__(1,0,0xFFFFFFFF, 0x9A, 0xCF);
	__set_gdt__(2,0,0xFFFFFFFF, 0x92, 0xCF);
	__set_gdt__(3,0,0xFFFFFFFF,0xFA, 0xCF);
	__set_gdt__(4,0,0xFFFFFFFF, 0xF2, 0xCF);

	__gdt_up__((uint32_t) &gdt_ptr);
}

__static__ __void__ __set_gdt__(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity){
	gdt_entry[num].base_low = (base & 0xFFFF);
	gdt_entry[num].base_middle = (base >> 16) & 0xFF;
	gdt_entry[num].base_high = (base >> 24) & 0xFF;
	gdt_entry[num].limit_low = (limit & 0xFFFF);
	gdt_entry[num].granularity = (limit >> 16) & 0x0F;
	gdt_entry[num].granularity |= granularity & 0xF0;
	gdt_entry[num].access = access;

}

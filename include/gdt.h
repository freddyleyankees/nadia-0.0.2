#include "types.h"
#ifndef __GDT_H__
#define __GDT_H__ 

	struct gdt_entry_struct{
		uint16_t limit_low;
		uint16_t base_low;
		uint8_t base_middle;
		uint8_t access;
		uint8_t granularity;
		uint8_t base_high;
	} __attribute__((packed));

	struct gdt_ptr_struct{
		uint16_t limit;
		uint32_t base;
	} __attribute__((packed));

	typedef struct gdt_entry_struct gdt_entry_t;
	typedef struct gdt_ptr_struct gdt_ptr_t;

	__static__ __void__ __set_gdt__(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);
	__extern__ __void__ __gdt_up__(uint32_t);

#endif
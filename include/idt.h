#ifndef __IDT_H__
#define __IDT_H__
#define __MEMORY_H__
#include "segment.h"

	#define __INTGATE__	  		0x8E		
	#define __TRAPGATE__ 		0x8F	
	#define __SYSTEMGATE__	 	0xEF

	struct idt_entry_struct
	{
		uint16_t base_low;
		uint16_t select;
		uint8_t type;
		uint8_t flags;
		uint16_t base_high;
	} __attribute__((packed));

	struct idt_ptr_struct
	{
		uint16_t limit;
		uint32_t base;
	} __attribute__((packed));

	typedef struct idt_entry_struct idt_entry_t;
	typedef struct idt_ptr_struct idt_ptr_t;

	__static__ __void__ __set_idt__(int8_t, uint32_t, uint16_t, uint8_t);
	__void__ __activate_All_int__();
	__static__ __void__ __activate_int__(int8_t);
	__static__ __void__ __deactivate_int__(int8_t);
	__static__ __void__ __reset_int__(int8_t);
	__extern__ __void__ __idt_up__(uint32_t);
	
	__extern__ __void__ __asm_int_ign__(__void__);
	__extern__ __void__ __asm_isr_def__(__void__);

	__extern__ __void__ __asm_isr_0__(__void__);
	__extern__ __void__ __asm_isr_1__(__void__);
	__extern__ __void__ __asm_isr_2__(__void__);
	__extern__ __void__ __asm_isr_3__(__void__);
	__extern__ __void__ __asm_isr_4__(__void__);
	__extern__ __void__ __asm_isr_5__(__void__);
	__extern__ __void__ __asm_isr_6__(__void__);
	__extern__ __void__ __asm_isr_7__(__void__);
	__extern__ __void__ __asm_isr_8__(__void__);
	__extern__ __void__ __asm_isr_9__(__void__);
	__extern__ __void__ __asm_isr_10__(__void__);
	__extern__ __void__ __asm_isr_11__(__void__);
	__extern__ __void__ __asm_isr_12__(__void__);
	__extern__ __void__ __asm_isr_13__(__void__);
	__extern__ __void__ __asm_isr_14__(__void__);
	__extern__ __void__ __asm_isr_15__(__void__);
	__extern__ __void__ __asm_isr_16__(__void__);
	__extern__ __void__ __asm_isr_17__(__void__);
	__extern__ __void__ __asm_isr_18__(__void__);
	__extern__ __void__ __asm_isr_19__(__void__);
	__extern__ __void__ __asm_isr_20__(__void__);
	__extern__ __void__ __asm_isr_21__(__void__);
	__extern__ __void__ __asm_isr_22__(__void__);
	__extern__ __void__ __asm_isr_23__(__void__);
	__extern__ __void__ __asm_isr_24__(__void__);
	__extern__ __void__ __asm_isr_25__(__void__);
	__extern__ __void__ __asm_isr_26__(__void__);
	__extern__ __void__ __asm_isr_27__(__void__);
	__extern__ __void__ __asm_isr_28__(__void__);
	__extern__ __void__ __asm_isr_29__(__void__);
	__extern__ __void__ __asm_isr_30__(__void__);
	__extern__ __void__ __asm_isr_31__(__void__);

	__extern__ __void__ __asm_irq_0__(__void__);
	__extern__ __void__ __asm_irq_1__(__void__);
	__extern__ __void__ __asm_irq_2__(__void__);
	__extern__ __void__ __asm_irq_3__(__void__);
	__extern__ __void__ __asm_irq_4__(__void__);
	__extern__ __void__ __asm_irq_5__(__void__);
	__extern__ __void__ __asm_irq_6__(__void__);
	__extern__ __void__ __asm_irq_7__(__void__);
	__extern__ __void__ __asm_irq_8__(__void__);
	__extern__ __void__ __asm_irq_9__(__void__);
	__extern__ __void__ __asm_irq_10__(__void__);
	__extern__ __void__ __asm_irq_11__(__void__);
	__extern__ __void__ __asm_irq_12__(__void__);
	__extern__ __void__ __asm_irq_13__(__void__);
	__extern__ __void__ __asm_irq_14__(__void__);
	__extern__ __void__ __asm_irq_15__(__void__);

#endif
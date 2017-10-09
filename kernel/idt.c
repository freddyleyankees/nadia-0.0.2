#include "../include/idt.h"



idt_entry_t idt_entry[256];
idt_ptr_t idt_ptr;


__extern__ __void__ __init_idt__(__void__){
	idt_ptr.limit = 256*8-1;
	idt_ptr.base = (uint32_t) &idt_entry;

	__memset__((uint8_t*) &idt_entry,0,(256*8));

	__set_idt__(0,(uint32_t) __asm_isr_0__,0x08, __INTGATE__);
	__set_idt__(1,(uint32_t) __asm_isr_1__,0x08, __INTGATE__);
	__set_idt__(2,(uint32_t) __asm_isr_2__,0x08, __INTGATE__);
	__set_idt__(3,(uint32_t) __asm_isr_3__,0x08, __INTGATE__);
	__set_idt__(4,(uint32_t) __asm_isr_4__,0x08, __INTGATE__);
	__set_idt__(5,(uint32_t) __asm_isr_5__,0x08, __INTGATE__);
	__set_idt__(6,(uint32_t) __asm_isr_5__,0x08, __INTGATE__);
	__set_idt__(7,(uint32_t) __asm_isr_7__,0x08, __INTGATE__);
	__set_idt__(8,(uint32_t) __asm_isr_8__,0x08, __INTGATE__);
	__set_idt__(9,(uint32_t) __asm_isr_9__,0x08, __INTGATE__);
	__set_idt__(10,(uint32_t) __asm_isr_10__,0x08, __INTGATE__);
	__set_idt__(11,(uint32_t) __asm_isr_11__,0x08, __INTGATE__);
	__set_idt__(12,(uint32_t) __asm_isr_12__,0x08, __INTGATE__);
	__set_idt__(13,(uint32_t) __asm_isr_13__,0x08, __INTGATE__);
	__set_idt__(14,(uint32_t) __asm_isr_14__,0x08, __INTGATE__);
	__set_idt__(15,(uint32_t) __asm_isr_15__,0x08, __INTGATE__);
	__set_idt__(16,(uint32_t) __asm_isr_16__,0x08, __INTGATE__);
	__set_idt__(17,(uint32_t) __asm_isr_17__,0x08, __INTGATE__);
	__set_idt__(18,(uint32_t) __asm_isr_18__,0x08, __INTGATE__);
	__set_idt__(19,(uint32_t) __asm_isr_19__,0x08, __INTGATE__);
	__set_idt__(20,(uint32_t) __asm_isr_20__,0x08, __INTGATE__);
	__set_idt__(21,(uint32_t) __asm_isr_21__,0x08, __INTGATE__);
	__set_idt__(22,(uint32_t) __asm_isr_22__,0x08, __INTGATE__);
	__set_idt__(23,(uint32_t) __asm_isr_23__,0x08, __INTGATE__);
	__set_idt__(24,(uint32_t) __asm_isr_24__,0x08, __INTGATE__);
	__set_idt__(25,(uint32_t) __asm_isr_25__,0x08, __INTGATE__);
	__set_idt__(26,(uint32_t) __asm_isr_26__,0x08, __INTGATE__);
	__set_idt__(27,(uint32_t) __asm_isr_27__,0x08, __INTGATE__);
	__set_idt__(28,(uint32_t) __asm_isr_28__,0x08, __INTGATE__);
	__set_idt__(29,(uint32_t) __asm_isr_29__,0x08, __INTGATE__);
	__set_idt__(30,(uint32_t) __asm_isr_30__,0x08, __INTGATE__);
	__set_idt__(31,(uint32_t) __asm_isr_31__,0x08, __INTGATE__);

	__set_idt__(32,(uint32_t) __asm_irq_0__,0x08, __INTGATE__);
	__set_idt__(33,(uint32_t) __asm_irq_1__,0x08, __INTGATE__);
	__set_idt__(34,(uint32_t) __asm_irq_2__,0x08, __INTGATE__);
	__set_idt__(35,(uint32_t) __asm_irq_3__,0x08, __INTGATE__);
	__set_idt__(36,(uint32_t) __asm_irq_4__,0x08, __INTGATE__);
	__set_idt__(37,(uint32_t) __asm_irq_5__,0x08, __INTGATE__);
	__set_idt__(38,(uint32_t) __asm_irq_6__,0x08, __INTGATE__);
	__set_idt__(39,(uint32_t) __asm_irq_7__,0x08, __INTGATE__);
	__set_idt__(40,(uint32_t) __asm_irq_8__,0x08, __INTGATE__);
	__set_idt__(41,(uint32_t) __asm_irq_9__,0x08, __INTGATE__);
	__set_idt__(42,(uint32_t) __asm_irq_10__,0x08, __INTGATE__);
	__set_idt__(43,(uint32_t) __asm_irq_11__,0x08, __INTGATE__);
	__set_idt__(44,(uint32_t) __asm_irq_12__,0x08, __INTGATE__);
	__set_idt__(45,(uint32_t) __asm_irq_13__,0x08, __INTGATE__);
	__set_idt__(46,(uint32_t) __asm_irq_14__,0x08, __INTGATE__);
	__set_idt__(47,(uint32_t) __asm_irq_15__,0x08, __INTGATE__);


	__idt_up__((uint32_t) &idt_ptr);
}

__void__ __activate_All_int__(){
	__asm__ __volatile__("sti");
}

__static__ __void__ __set_idt__(int8_t num, uint32_t base, uint16_t select, uint8_t flags){
	
	idt_entry[num].base_low = base & 0xFFFF;
    idt_entry[num].base_high = (base >> 16) & 0xFFFF;

    idt_entry[num].select     = select;
    idt_entry[num].type = 0;
    idt_entry[num].flags   = flags;

}


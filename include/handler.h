#include "types.h"
#ifndef __HANDLER_H__
#define __HANDLER_H__

#define IRQ0 	32
#define IRQ1 	33
#define IRQ2 	34
#define IRQ3 	35
#define IRQ4 	36
#define IRQ5 	37
#define IRQ6 	38
#define IRQ7 	39
#define IRQ8 	40
#define IRQ9 	41
#define IRQ10 	42
#define IRQ11 	43
#define IRQ12 	44
#define IRQ13 	45
#define IRQ14 	46
#define IRQ15 	47

typedef struct registers
{
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t num_int, err_code;
	uint32_t eip, cs, eflags, usr_esp, ss;
} registers_t;

typedef __void__ (*__isr_t__)(registers_t);

__void__ __register_int_handler__(uint32_t, __isr_t__ );

#endif
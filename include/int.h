#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__
#include "types.h"
#include "handler.h"
#include "int.h"

#define ISR0 0
#define ISR1 1
#define ISR2 2
#define ISR3 3
#define ISR4 4
#define ISR5 5
#define ISR6 6
#define ISR7 7
#define ISR8 8
#define ISR9 9
#define ISR10 10
#define ISR11 11
#define ISR12 12
#define ISR13 13
#define ISR14 14
#define ISR15 15
#define ISR16 16
#define ISR17 17
#define ISR18 18
#define ISR19 19
#define ISR20 20
#define ISR21 21
#define ISR22 22
#define ISR23 23
#define ISR24 24
#define ISR25 25
#define ISR26 26
#define ISR27 27
#define ISR28 28
#define ISR29 29
#define ISR30 30
#define ISR31 31

__static__ __void__ isr0_callback(registers_t);
__static__ __void__ isr1_callback(registers_t);
__static__ __void__ isr2_callback(registers_t);
__static__ __void__ isr3_callback(registers_t);
__static__ __void__ isr4_callback(registers_t);
__static__ __void__ isr5_callback(registers_t);
__static__ __void__ isr6_callback(registers_t);
__static__ __void__ isr7_callback(registers_t);
__static__ __void__ isr8_callback(registers_t);
__static__ __void__ isr9_callback(registers_t);
__static__ __void__ isr10_callback(registers_t);
__static__ __void__ isr11_callback(registers_t);
__static__ __void__ isr12_callback(registers_t);
__static__ __void__ isr13_callback(registers_t);
__static__ __void__ isr14_callback(registers_t);
__static__ __void__ isr16_callback(registers_t);
__static__ __void__ isr17_callback(registers_t);
__static__ __void__ isr18_callback(registers_t);
__static__ __void__ isr19_callback(registers_t);
__static__ __void__ isr_reserved_callback(registers_t);

__void__ divid_by_zero(__void__);
__void__ nm_int(__void__);
__void__ break_point(__void__);
__void__ overflow(__void__);
__void__ bound_rang_exc(__void__);
__void__ invalid_op(__void__);
__void__ device_not_avail(__void__);
__void__ double_fault(__void__);
__void__ copro_seg(__void__);
__void__ invalid_tss(__void__);
__void__ seg_not_pre(__void__);
__void__ stack_seg_error(__void__);
__void__ general_protect(__void__);
__void__ page_fault(__void__);
__void__ fpu_error(__void__);
__void__ align_check(__void__);
__void__ machine_check(__void__);
__void__ fp_excep(__void__);
__void__ default_int(__void__);

__void__ init_int(__void__);
#endif
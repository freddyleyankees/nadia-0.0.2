extern __isr_handler__, __irq_handler__
global __gdt_up__, __idt_up__, __isr_common_int__, __irq_common_int__, __asm_irq_ign__, __asm_isr_def__


__gdt_up__:
   mov eax, [esp+4]  ; Get the pointer to the GDT, passed as a parameter.
   lgdt [eax]        ; Load the new GDT pointer

   mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
   mov ds, ax        ; Load all data segment selectors
   mov es, ax
   mov fs, ax
   mov gs, ax
   mov ss, ax
   jmp 0x08:.done   ; 0x08 is the offset to our code segment: Far jump!
.done:
   ret


__idt_up__:
   mov eax, [esp+4]  ; Get the pointer to the IDT, passed as a parameter. 
   lidt [eax]        ; Load the IDT pointer.
   ret


%macro   SAVE_REGS 0
   pusha
   mov ax, ds
   push eax
   
   mov ax,0x10
   mov ds,ax
   mov es,ax
   mov fs,ax
   mov gs,ax
%endmacro

%macro   RESTORE_REGS 0
   pop eax
   mov ds,ax
   mov es,ax
   mov fs,ax
   mov gs,ax
   popa
   add esp, 8
%endmacro

__isr_common_int__:
   SAVE_REGS
   call __isr_handler__
   RESTORE_REGS
   sti
   iret

__irq_common_int__:
   SAVE_REGS
   call __irq_handler__
   RESTORE_REGS
   sti
   iret

__asm_int_ign__:
   cli
   push byte 0
   push byte 0x70
   jmp __isr_common_int__

__asm_isr_def__:
   cli
   push byte 0
   push byte 0x71
   jmp __isr_common_int__

;routine exception

%macro ISR_HANDLER_NOERRCODE 1  
   [GLOBAL __asm_isr_%1__]
   __asm_isr_%1__:
      cli
      push byte 0
      push byte %1
      jmp __isr_common_int__
%endmacro

%macro ISR_HANDLER_ERRCODE 1
   [GLOBAL __asm_isr_%1__]
   __asm_isr_%1__:
      cli
      push byte %1
      jmp __isr_common_int__
%endmacro


%macro IRQ_HANDLER 2  
   [GLOBAL __asm_irq_%1__]
   __asm_irq_%1__:
      cli
      push byte 0
      push byte %2
      jmp __irq_common_int__
%endmacro

%macro SYS_CALL_HANDLER 1  
   [GLOBAL __sys_call__]
   __sys_call__:
      cli
      push byte 0
      push byte %1
      jmp __irq_common_int__
%endmacro

ISR_HANDLER_NOERRCODE 0
ISR_HANDLER_NOERRCODE 1
ISR_HANDLER_NOERRCODE 2
ISR_HANDLER_NOERRCODE 3
ISR_HANDLER_NOERRCODE 4
ISR_HANDLER_NOERRCODE 5
ISR_HANDLER_NOERRCODE 6
ISR_HANDLER_NOERRCODE 7
ISR_HANDLER_ERRCODE 8
ISR_HANDLER_NOERRCODE 9
ISR_HANDLER_ERRCODE 10
ISR_HANDLER_ERRCODE 11
ISR_HANDLER_ERRCODE 12
ISR_HANDLER_ERRCODE 13
ISR_HANDLER_ERRCODE 14
ISR_HANDLER_NOERRCODE 15
ISR_HANDLER_NOERRCODE 16
ISR_HANDLER_NOERRCODE 17
ISR_HANDLER_NOERRCODE 18
ISR_HANDLER_NOERRCODE 19
ISR_HANDLER_NOERRCODE 20
ISR_HANDLER_NOERRCODE 21
ISR_HANDLER_NOERRCODE 22
ISR_HANDLER_NOERRCODE 23
ISR_HANDLER_NOERRCODE 24
ISR_HANDLER_NOERRCODE 25
ISR_HANDLER_NOERRCODE 26
ISR_HANDLER_NOERRCODE 27
ISR_HANDLER_NOERRCODE 28
ISR_HANDLER_NOERRCODE 29
ISR_HANDLER_NOERRCODE 30
ISR_HANDLER_NOERRCODE 31

IRQ_HANDLER 0, 32
IRQ_HANDLER 1, 33
IRQ_HANDLER 2, 34
IRQ_HANDLER 3, 35
IRQ_HANDLER 4, 36
IRQ_HANDLER 5, 37
IRQ_HANDLER 6, 38
IRQ_HANDLER 7, 39
IRQ_HANDLER 8, 40
IRQ_HANDLER 9, 41
IRQ_HANDLER 10, 42
IRQ_HANDLER 11, 43
IRQ_HANDLER 12, 44
IRQ_HANDLER 13, 45
IRQ_HANDLER 14, 46
IRQ_HANDLER 15, 47

SYS_CALL_HANDLER 96

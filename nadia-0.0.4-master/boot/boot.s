.set __MULTIBOOT_MAGIC__, 0X1BADB002
.set __MULTIBOOT_FLAGS__, (1<<0 | 1<<1)
.set __MULTIBOOT_CHECKSUM__, -(__MULTIBOOT_MAGIC__ + __MULTIBOOT_FLAGS__)

.section .multiboot
	.long __MULTIBOOT_MAGIC__
	.long __MULTIBOOT_FLAGS__
	.long __MULTIBOOT_CHECKSUM__


.section .text
.extern main
.global start

start:
	mov kernel_stack, %esp
	push %eax
	push %ebx
	call main

stop:
	cli
	hlt
	jmp stop

.section .bss
.space 1*1024*1024
kernel_stack:

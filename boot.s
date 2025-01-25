/* Declare the constants for the multiboot header */
.set ALIGN, 	1<<0				/* align loaded modules on page boundaries */
.set MEMINFO,	1<<1				/* provide memory map */
.set FLAGS, 	ALIGN | MEMINFO		/* this is the Multiboot 'flag' field */
.set MAGIC,		0x1BADB002			/* 'magic number' lets the bootloader find the header */
.set CHECKSUM,	-(MAGIC + FLAGS)	/* checksum of above to provde that we're multiboot */

/* The stack */
.section .bss
	.align 16
stack_bottom:
	.skip 16384	/* 16 KiB */
stack_top:

/* Declcare the multiboot header that marks the program as a kernel */
.section .multiboot
	.align  4
	.long 	MAGIC
	.long	FLAGS
	.long	CHECKSUM

.section .text
	.global _start
	.type _start, @function
_start:
	mov $stack_top, %esp
	call kernel_main

	cli
1:	hlt
	jmp 1b

.size _start, . - _start

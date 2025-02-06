.section .text
	.global _getkeyboardinput
	.type _getkeyboardinput, @function
_getkeyboardinput:
	inb $0x64, %al
	testb $0b01, %al
	jz _getkeyboardinput
	inb $0x60, %al
	ret



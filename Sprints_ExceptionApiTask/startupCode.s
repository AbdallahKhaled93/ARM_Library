	.cpu cortex-m4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"startupCode.c"
	.text
	.global	au32VectorTable
	.section	.intvecs,"a"
	.align	2
	.type	au32VectorTable, %object
	.size	au32VectorTable, 64
au32VectorTable:
	.word	536903676
	.word	ResetHandler
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	SVCHandler
	.word	0
	.word	0
	.word	0
	.word	0
	.text
	.align	1
	.global	SVCHandler
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	SVCHandler, %function
SVCHandler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	.syntax unified
@ 37 "startupCode.c" 1
	MOV R0, #0x0
@ 0 "" 2
@ 38 "startupCode.c" 1
	MSR control, R0
@ 0 "" 2
	.thumb
	.syntax unified
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
	.size	SVCHandler, .-SVCHandler
	.align	1
	.global	ResetHandler
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	ResetHandler, %function
ResetHandler:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #24
	add	r7, sp, #0
	ldr	r3, .L10
	str	r3, [r7, #20]
	ldr	r3, .L10+4
	str	r3, [r7, #8]
	ldr	r3, .L10+8
	str	r3, [r7, #16]
	ldr	r3, .L10+12
	str	r3, [r7, #12]
	ldr	r3, .L10+16
	str	r3, [r7, #4]
	b	.L3
.L4:
	ldr	r3, [r7, #20]
	adds	r2, r3, #4
	str	r2, [r7, #20]
	movs	r2, #0
	str	r2, [r3]
.L3:
	ldr	r2, [r7, #20]
	ldr	r3, [r7, #8]
	cmp	r2, r3
	bcc	.L4
	b	.L5
.L6:
	ldr	r2, [r7, #16]
	adds	r3, r2, #4
	str	r3, [r7, #16]
	ldr	r3, [r7, #12]
	adds	r1, r3, #4
	str	r1, [r7, #12]
	ldr	r2, [r2]
	str	r2, [r3]
.L5:
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L6
	ldr	r3, .L10+20
	str	r3, [r7, #16]
	ldr	r3, .L10+24
	str	r3, [r7, #12]
	ldr	r3, .L10+28
	str	r3, [r7, #4]
	b	.L7
.L8:
	ldr	r2, [r7, #16]
	adds	r3, r2, #4
	str	r3, [r7, #16]
	ldr	r3, [r7, #12]
	adds	r1, r3, #4
	str	r1, [r7, #12]
	ldr	r2, [r2]
	str	r2, [r3]
.L7:
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L8
	bl	main
.L9:
	b	.L9
.L11:
	.align	2
.L10:
	.word	__bss_start__
	.word	__bss_end__
	.word	__data_load__
	.word	__data_start__
	.word	__data_end__
	.word	__fls_drv_load__
	.word	__fls_drv_start__
	.word	__fls_drv_end__
	.size	ResetHandler, .-ResetHandler
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"

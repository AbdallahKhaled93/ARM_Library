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
	.file	"app_main.c"
	.text
	.global	u8InitGLobalVar
	.data
	.type	u8InitGLobalVar, %object
	.size	u8InitGLobalVar, 1
u8InitGLobalVar:
	.byte	2
	.bss
	.align	2
u32NonInitStaticGlobalVar:
	.space	4
	.size	u32NonInitStaticGlobalVar, 4
	.global	u16ConstGlobalVar
	.section	.rodata
	.align	1
	.type	u16ConstGlobalVar, %object
	.size	u16ConstGlobalVar, 2
u16ConstGlobalVar:
	.short	3
	.section	.flashDrv,"ax",%progbits
	.align	1
	.global	executeFromRam
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	executeFromRam, %function
executeFromRam:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L4
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L3
	ldr	r3, .L4
	movs	r2, #0
	strb	r2, [r3]
.L3:
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L5:
	.align	2
.L4:
	.word	bFlashBlocked
	.size	executeFromRam, .-executeFromRam
	.global	au32SprintsArray
	.section	.sprints,"a"
	.align	2
	.type	au32SprintsArray, %object
	.size	au32SprintsArray, 20
au32SprintsArray:
	.ascii	"\000\001\002\003\004\005\006\007\010\011\012\013\014"
	.ascii	"\015\016\017\020\021\022\023"
	.global	bFlashBlocked
	.data
	.type	bFlashBlocked, %object
	.size	bFlashBlocked, 1
bFlashBlocked:
	.byte	1
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r3, #4
	strh	r3, [r7, #6]	@ movhi
	movs	r3, #3
	cmp	r3, #3
	bne	.L7
	ldr	r3, .L10
	movs	r2, #6
	str	r2, [r3]
	adds	r3, r7, #6
	mov	r0, r3
	bl	vidFunc
	b	.L8
.L7:
	ldr	r3, .L10
	movs	r2, #7
	str	r2, [r3]
.L8:
	movs	r0, #1
	bl	Mcu_EnableException
	movs	r0, #1
	bl	Mcu_DisableException
	movs	r0, #2
	bl	Mcu_EnableException
	movs	r0, #2
	bl	Mcu_DisableException
.L9:
	bl	executeFromRam
	ldr	r3, .L10+4
	movs	r2, #1
	strb	r2, [r3]
	b	.L9
.L11:
	.align	2
.L10:
	.word	u32NonInitStaticGlobalVar
	.word	bFlashBlocked
	.size	main, .-main
	.data
	.type	u8InitStaticLocVar.4159, %object
	.size	u8InitStaticLocVar.4159, 1
u8InitStaticLocVar.4159:
	.byte	5
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"

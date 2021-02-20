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
	.file	"Mcu.c"
	.text
	.align	1
	.global	Mcu_EnableException
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	Mcu_EnableException, %function
Mcu_EnableException:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	mov	r3, r0
	strb	r3, [r7, #7]
	.syntax unified
@ 14 "MCU/Mcu.c" 1
	svc #0
@ 0 "" 2
	.thumb
	.syntax unified
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L2
	.syntax unified
@ 18 "MCU/Mcu.c" 1
	CPSIE i
@ 0 "" 2
	.thumb
	.syntax unified
	b	.L3
.L2:
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	cmp	r3, #2
	bne	.L3
	.syntax unified
@ 22 "MCU/Mcu.c" 1
	CPSIE f
@ 0 "" 2
	.thumb
	.syntax unified
.L3:
	.syntax unified
@ 30 "MCU/Mcu.c" 1
	MOV R0, #0x1
@ 0 "" 2
@ 31 "MCU/Mcu.c" 1
	MSR control, R0
@ 0 "" 2
	.thumb
	.syntax unified
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
	.size	Mcu_EnableException, .-Mcu_EnableException
	.align	1
	.global	Mcu_DisableException
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	Mcu_DisableException, %function
Mcu_DisableException:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	mov	r3, r0
	strb	r3, [r7, #7]
	.syntax unified
@ 44 "MCU/Mcu.c" 1
	svc #0
@ 0 "" 2
	.thumb
	.syntax unified
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L5
	.syntax unified
@ 48 "MCU/Mcu.c" 1
	CPSID i
@ 0 "" 2
	.thumb
	.syntax unified
	b	.L6
.L5:
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	cmp	r3, #2
	bne	.L6
	.syntax unified
@ 52 "MCU/Mcu.c" 1
	CPSID f
@ 0 "" 2
	.thumb
	.syntax unified
.L6:
	.syntax unified
@ 60 "MCU/Mcu.c" 1
	MOV R0, #0x1
@ 0 "" 2
@ 61 "MCU/Mcu.c" 1
	MSR control, R0
@ 0 "" 2
	.thumb
	.syntax unified
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
	.size	Mcu_DisableException, .-Mcu_DisableException
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Interrupt control driver
 *
 *      \details  Implementation of the driver for system peripheral NVIC\SCB
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "CortexM4_Registers.h"
#include "Registers_Ops.h"
#include "IntCtrl.h"
#include "CpuDriver.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/* APINT */ 
#define INTCTRL_PRIGROUP_OFFSET      (0x8)

#define INTCTRL_PRIGROUP_XXX         (0x4)
#define INTCTRL_PRIGROUP_XXY         (0x5)
#define INTCTRL_PRIGROUP_XYY         (0x6)
#define INTCTRL_PRIGROUP_YYY         (0x7)

#define INTCTRL_REGISTER_SIZE_BITS   (32)
#define INTCTRL_REGISTER_SIZE_BYTES  (4)

/* Enable interrupt registers */
#define INTCTRL_ENx_REGISTERS_BASE_ADDR   (SYS_PERIPHERALS_BASE_ADDR + 0x100)

/* Priority groups registers */
#define INTCTRL_PRIx_REGISTERS_BASE_ADDR   (SYS_PERIPHERALS_BASE_ADDR + 0x400)
#define INTCTRL_PRIx_FIRST_USEFUL_BIT      (5)
#define INTCTRL_INT_COUNT_PER_PRIx         (4)

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCtrl_init(void)     
* \Description     : Init function for the interrupt control peripheral                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
void IntCtrl_init(void)
{

    uint8 u8LoopIndex;
    uint8 u8InterruptBitOffset, u8InterruptRegister, u8CurrentInterruptNumber;
    uint32 u32InterruptPRIxRegisterAddress;

    /* Switch to privilege mode to be able to configure exceptions */
    CpuDriver_SwitchToPrivilegeMode();

#if !defined(INTCTRL_GRP_PRIO_COUNT)
#error "INTCTRL_GRP_PRIO_COUNT is missing"
#endif

    /* Assign bits to groups and subgroups */
#if   INTCTRL_GRP_PRIO_COUNT == 8
    APINT = APINT_KEY | ((APINT & 0x0000FFFF) | INTCTRL_PRIGROUP_XXX << INTCTRL_PRIGROUP_OFFSET);
#elif INTCTRL_GRP_PRIO_COUNT == 4
    APINT = APINT_KEY | ((APINT & 0x0000FFFF) | INTCTRL_PRIGROUP_XXY << INTCTRL_PRIGROUP_OFFSET);
#elif INTCTRL_GRP_PRIO_COUNT == 2
    APINT = APINT_KEY | ((APINT & 0x0000FFFF) | INTCTRL_PRIGROUP_XYY << INTCTRL_PRIGROUP_OFFSET);
#elif INTCTRL_GRP_PRIO_COUNT == 1
    APINT = APINT_KEY | ((APINT & 0x0000FFFF) | INTCTRL_PRIGROUP_YYY << INTCTRL_PRIGROUP_OFFSET);
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

    /* Configure peripherals interrupts */
    for (u8LoopIndex = 0; u8LoopIndex < INTCTRL_ENABLED_INTERRUPTS_COUNT; u8LoopIndex++)
    {
        u8CurrentInterruptNumber = IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionNum;

        /* Enable interrupt in ENx register */
        u8InterruptBitOffset = u8CurrentInterruptNumber % INTCTRL_REGISTER_SIZE_BITS;
        u8InterruptRegister = u8CurrentInterruptNumber / INTCTRL_REGISTER_SIZE_BITS;
        SET_BIT((INTCTRL_ENx_REGISTERS_BASE_ADDR + (u8InterruptRegister * INTCTRL_REGISTER_SIZE_BYTES)), u8InterruptBitOffset);

        /* Get corresponding PRI register */
        u8InterruptBitOffset = INTCTRL_PRIx_FIRST_USEFUL_BIT + ((u8CurrentInterruptNumber % INTCTRL_INT_COUNT_PER_PRIx) * 8);
        u8InterruptRegister = u8CurrentInterruptNumber / INTCTRL_INT_COUNT_PER_PRIx;
        u32InterruptPRIxRegisterAddress = INTCTRL_PRIx_REGISTERS_BASE_ADDR + (u8InterruptRegister * INTCTRL_REGISTER_SIZE_BYTES);

        /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
        (*((uint32*)u32InterruptPRIxRegisterAddress) |= ((uint32)(IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionGrp<<u8InterruptBitOffset)));
#elif INTCTRL_GRP_PRIO_COUNT == 4
        (*((uint32*)u32InterruptPRIxRegisterAddress) |= ((uint32)(IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionGrp<<(u8InterruptBitOffset + 1))));
        (*((uint32*)u32InterruptPRIxRegisterAddress) |= ((uint32)(IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionSubGrp<<u8InterruptBitOffset)));
#elif INTCTRL_GRP_PRIO_COUNT == 2
        (*((uint32*)u32InterruptPRIxRegisterAddress) |= ((uint32)(IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionGrp<<(u8InterruptBitOffset + 2))));
        (*((uint32*)u32InterruptPRIxRegisterAddress) |= ((uint32)(IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionSubGrp<<u8InterruptBitOffset)));
#elif INTCTRL_GRP_PRIO_COUNT == 1
        (*((uint32*)u32InterruptPRIxRegisterAddress) |= ((uint32)(IntCtrl_InterruptsCfg[u8LoopIndex].u8ExceptionSubGrp<<u8InterruptBitOffset)));      
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

    }
    
    /* Configure system exceptions */
    for (u8LoopIndex = 0; u8LoopIndex < INTCTRL_ENABLED_SYS_EXCEPTIONS_COUNT; u8LoopIndex++)
    {
        u8CurrentInterruptNumber = IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionNum;

        switch (u8CurrentInterruptNumber)
        {
        case INTCTRL_MEM_MNGMNT_FAULT:

            SYSHNDCTRL.BITS.MEM = 1;

            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI1.BITS.MEM |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI1.BITS.MEM |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI1.BITS.MEM |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI1.BITS.MEM |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI1.BITS.MEM |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI1.BITS.MEM |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        
        case INTCTRL_BUS_FAULT:

            SYSHNDCTRL.BITS.BUS = 1;

            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI1.BITS.BUS |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI1.BITS.BUS |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI1.BITS.BUS |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI1.BITS.BUS |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI1.BITS.BUS |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI1.BITS.BUS |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        
        case INTCTRL_USAGE_FAULT:

            SYSHNDCTRL.BITS.USAGE = 1;

            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI1.BITS.USAGE |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI1.BITS.USAGE |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI1.BITS.USAGE |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI1.BITS.USAGE |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI1.BITS.USAGE |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI1.BITS.USAGE |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        
        case INTCTRL_SVC:

            /* TODO : check if there is an enable bit for SVC */

            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI2.BITS.SVC |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI2.BITS.SVC |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI2.BITS.SVC |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI2.BITS.SVC |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI2.BITS.SVC |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI2.BITS.SVC |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        
        case INTCTRL_DEBUG_MNTR:
            
            /* TODO : check if there is an enable bit for debug exception */

            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI3.BITS.DEBUG |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI3.BITS.DEBUG |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI3.BITS.DEBUG |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI3.BITS.DEBUG |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI3.BITS.DEBUG |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI3.BITS.DEBUG |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        
        case INTCTRL_PENDSV:
            
            /* TODO : check if there is an enable bit for PENDSV */

            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI3.BITS.PENDSV |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI3.BITS.PENDSV |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI3.BITS.PENDSV |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI3.BITS.PENDSV |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI3.BITS.PENDSV |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI3.BITS.PENDSV |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        
        case INTCTRL_SYS_TICK:

            STCTRL.BITS.INTEN = 1;
            
            /* Set priority group and sub group */
#if   INTCTRL_GRP_PRIO_COUNT == 8
            SYSPRI3.BITS.TICK |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 4
            SYSPRI3.BITS.TICK |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 1);
            SYSPRI3.BITS.TICK |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 2
            SYSPRI3.BITS.TICK |= (IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionGrp << 2);
            SYSPRI3.BITS.TICK |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#elif INTCTRL_GRP_PRIO_COUNT == 1
            SYSPRI3.BITS.TICK |= IntCtrl_ExceptionsCfg[u8LoopIndex].u8ExceptionSubGrp;
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */

            break;
        default:
            break;
        }
    }

    /* For safety, go back to user mode */
    CpuDriver_SwitchToUserMode();
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/

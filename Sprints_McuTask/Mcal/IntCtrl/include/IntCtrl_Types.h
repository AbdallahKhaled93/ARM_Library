/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  Data types definition for IntCtrl driver
 *  
 *********************************************************************************************************************/
#ifndef _INTCTRL_TYPES_H
#define _INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Enum for system exceptions and faults (programmable only)*/
typedef enum
{
    INTCTRL_MEM_MNGMNT_FAULT = 4,
    INTCTRL_BUS_FAULT,
    INTCTRL_USAGE_FAULT,
    INTCTRL_SVC = 11,
    INTCTRL_DEBUG_MNTR,
    INTCTRL_PENDSV = 14,
    INTCTRL_SYS_TICK
}IntCtrl_SysExceptionType;

/* Enum for MCU interrupts */
typedef enum
{
    INTCTRL_GPIO_PORTA = 0,
    INTCTRL_GPIO_PORTB,
    INTCTRL_GPIO_PORTC,
    INTCTRL_GPIO_PORTD,
    INTCTRL_GPIO_PORTE,
    INTCTRL_UART0,
    INTCTRL_UART1,
    INTCTRL_SSI0,
    INTCTRL_I2C0,
    INTCTRL_PWM0_FAULT,
    INTCTRL_PWM0_GEN0,
    INTCTRL_PWM0_GEN1,
    INTCTRL_PWM0_GEN2,
    INTCTRL_QEI0,
    INTCTRL_ADC0_SEQ0,
    INTCTRL_ADC0_SEQ1,
    INTCTRL_ADC0_SEQ2,
    INTCTRL_ADC0_SEQ3,
    INTCTRL_WATCHDOG_TIMERS,
    INTCTRL_TIMER_0A,
    INTCTRL_TIMER_0B,
    INTCTRL_TIMER_1A,
    INTCTRL_TIMER_1B,
    INTCTRL_TIMER_2A,
    INTCTRL_TIMER_2B,
    INTCTRL_ANALOG_COMPARATOR0,
    INTCTRL_ANALOG_COMPARATOR1,
    INTCTRL_SYSTEM_CTRL = 28,
    INTCTRL_FLASH_MEMORY_CTRL,
    INTCTRL_GPIO_PORTF,
    INTCTRL_UART2 = 33,
    INTCTRL_SSI1,
    INTCTRL_TIMER_3A,
    INTCTRL_TIMER_3B,
    INTCTRL_I2C1,
    INTCTRL_QEI1,
    INTCTRL_CAN0,
    INTCTRL_CAN1,
    INTCTRL_HIBERNATION_MODULE = 43,
    INTCTRL_USB,
    INTCTRL_PWM0_GEN3,
    INTCTRL_UDMA_SW,
    INTCTRL_UDMA_ERR,
    INTCTRL_ADC1_SEQ0,
    INTCTRL_ADC1_SEQ1,
    INTCTRL_ADC1_SEQ2,
    INTCTRL_ADC1_SEQ3,
    INTCTRL_SSI2 = 57,
    INTCTRL_SSI3,
    INTCTRL_UART3,
    INTCTRL_UART4,
    INTCTRL_UART5,
    INTCTRL_UART6,
    INTCTRL_UART7,
    INTCTRL_I2C2 = 68,
    INTCTRL_I2C3,
    INTCTRL_TIMER_4A,
    INTCTRL_TIMER_4B,
    INTCTRL_TIMER_5A = 92,
    INTCTRL_TIMER_5B,
    INTCTRL_TIMER_0A_64,
    INTCTRL_TIMER_0B_64,
    INTCTRL_TIMER_1A_64,
    INTCTRL_TIMER_1B_64,
    INTCTRL_TIMER_2A_64,
    INTCTRL_TIMER_2B_64,
    INTCTRL_TIMER_3A_64,
    INTCTRL_TIMER_3B_64,
    INTCTRL_TIMER_4A_64,
    INTCTRL_TIMER_4B_64,
    INTCTRL_TIMER_5A_64,
    INTCTRL_TIMER_5B_64,
    INTCTRL_SYS_EXCP,
    INTCTRL_PWM1_GEN0 = 134,
    INTCTRL_PWM1_GEN1,
    INTCTRL_PWM1_GEN2,
    INTCTRL_PWM1_GEN3,
    INTCTRL_PWM1_FAULT,
}IntCtrl_InterruptType;

typedef struct 
{
    IntCtrl_InterruptType u8ExceptionNum;
    uint8 u8ExceptionGrp;
    uint8 u8ExceptionSubGrp;
}IntCtrl_InterruptCfgType;

typedef struct 
{
    IntCtrl_SysExceptionType u8ExceptionNum;
    uint8 u8ExceptionGrp;
    uint8 u8ExceptionSubGrp;
}IntCtrl_ExceptionCfgType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* _INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/

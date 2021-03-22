/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Types.h
 *       Module:  Mcu
 *
 *  Description:  Header file for Mcu driver types   
 *  
 *********************************************************************************************************************/
#ifndef _MCU_TYPES_h
#define _MCU_TYPES_h

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

#define MCU_RESET_CAUSE_EXTERNAL       (0x1)
#define MCU_RESET_CAUSE_POWER_ON       (0x2)
#define MCU_RESET_CAUSE_BROWN_OUT      (0x4)
#define MCU_RESET_CAUSE_WATCHDOG0      (0x8)
#define MCU_RESET_CAUSE_SOFTWARE       (0x10)
#define MCU_RESET_CAUSE_WATCHDOG1      (0X20)
#define MCU_RESET_CAUSE_MAIN_OSC_FAIL  (0x10000)
typedef uint32 Mcu_RawResetType;


typedef enum
{
    MCU_CLOCK_SOURCE_MOSC = 0,
    MCU_CLOCK_SOURCE_PIOSC,
    MCU_CLOCK_SOURCE_PIOSC_BY_4,
    MCU_CLOCK_SOURCE_LFIOSC,
}Mcu_ClockSrcType;

typedef enum
{
    MCU_PERIPHERAL_CLOCK_WATCHDOG0 = 0,
    MCU_PERIPHERAL_CLOCK_WATCHDOG1,
    MCU_PERIPHERAL_CLOCK_TIMER0 = 32,
    MCU_PERIPHERAL_CLOCK_TIMER1,
    MCU_PERIPHERAL_CLOCK_TIMER2,
    MCU_PERIPHERAL_CLOCK_TIMER3,
    MCU_PERIPHERAL_CLOCK_TIMER4,
    MCU_PERIPHERAL_CLOCK_TIMER5,
    MCU_PERIPHERAL_CLOCK_GPIOA = 64,
    MCU_PERIPHERAL_CLOCK_GPIOB,
    MCU_PERIPHERAL_CLOCK_GPIOC,
    MCU_PERIPHERAL_CLOCK_GPIOD,
    MCU_PERIPHERAL_CLOCK_GPIOE,
    MCU_PERIPHERAL_CLOCK_GPIOF,
    MCU_PERIPHERAL_CLOCK_DMA = 96,
    MCU_PERIPHERAL_CLOCK_HIB = 160,
    MCU_PERIPHERAL_CLOCK_UART0 = 192,
    MCU_PERIPHERAL_CLOCK_UART1,
    MCU_PERIPHERAL_CLOCK_UART2,
    MCU_PERIPHERAL_CLOCK_UART3,
    MCU_PERIPHERAL_CLOCK_UART4,
    MCU_PERIPHERAL_CLOCK_UART5,
    MCU_PERIPHERAL_CLOCK_UART6,
    MCU_PERIPHERAL_CLOCK_UART7,
    MCU_PERIPHERAL_CLOCK_SSI0 = 224,
    MCU_PERIPHERAL_CLOCK_SSI1,
    MCU_PERIPHERAL_CLOCK_SSI2,
    MCU_PERIPHERAL_CLOCK_SSI3,
    MCU_PERIPHERAL_CLOCK_I2C0 = 256,
    MCU_PERIPHERAL_CLOCK_I2C1,
    MCU_PERIPHERAL_CLOCK_I2C2,
    MCU_PERIPHERAL_CLOCK_I2C3,
    MCU_PERIPHERAL_CLOCK_USB = 320,
    MCU_PERIPHERAL_CLOCK_CAN0 = 416,
    MCU_PERIPHERAL_CLOCK_CAN1,
    MCU_PERIPHERAL_CLOCK_ADC0 = 448,
    MCU_PERIPHERAL_CLOCK_ADC1,
    MCU_PERIPHERAL_CLOCK_ACMP = 480,
    MCU_PERIPHERAL_CLOCK_PWM0 = 512,
    MCU_PERIPHERAL_CLOCK_PWM1,
    MCU_PERIPHERAL_CLOCK_QEI0 = 544,
    MCU_PERIPHERAL_CLOCK_QEI1,
    MCU_PERIPHERAL_CLOCK_EEPROM = 704,
    MCU_PERIPHERAL_CLOCK_WTIMER0 = 736,
    MCU_PERIPHERAL_CLOCK_WTIMER1,
    MCU_PERIPHERAL_CLOCK_WTIMER2,
    MCU_PERIPHERAL_CLOCK_WTIMER3,
    MCU_PERIPHERAL_CLOCK_WTIMER4,
    MCU_PERIPHERAL_CLOCK_WTIMER5,
}Mcu_EnabledPeripheralClockType;

typedef struct
{
    Mcu_ClockSrcType u8ClockSource;
    bool bUsePll;
    uint32 u32FreqKHZ;

}Mcu_ConfigType;

typedef uint8 Mcu_ClockType;

#define MCU_PLL_STATUS_UNLOCKED        (0x0)
#define MCU_PLL_STATUS_LOCKED          (0x1)
typedef uint8 Mcu_PLLStatusType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* _MCU_TYPES_h */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Types.h
 *********************************************************************************************************************/

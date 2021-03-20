/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TM4C123GH6PM_Registers.h
 *       Module:  common
 *
 *  Description:  Register description file for TI microcontroller TM4C123GH6PM
 *  
 *********************************************************************************************************************/
#ifndef _TM4C123GH6PM_REGISTERS_H
#define _TM4C123GH6PM_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* system control */
#define SYSTEM_CONTROL_BASE_ADDR             (0x400FE000)


typedef struct
{
    uint32 MOSCDIS     : 1;
    uint32             : 3;
    uint32 OSCSRC      : 2;
    uint32 XTAL        : 5;
    uint32 BYPASS      : 1;
    uint32             : 1;
    uint32 PWRDN       : 1;
    uint32             : 3;
    uint32 PWMDIV      : 3;
    uint32 USEPWMDIV   : 1;
    uint32             : 1;
    uint32 USESYSDIV   : 1;
    uint32 SYSDIV      : 4;
    uint32 ACG         : 1;
    uint32             : 4;
}RCC_BF;

typedef union
{
    uint32 VALUE;
    RCC_BF BITS;
}RCC_U;

typedef struct
{
    uint32            : 4;
    uint32 OSCSRC2    : 3;
    uint32            : 4;
    uint32 BYPASS2    : 1;
    uint32            : 1;
    uint32 PWRDN2     : 1;
    uint32 USBPWRDN   : 1;
    uint32            : 7;
    uint32 SYSDIV2LSB : 1;
    uint32 SYSDIV2    : 6;
    uint32            : 1;
    uint32 DIV400     : 1;
    uint32 USERCC2    : 1;
}RCC2_BF;

typedef union
{
    uint32 VALUE;
    RCC2_BF BITS;
}RCC2_U;

typedef struct
{
    uint32 LOCK    : 1;
    uint32         : 31;
}PLLSTAT_BF;

typedef union
{
    uint32 VALUE;
    PLLSTAT_BF BITS;
}PLLSTAT_U;


#define RESC                                 (*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDR + 0x05C)))
#define RCC                                  (*((volatile RCC_U*)(SYSTEM_CONTROL_BASE_ADDR + 0x060)))
#define RCC2                                 (*((volatile RCC2_U*)(SYSTEM_CONTROL_BASE_ADDR + 0x070)))
#define PLLSTAT                              (*((volatile PLLSTAT_U*)(SYSTEM_CONTROL_BASE_ADDR + 0x168)))

/* gpio */
#define GPIODATA(portBaseAddr)               (*((volatile uint32*)(portBaseAddr)))
#define GPIODIR(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x400)))
#define GPIOIS(portBaseAddr)                 (*((volatile uint32*)(portBaseAddr + 0x404)))
#define GPIOIBE(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x408)))
#define GPIOIVE(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x40C)))
#define GPIOIM(portBaseAddr)                 (*((volatile uint32*)(portBaseAddr + 0x410)))
#define GPIORIS(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x414)))
#define GPIOMIS(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x418)))
#define GPIOICR(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x41C)))
#define GPIOAFSEL(portBaseAddr)              (*((volatile uint32*)(portBaseAddr + 0x420)))
#define GPIOR2R(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x500)))
#define GPIOR4R(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x504)))
#define GPIOR8R(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x508)))
#define GPIOODR(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x50C)))
#define GPIOPUR(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x510)))
#define GPIOPDR(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x514)))
#define GPIOSLR(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x518)))
#define GPIODEN(portBaseAddr)                (*((volatile uint32*)(portBaseAddr + 0x51C)))
#define GPIOLOCK(portBaseAddr)               (*((volatile uint32*)(portBaseAddr + 0x520)))
#define GPIOCR(portBaseAddr)                 (*((volatile uint32*)(portBaseAddr + 0x524)))
#define GPIOAMSEL(portBaseAddr)              (*((volatile uint32*)(portBaseAddr + 0x528)))
#define GPIOPCTL(portBaseAddr)               (*((volatile uint32*)(portBaseAddr + 0x52C)))
#define GPIOADCCTL(portBaseAddr)             (*((volatile uint32*)(portBaseAddr + 0x530)))
#define GPIODMACTL(portBaseAddr)             (*((volatile uint32*)(portBaseAddr + 0x534)))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* _TM4C123GH6PM_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: TM4C123GH6PM_Registers.h
 *********************************************************************************************************************/

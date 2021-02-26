/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CortexM4_Registers.h
 *       Module:  common
 *
 *  Description:  Register description file for cortex m4  
 *  
 *********************************************************************************************************************/
#ifndef _CORTEXM4_REGISTERS_H
#define _CORTEXM4_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SYS_PERIPHERALS_BASE_ADDR       (0xE000E000)


/* SCB Registers */

typedef struct
{
    uint32        : 5;
    uint32 MEM    : 3;
    uint32        : 5;
    uint32 BUS    : 3;
    uint32        : 5;
    uint32 USAGE  : 3;
    uint32        : 8;
}SYSPRI1_BF;

typedef union
{
    uint32 VALUE;
    SYSPRI1_BF BITS;
}SYSPRI1_U;

typedef struct
{
    uint32        : 29;
    uint32 SVC    : 3;
}SYSPRI2_BF;

typedef union
{
    uint32 VALUE;
    SYSPRI2_BF BITS;
}SYSPRI2_U;

typedef struct
{
    uint32        : 5;
    uint32 DEBUG  : 3;
    uint32        : 13;
    uint32 PENDSV : 3;
    uint32        : 5;
    uint32 TICK   : 3;
}SYSPRI3_BF;

typedef union
{
    uint32 VALUE;
    SYSPRI3_BF BITS;
}SYSPRI3_U;

typedef struct
{
    uint32 MEMA   : 1;
    uint32 BUSA   : 1;
    uint32        : 1;
    uint32 USGA   : 1;
    uint32        : 3;
    uint32 SVCA   : 1;
    uint32 MON    : 1;
    uint32        : 1;
    uint32 PNDSV  : 1;
    uint32 TICK   : 1;
    uint32 USAGEP : 1;
    uint32 MEMP   : 1;
    uint32 BUSP   : 1;
    uint32 SVC    : 1;
    uint32 MEM    : 1;
    uint32 BUS    : 1;
    uint32 USAGE  : 1;
    uint32        : 13;
}SYSHNDCTRL_BF;

typedef union
{
    uint32 VALUE;
    SYSHNDCTRL_BF BITS;
}SYSHNDCTRL_U;


#define APINT                             (*((volatile uint32*)(SYS_PERIPHERALS_BASE_ADDR + 0xD0C)))
#define SYSPRI1                           (*((volatile SYSPRI1_U*)(SYS_PERIPHERALS_BASE_ADDR + 0xD18)))
#define SYSPRI2                           (*((volatile SYSPRI2_U*)(SYS_PERIPHERALS_BASE_ADDR + 0xD1C)))
#define SYSPRI3                           (*((volatile SYSPRI3_U*)(SYS_PERIPHERALS_BASE_ADDR + 0xD20)))
#define SYSHNDCTRL                        (*((volatile SYSHNDCTRL_U*)(SYS_PERIPHERALS_BASE_ADDR + 0xD24)))



/* SysTick registers */
typedef struct
{
    uint32 ENABLE : 1;
    uint32 INTEN  : 1;
    uint32 CLKSRC : 1;
    uint32        : 13;
    uint32 COUNT  : 1;
    uint32        : 15;
}STCTRL_BF;

typedef union
{
    uint32 VALUE;
    STCTRL_BF BITS;
}STCTRL_U;


#define STCTRL                           (*((volatile STCTRL_U*)(SYS_PERIPHERALS_BASE_ADDR + 0x010)))

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

 
#endif  /* _CORTEXM4_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: CortexM4_Registers.h
 *********************************************************************************************************************/

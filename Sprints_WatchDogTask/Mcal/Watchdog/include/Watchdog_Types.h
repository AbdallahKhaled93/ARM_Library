/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Watchdog_Types.h
 *       Module:  Watchdog
 *
 *  Description:  Header file for Watchdog driver types   
 *  
 *********************************************************************************************************************/
#ifndef _WATCHDOG_TYPES_H
#define _WATCHDOG_TYPES_H

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

typedef enum
{
    WATCHDOG_INTERRUPT_STANDARD,
    WATCHDOG_INTERRUPT_NMI
}Wdg_InterruptType;

typedef struct 
{
    void (*ptrfuncWatchdogNotification)(void);
    Wdg_InterruptType u8InterruptType;
    uint16 u16InitialTimeout;
    uint16 u16MaxTimeout;
}Wdg_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* _WATCHDOG_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Watchdog_Types.h
 *********************************************************************************************************************/

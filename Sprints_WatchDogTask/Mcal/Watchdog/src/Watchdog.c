/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Watchdog.c
 *        \brief  Digital IO driver
 *
 *      \details  Implemenation of the Watchdog peripheral for TI microcontroller TM4C123GH6PM
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Registers_Ops.h"
#include "TM4C123GH6PM_Registers.h"
#include "Watchdog.h"
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define WATCHDOG_BASE_ADDR_WDG1     0x40001000


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
* \Syntax          : void Wdg_Init(void)    
* \Description     : This function intialize the watchdog module                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void Wdg_Init(void)
{
    float fTickDuration;
    uint32 u32CounterLoadValue;

    fTickDuration = Mcu_getTickDuration();

    /* set WDGLOAD, the configured value is ms */
    u32CounterLoadValue = (uint32)((float)Wdg_Config.u16InitialTimeout / fTickDuration);

    WDTLOAD(WATCHDOG_BASE_ADDR_WDG1) = u32CounterLoadValue;
    /* wait for watchdog 1 to sync */
    while(WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.WRC != 1);

    /* always enable watchdog reset */
    WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.RESEN = STD_ON;
    /* wait for watchdog 1 to sync */
    while(WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.WRC != 1);

    /* set interrupt type */
    WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.INTTYPE = Wdg_Config.u8InterruptType;
    /* wait for watchdog 1 to sync */
    while(WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.WRC != 1);

    /* enable watchdog interrupt */
    WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.INTEN = STD_ON;
    /* wait for watchdog 1 to sync */
    while(WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.WRC != 1);
}

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition ( uint16 timeout )    
* \Description     : This function refreshes the watchdog by setting the WDTLOAD register                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : timeout the new timeout to loaded in the WDTLOAD                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void Wdg_SetTriggerCondition (uint16 timeout)
{
    float fTickDuration;
    uint32 u32CounterLoadValue;

    fTickDuration = Mcu_getTickDuration();

    /* Check if the new value is not greater than the max */
    if(timeout <= Wdg_Config.u16MaxTimeout)
    {
        u32CounterLoadValue = (uint32)((float)timeout / fTickDuration);
    }
    /* Use init value */
    else
    {
        u32CounterLoadValue = (uint32)((float)Wdg_Config.u16InitialTimeout / fTickDuration);
    }

    WDTLOAD(WATCHDOG_BASE_ADDR_WDG1) = u32CounterLoadValue;
    /* wait for watchdog 1 to sync */
    while(WDTCTL(WATCHDOG_BASE_ADDR_WDG1).BITS.WRC != 1);
}

/******************************************************************************
* \Syntax          :  
* \Description     : Interrupt service routine for watchdog 1                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void ISR_WDT1(void)
{
    Wdg_Config.ptrfuncWatchdogNotification();
}

/**********************************************************************************************************************
 *  END OF FILE: Watchdog.c
 *********************************************************************************************************************/

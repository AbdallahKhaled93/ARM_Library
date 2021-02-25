/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  CpuDriver.c
 *        \brief  Cpu abstraction
 *
 *      \details  Implementation of the cpu driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "CpuDriver.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/* Keeps track of how many nested critical section are entered */
static uint8 u8CriticalSectionCounter = 0;

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
* \Syntax          : void CpuDriver_EnableGlobalInterrupt(void)     
* \Description     : Enable exception whether it is programmable or fault exceptions                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                    
*******************************************************************************/
void CpuDriver_EnableGlobalInterrupt(void)
{

    /* Trigger exception to go to handler mode in order to go to privilege mode */
    __asm("svc #0");
    __asm("CPSIE i");
    __asm("CPSIE f");

    /* go to user mode */
    __asm("MOV R0, #0x1");
    __asm("MSR control, R0");
}

/******************************************************************************
* \Syntax          : void CpuDriver_DisableGlobalInterrupt(void)     
* \Description     : Disable all exceptions except NMI
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                    
*******************************************************************************/
void CpuDriver_DisableGlobalInterrupt(void)
{

    /* Trigger exception to go to handler mode in order to go to privilege mode */
    __asm("svc #0");
    __asm("CPSID i");
    __asm("CPSID f");

    /* go to user mode */
    __asm("MOV R0, #0x1");
    __asm("MSR control, R0");
}

/******************************************************************************
* \Syntax          : void CpuDriver_StartCriticalSection(void)     
* \Description     : Called before critical section entry to disable NMI
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                    
*******************************************************************************/
void CpuDriver_StartCriticalSection(void)
{
    CpuDriver_DisableGlobalInterrupt();
    u8CriticalSectionCounter++;
}


/******************************************************************************
* \Syntax          : void CpuDriver_StopCriticalSection(void)     
* \Description     : Called at the exit of the critical section to enable exceptions
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                    
*******************************************************************************/
void CpuDriver_StopCriticalSection(void)
{
    u8CriticalSectionCounter--;

    /* Ensure that this is the last exit critical section */
    if(0 == u8CriticalSectionCounter)
    {
        CpuDriver_EnableGlobalInterrupt();
    }
}
/**********************************************************************************************************************
 *  END OF FILE: CpuDriver.c
 *********************************************************************************************************************/

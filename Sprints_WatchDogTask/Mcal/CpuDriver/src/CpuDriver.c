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
    asm(" CPSIE i");

    /* go to user mode */
    CpuDriver_SwitchToUserMode();
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
    asm(" svc #0");
    asm(" CPSID i");

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

/******************************************************************************
* \Syntax          : void CpuDriver_SwitchToPrivilegeMode(void)
* \Description     : Triggers SVC to go to privilege mode
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                    
*******************************************************************************/
void CpuDriver_SwitchToPrivilegeMode(void)
{
    /* Trigger exception to go to handler mode in order to go to privilege mode */
    asm(" svc #0");
}

/******************************************************************************
* \Syntax          : void CpuDriver_SwitchToUserMode(void)
* \Description     : switch back to user mode (unprivileged)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/
void CpuDriver_SwitchToUserMode(void)
{
    asm(" PUSH {R5}");
    // Go to user mode
    asm(" MOV R5, #0x1");
    asm(" MSR control, R5");

    asm(" POP {R5}");
}

/******************************************************************************
* \Syntax          : void CpuDriver_SVCHandler(void)
* \Description     : System handler for SVC exception
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/
void CpuDriver_SVCHandler(void)
{
    asm(" PUSH {R5}");
    // Go to privilege mode
    asm(" MOV R5, #0x0");
    asm(" MSR control, R5");

    asm(" POP {R5}");
}


/**********************************************************************************************************************
 *  END OF FILE: CpuDriver.c
 *********************************************************************************************************************/

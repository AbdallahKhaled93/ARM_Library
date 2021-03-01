/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
 *        \brief  Mcu driver
 *
 *      \details  Implemenation of the MCU peripheral for TivaC
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "TM4C123GH6PM_Registers.h"
#include "CortexM4_Registers.h"
#include "Mcu.h"
#include "CpuDriver.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define MCU_PERFORM_SOFT_SYSTEM_RESET_VAL           (0x4)

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static Mcu_RawResetType u32RawResetCause;
static Mcu_ConfigType   *pstrMcuConfig = NULL;

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
* \Syntax          : void Mcu_Init(const Mcu_ConfigType* ConfigPtr)      
* \Description     : This function populates the config pointer
*                    and reads the reset cause register and save it for later          
*                    and the reset cause register                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
{
    /* Check if config pointer is not null and then asign it to local config pointer */
    if (ConfigPtr != NULL)
    {
        pstrMcuConfig = ConfigPtr;
    }

    /* Read the reset cause and reset the RESC register */
    u32RawResetCause = RESC;
    RESC = 0x0;
    
}


/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)       
* \Description     : This function performs a soft system reset                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void Mcu_PerformReset(void)
{
    /* Switch to privilege mode to be able to perform a reset */
    CpuDriver_SwitchToPrivilegeMode();
    APINT = APINT_KEY | ((APINT & 0x0000FFFF) |  MCU_PERFORM_SOFT_SYSTEM_RESET_VAL);

    /* Stuck the code in an infinite loop to stop execution and give time to the reset to happen*/
    while(1);
}

/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)    
* \Description     : This function returns the cause of the last reset
*                    Precaution :  this function clears the reset cause register after reading it. 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType                                
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
    return u32RawResetCause;
}

/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/

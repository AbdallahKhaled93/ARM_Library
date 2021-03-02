/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
 *        \brief  Mcu driver
 *
 *      \details  Implemenation of the MCU peripheral for TI microcontroller TM4C123GH6PM
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "TM4C123GH6PM_Registers.h"
#include "CortexM4_Registers.h"
#include "Registers_Ops.h"
#include "Mcu.h"
#include "CpuDriver.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define MCU_PERFORM_SOFT_SYSTEM_RESET_VAL           (0x4)
#define MCU_PLL_CLOCK_AFTER_PREDIV                  (200)     
#define MCU_CLOCK_SOURCE_PIOSC_FREQ_MHZ             (16)
#define MCU_AVAIL_CRYSTAL_FREQS                     (27)
#define MCU_CRYSTAL_DEFAULT_XTAL_VALUE              (0x15)
#define MCU_RCGCx_BASE_ADDR                         (SYSTEM_CONTROL_BASE_ADDR + 0x600)
#define MCU_RCGCx_REGISTER_SIZE_BITS                (32)    
#define MCU_RCGCx_REGISTER_SIZE_BYTES               (4)  

#define MCU_KHZ_TO_MHZ(Freq)                        (Freq / 1000)  

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static Mcu_RawResetType u32RawResetCause;
static Mcu_ConfigType   *pstrMcuConfig = NULL;

/* Values are truncated because only single point precision is supported */
static float crystalFreqMapping[MCU_AVAIL_CRYSTAL_FREQS] = {
    0,
    0,
    0,
    0,
    0,
    0,
    4.0,
    4.1,
    4.9,
    5.0,
    5.1,
    6.0,
    6.1,
    7.4,
    8.0,
    8.2,
    10.0,
    12.0,
    12.3,
    13.6,
    14.3,
    16.0,
    16.4,
    18.0,
    20.0,
    24.0,
    25.0
};

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* This function enable all clock gates for configured peripherals  */
static void enablePeripherals(void);
/* This function configures PLL, SYSDIV and clock source */
static void configureSystemClock(Mcu_ClockType u8ClockSetting);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

static void enablePeripherals(void)
{
    uint16 u16LoopIndex;
    uint8 u8CurrentRCGCx;
    uint8 u8Offset;

    for (u16LoopIndex = 0; u16LoopIndex < MCU_ENABLED_PERIPHERALS_CONFIG_ARRAY_SIZE; u16LoopIndex++)
    {
        u8Offset = Mcu_EnabledPeripheralsConfig[u16LoopIndex] % MCU_RCGCx_REGISTER_SIZE_BITS;
        u8CurrentRCGCx = Mcu_EnabledPeripheralsConfig[u16LoopIndex] / MCU_RCGCx_REGISTER_SIZE_BITS;
        SET_BIT((MCU_RCGCx_BASE_ADDR + (u8CurrentRCGCx * MCU_RCGCx_REGISTER_SIZE_BYTES)), u8Offset);
    }
    
}

static void configureSystemClock(Mcu_ClockType u8ClockSetting)
{
    uint16 u16OscilatorSrcFreq = MCU_KHZ_TO_MHZ(pstrMcuConfig[u8ClockSetting].u32FreqKHZ);

    /********** Write to RCC register first **********/

    /* Configure PLL & divisors */
    if (TRUE == pstrMcuConfig[u8ClockSetting].bUsePll)
    {
        /* Write zero the power down bit to enter normal operation mode */
        RCC.BITS.PWRDN = 0;
        /* SYSDIV is mandatory in case of PLL, so write 1 to USESYSDIV bit to ensure normal operation */
        RCC.BITS.USESYSDIV = 1;
        /* Configure SYSDIV */
        RCC.BITS.SYSDIV = (MCU_PLL_CLOCK_AFTER_PREDIV / MCU_KHZ_TO_MHZ(pstrMcuConfig[u8ClockSetting].u32FreqKHZ)) - 1;
    }
    /* PLL is not used */
    else
    {
        switch (pstrMcuConfig[u8ClockSetting].u8ClockSource)
        {
        case MCU_CLOCK_SOURCE_PIOSC:
            u16OscilatorSrcFreq = MCU_CLOCK_SOURCE_PIOSC_FREQ_MHZ;
            break;
        case MCU_CLOCK_SOURCE_PIOSC_BY_4:
            u16OscilatorSrcFreq = MCU_CLOCK_SOURCE_PIOSC_FREQ_MHZ / 4;
            break;
        case MCU_CLOCK_SOURCE_MOSC:
            u16OscilatorSrcFreq = crystalFreqMapping[MCU_INPUT_CRYSTAL_FREQ_MHZ];
            RCC.BITS.XTAL = MCU_INPUT_CRYSTAL_FREQ_MHZ;
            break;
        default:
            break;
        }

        RCC.BITS.SYSDIV = ((float)u16OscilatorSrcFreq / (float)MCU_KHZ_TO_MHZ(pstrMcuConfig[u8ClockSetting].u32FreqKHZ)) - 1;
    }

    /* if main oscilator is chosen, enable it*/
    if (MCU_CLOCK_SOURCE_MOSC == pstrMcuConfig[u8ClockSetting].u8ClockSource)
    {
        /* enable by writing zero */
        RCC.BITS.MOSCDIS = 0;
    }

    /* set oscillator source */
    RCC.BITS.OSCSRC = pstrMcuConfig[u8ClockSetting].u8ClockSource;
}

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
* \Parameters (in) : Mcu_ConfigType*                     
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
* \Syntax          : Std_ReturnType Mcu_InitClock(Mcu_ClockType u8ClockSetting)       
* \Description     : Initialize the clock according to the selected config                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType u8ClockSetting)
{
    Std_ReturnType retVal;

    /* Pointer is not initialized */
    if(pstrMcuConfig == NULL)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* Invalid index */
        if(u8ClockSetting >= MCU_CLK_CONFIG_ARRAY_SIZE)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            enablePeripherals();
            configureSystemClock(u8ClockSetting);
            retVal = E_OK;
        }
    }

    return retVal;
}

/******************************************************************************
* \Syntax          : Mcu_PLLStatusType Mcu_GetPLLStatus(void)       
* \Description     : this function enables PLL bypass in order to feed the system                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PLLStatusType  MCU_PLL_STATUS_UNLOCKED
*                                       MCU_PLL_STATUS_LOCKED                                  
*******************************************************************************/
Mcu_PLLStatusType Mcu_GetPLLStatus(void)
{
    return (Mcu_PLLStatusType)PLLSTAT.BITS.LOCK;
}

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePLLClock(void)       
* \Description     : this function clears PLL bypass in order to feed the system using PLL                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Mcu_DistributePLLClock(void)
{
    Std_ReturnType retVal;

    /* Check if PLL is locked */
    if(MCU_PLL_STATUS_LOCKED == PLLSTAT.BITS.LOCK)
    {
        /* End PLL bypassing */
        RCC.BITS.BYPASS = 0;
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    
    return retVal;
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

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu_Lcfg.c
 *        \brief  Mcu driver configuration
 *
 *      \details  Link time configuration for Mcu driver of TI microcontroller TM4C123GH6PM
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* Enabled clock for peripherals */
const Mcu_EnabledPeripheralClockType Mcu_EnabledPeripheralsConfig[MCU_ENABLED_PERIPHERALS_CONFIG_ARRAY_SIZE] = 
{
    MCU_PERIPHERAL_CLOCK_I2C0,
    MCU_PERIPHERAL_CLOCK_WTIMER5,
    MCU_PERIPHERAL_CLOCK_GPIOD,
    MCU_PERIPHERAL_CLOCK_UART1,
    MCU_PERIPHERAL_CLOCK_TIMER0
};


/* For the clock source field, please use the value in the Mcu_ClockSrcType */
const Mcu_ConfigType Mcu_ClockConfig[MCU_CLK_CONFIG_ARRAY_SIZE] = 
{
    /* clock source, Pll used, frequency in KHZ */
    {MCU_CLOCK_SOURCE_MOSC, TRUE, 25000},
    {MCU_CLOCK_SOURCE_PIOSC, FALSE, 16000}
};

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Mcu_Lcfg.c
 *********************************************************************************************************************/

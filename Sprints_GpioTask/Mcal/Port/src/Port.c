/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port driver
 *
 *      \details  Implemenation of the Port peripheral for TI microcontroller TM4C123GH6PM
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Registers_Ops.h"
#include "TM4C123GH6PM_Registers.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define GET_PORT_BASE_ADDR(port)             (PORT_BASE_ADDRESS[port])

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static const uint32 PORT_BASE_ADDRESS[] = {
    0x40004000,
    0x40005000,
    0x40006000,
    0x40007000,
    0x40024000,
    0x40025000
};

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
* \Syntax          : void Port_Init (const Port_ConfigType* ConfigPtr)       
* \Description     : This function intialize the GPIO module                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr array of pin configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void Port_Init (const Port_ConfigType* ConfigPtr)
{
    uint8 u8PortNumber;
    uint8 u8PinPosition;
    uint8 u8LoopIndex;

    for(u8LoopIndex = 0; u8LoopIndex < PORT_PIN_CFG_SIZE; u8LoopIndex++)
    {
        u8PortNumber = ConfigPtr[u8LoopIndex].pin / 8;
        u8PinPosition = ConfigPtr[u8LoopIndex].pin % 8;

        /* Configure pin direction */
        if(PORT_DIR_OUTPUT == ConfigPtr[u8LoopIndex].pinDirection)
        {
            SET_BIT(GPIODIR(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
        }
        else if(PORT_DIR_INPUT == ConfigPtr[u8LoopIndex].pinDirection)
        {
            CLR_BIT(GPIODIR(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
        }

        /* Configure port mode */
        if(PORT_PIN_MODE_DIO != ConfigPtr[u8LoopIndex].pinMode)
        {
            SET_BIT(GPIOAFSEL(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            GPIOPCTL(GET_PORT_BASE_ADDR(u8PortNumber)) =  GPIOPCTL(GET_PORT_BASE_ADDR(u8PortNumber)) | 
                                                                (ConfigPtr[u8LoopIndex].pinMode << (4 * u8PinPosition));
        }
        else
        {
            CLR_BIT(GPIOAFSEL(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
        }

        /* Set current */
        switch (ConfigPtr[u8LoopIndex].pinCurrent)
        {
        case PORT_PIN_2mA:
            SET_BIT(GPIOR2R(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            break;
        case PORT_PIN_4mA:
            SET_BIT(GPIOR4R(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            break;
        case PORT_PIN_8mA:
            SET_BIT(GPIOR8R(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            break;
        
        default:
            break;
        }

        /* Set attach mode */
        switch (ConfigPtr[u8LoopIndex].pinAttach)
        {
        case PORT_ATTACH_PULLUP:
            SET_BIT(GPIOPUR(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            break;
        case PORT_ATTACH_PULLDOWN:
            SET_BIT(GPIOPDR(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            break;
        case PORT_ATTACH_OPENDRAIN:
            SET_BIT(GPIOODR(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);
            break;
        
        default:
            break;
        }

        /* Enable GPIO digital I/O */
        SET_BIT(GPIODEN(GET_PORT_BASE_ADDR(u8PortNumber)) , u8PinPosition);

    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/

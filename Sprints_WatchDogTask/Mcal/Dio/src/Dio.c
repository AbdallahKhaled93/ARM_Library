/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital IO driver
 *
 *      \details  Implemenation of the Dio peripheral for TI microcontroller TM4C123GH6PM
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Registers_Ops.h"
#include "TM4C123GH6PM_Registers.h"
#include "Dio.h"

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
* \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)       
* \Description     : Read a DIO pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   the id of the pin to be read                    
* \Parameters (out):                                                       
* \Return value:   : Dio_LevelType   DIO_LEVEL_LOW
*                                    DIO_LEVEL_HIGH                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    uint8 u8AddressLine;
    uint8 u8PinPosition;
    uint8 u8PortNumber;
    uint32 u32RawPinLevel;

    u8PortNumber = ChannelId / 8;
    u8PinPosition = ChannelId % 8;
    /* calculate the corresponding address line to the pin*/
    u8AddressLine = (1 << u8PinPosition) << 2;

    /* Read port through the mask */
    u32RawPinLevel = GPIODATA(GET_PORT_BASE_ADDR(u8PortNumber), u8AddressLine);

    return ((Dio_LevelType)(u32RawPinLevel >> u8PinPosition));
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)     
* \Description     : Writes a dio pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   the id of the pin to be written 
* \Parameters (in) : Level   the level to be written to this pin                   
* \Parameters (out):                                                       
* \Return value:   : none                                 
*******************************************************************************/
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 u8AddressLine;
    uint8 u8PinPosition;
    uint8 u8PortNumber;

    u8PortNumber = ChannelId / 8;
    u8PinPosition = ChannelId % 8;
    /* calculate the corresponding address line to the pin*/
    u8AddressLine = (1 << u8PinPosition) << 2;    

    /* write value through the mask */
    GPIODATA(GET_PORT_BASE_ADDR(u8PortNumber), u8AddressLine) = Level << u8PinPosition;
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId) 
* \Description     : Read a whole port                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId   the id of the port to be written              
* \Parameters (out):                                                       
* \Return value:   : Dio_PortLevelType                                 
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    /* Here the whole port is read, so the last address line is read to return tha value of all pins */
    return GPIODATA(GET_PORT_BASE_ADDR(PortId), 0x3FC);
}

/******************************************************************************
* \Syntax          : void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)   
* \Description     : Writes a whole port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId   the id of the port to be written 
* \Parameters (in) : Level   the level to be written to this port                   
* \Parameters (out):                                                       
* \Return value:   : none                                 
*******************************************************************************/
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    /* Here the whole port is written, so the last address line is used to pass all pin values */
    GPIODATA(GET_PORT_BASE_ADDR(PortId), 0x3FC) = Level;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)  
* \Description     : flips a value of a pint                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   the id of the port to be flipped                
* \Parameters (out):                                                       
* \Return value:   : none                                 
*******************************************************************************/
void Dio_FlipChannel (Dio_ChannelType ChannelId)
{
    uint8 u8AddressLine;
    uint8 u8PinPosition;
    uint8 u8PortNumber;

    u8PortNumber = ChannelId / 8;
    u8PinPosition = ChannelId % 8;
    /* calculate the corresponding address line to the pin*/
    u8AddressLine = (1 << u8PinPosition) << 2;

    /* flip the value value through the mask */
    FLIP_BIT_REG(GPIODATA(GET_PORT_BASE_ADDR(u8PortNumber), u8AddressLine), u8PinPosition);
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

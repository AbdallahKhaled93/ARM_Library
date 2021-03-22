/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  Dio
 *
 *  Description:  Header file for Dio driver types   
 *  
 *********************************************************************************************************************/
#ifndef _DIO_TYPES_H
#define _DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

typedef enum
{
    DIO_PA0 = 0,
    DIO_PA1,
    DIO_PA2,
    DIO_PA3,
    DIO_PA4,
    DIO_PA5,
    DIO_PA6,
    DIO_PA7,

    DIO_PB0 = 8,
    DIO_PB1,
    DIO_PB2,
    DIO_PB3,
    DIO_PB4,
    DIO_PB5,
    DIO_PB6,
    DIO_PB7,

    DIO_PC0 = 16,
    DIO_PC1,
    DIO_PC2,
    DIO_PC3,
    DIO_PC4,
    DIO_PC5,
    DIO_PC6,
    DIO_PC7,

    DIO_PD0 = 24,
    DIO_PD1,
    DIO_PD2,
    DIO_PD3,
    DIO_PD4,
    DIO_PD5,
    DIO_PD6,
    DIO_PD7,

    DIO_PE0 = 32,
    DIO_PE1,
    DIO_PE2,
    DIO_PE3,
    DIO_PE4,
    DIO_PE5,

    DIO_PF0 = 40,
    DIO_PF1,
    DIO_PF2,
    DIO_PF3,
    DIO_PF4,

}Dio_ChannelType;

typedef enum
{
    DIO_PORT_A = 0,
    DIO_PORT_B,
    DIO_PORT_C,
    DIO_PORT_D,
    DIO_PORT_E,
    DIO_PORT_F,
}Dio_PortType;

typedef enum
{
    DIO_LEVEL_LOW = 0,
    DIO_LEVEL_HIGH,
}Dio_LevelType;

typedef uint8 Dio_PortLevelType;

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

 
#endif  /* _DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  Port
 *
 *  Description:  Header file for Port driver types   
 *  
 *********************************************************************************************************************/
#ifndef _PORT_TYPES_H
#define _PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


typedef enum
{
    PORT_PA0 = 0,
    PORT_PA1,
    PORT_PA2,
    PORT_PA3,
    PORT_PA4,
    PORT_PA5,
    PORT_PA6,
    PORT_PA7,

    PORT_PB0 = 8,
    PORT_PB1,
    PORT_PB2,
    PORT_PB3,
    PORT_PB4,
    PORT_PB5,
    PORT_PB6,
    PORT_PB7,

    PORT_PC0 = 16,
    PORT_PC1,
    PORT_PC2,
    PORT_PC3,
    PORT_PC4,
    PORT_PC5,
    PORT_PC6,
    PORT_PC7,

    PORT_PD0 = 24,
    PORT_PD1,
    PORT_PD2,
    PORT_PD3,
    PORT_PD4,
    PORT_PD5,
    PORT_PD6,
    PORT_PD7,

    PORT_PE0 = 32,
    PORT_PE1,
    PORT_PE2,
    PORT_PE3,
    PORT_PE4,
    PORT_PE5,

    PORT_PF0 = 40,
    PORT_PF1,
    PORT_PF2,
    PORT_PF3,
    PORT_PF4,

}Port_PinType;



#define PORT_PIN_MODE_DIO              (0)

#define PORT_PIN_MODE_PA0_U0RX         (1)
#define PORT_PIN_MODE_PA0_CAN1RX       (8)

#define PORT_PIN_MODE_PA1_U0TX         (1)
#define PORT_PIN_MODE_PA1_CAN1TX       (8)

#define PORT_PIN_MODE_PA2_SSI0CLK      (2)
#define PORT_PIN_MODE_PA3_SSI0FSS      (2)
#define PORT_PIN_MODE_PA4_SSI0RX       (2)
#define PORT_PIN_MODE_PA5_SSI0TX       (2)

#define PORT_PIN_MODE_PA6_I2C1SCL      (3)
#define PORT_PIN_MODE_PA6_M1PWM2       (5)

#define PORT_PIN_MODE_PA7_I2C1SDA      (3)
#define PORT_PIN_MODE_PA7_M1PWM3       (5)

#define PORT_PIN_MODE_PB0_U1RX         (1)
#define PORT_PIN_MODE_PB0_T2CCP0       (7)

#define PORT_PIN_MODE_PB1_U1TX         (1)
#define PORT_PIN_MODE_PB1_T2CCP1       (7)

#define PORT_PIN_MODE_PB2_I2C0SCL      (3)
#define PORT_PIN_MODE_PB2_T3CCP0       (7)

#define PORT_PIN_MODE_PB3_I2C0SDA      (3)
#define PORT_PIN_MODE_PB3_T3CCP1       (7)

#define PORT_PIN_MODE_PB4_SSI2CLK      (2)
#define PORT_PIN_MODE_PB4_M0PWM2       (4)
#define PORT_PIN_MODE_PB4_T1CCP0       (7)
#define PORT_PIN_MODE_PB4_CAN0RX       (8)

#define PORT_PIN_MODE_PB5_SSI2FSS      (2)
#define PORT_PIN_MODE_PB5_M0PWM3       (4)
#define PORT_PIN_MODE_PB5_T1CCP1       (7)
#define PORT_PIN_MODE_PB5_CAN0TX       (8)

#define PORT_PIN_MODE_PB6_SSI2RX       (2)
#define PORT_PIN_MODE_PB6_M0PWM0       (4)
#define PORT_PIN_MODE_PB6_T0CCP0       (7)

#define PORT_PIN_MODE_PB7_SSI2TX       (2)
#define PORT_PIN_MODE_PB7_M0PWM1       (4)
#define PORT_PIN_MODE_PB7_T0CCP1       (7)

#define PORT_PIN_MODE_PC0_TCK_SWCLK    (1)
#define PORT_PIN_MODE_PC0_T4CCP0       (7)

#define PORT_PIN_MODE_PC1_TCK_SWDIO    (1)
#define PORT_PIN_MODE_PC1_T4CCP1       (7)

#define PORT_PIN_MODE_PC2_TDI          (1)
#define PORT_PIN_MODE_PC2_T5CCP0       (7)

#define PORT_PIN_MODE_PC3_TDO_SWO      (1)
#define PORT_PIN_MODE_PC3_T5CCP1       (7)

#define PORT_PIN_MODE_PC4_U4RX         (1)
#define PORT_PIN_MODE_PC4_U1RX         (2)
#define PORT_PIN_MODE_PC4_M0PWM6       (4)
#define PORT_PIN_MODE_PC4_IDX1         (6)
#define PORT_PIN_MODE_PC4_WT0CCP0      (7)
#define PORT_PIN_MODE_PC4_U1RTS        (8)

#define PORT_PIN_MODE_PC5_U4TX         (1)
#define PORT_PIN_MODE_PC5_U1TX         (2)
#define PORT_PIN_MODE_PC5_M0PWM7       (4)
#define PORT_PIN_MODE_PC5_PHA1         (6)
#define PORT_PIN_MODE_PC5_WT0CCP1      (7)
#define PORT_PIN_MODE_PC5_U1CTS        (8)

#define PORT_PIN_MODE_PC6_U3RX         (1)
#define PORT_PIN_MODE_PC6_PHB1         (6)
#define PORT_PIN_MODE_PC6_WT1CCP0      (7)
#define PORT_PIN_MODE_PC6_USB0EPEN     (8)

#define PORT_PIN_MODE_PC7_U3TX         (1)
#define PORT_PIN_MODE_PC7_WT1CCP1      (7)
#define PORT_PIN_MODE_PC7_USB0PFLT     (8)

#define PORT_PIN_MODE_PD0_SSI3CLK      (1)
#define PORT_PIN_MODE_PD0_SSI1CLK      (2)
#define PORT_PIN_MODE_PD0_I2C3SCL      (3)
#define PORT_PIN_MODE_PD0_M0PWM6       (4)
#define PORT_PIN_MODE_PD0_M1PWM0       (5)
#define PORT_PIN_MODE_PD0_WT2CCP0      (7)

#define PORT_PIN_MODE_PD1_SSI3FSS      (1)
#define PORT_PIN_MODE_PD1_SSI1FSS      (2)
#define PORT_PIN_MODE_PD1_I2C3SDA      (3)
#define PORT_PIN_MODE_PD1_M0PWM7       (4)
#define PORT_PIN_MODE_PD1_M1PWM1       (5)
#define PORT_PIN_MODE_PD1_WT2CCP1      (7)

#define PORT_PIN_MODE_PD2_SSI3RX       (1) 
#define PORT_PIN_MODE_PD2_SSI1RX       (2) 
#define PORT_PIN_MODE_PD2_M0FAULT0     (4)
#define PORT_PIN_MODE_PD2_WT3CCP0      (7)
#define PORT_PIN_MODE_PD2_USB0EPEN     (8)

#define PORT_PIN_MODE_PD3_SSI3TX       (1) 
#define PORT_PIN_MODE_PD3_SSI1TX       (2) 
#define PORT_PIN_MODE_PD3_IDX0         (6)
#define PORT_PIN_MODE_PD3_WT3CCP1      (7)
#define PORT_PIN_MODE_PD3_USB0PFLT     (8)

#define PORT_PIN_MODE_PD4_U6RX         (1)
#define PORT_PIN_MODE_PD4_WT4CCP0      (7)

#define PORT_PIN_MODE_PD5_U6TX         (1)
#define PORT_PIN_MODE_PD5_WT4CCP1      (7)

#define PORT_PIN_MODE_PD6_U2RX         (1)
#define PORT_PIN_MODE_PD6_M0FAULT0     (4)
#define PORT_PIN_MODE_PD6_PHA0         (6)
#define PORT_PIN_MODE_PD6_WT5CCP0      (7)

#define PORT_PIN_MODE_PD7_U2TX         (1)
#define PORT_PIN_MODE_PD7_PHB0         (6)
#define PORT_PIN_MODE_PD7_WT5CCP1      (7)
#define PORT_PIN_MODE_PD7_NMI          (8)

#define PORT_PIN_MODE_PE0_U7RX         (1)
#define PORT_PIN_MODE_PE1_U7TX         (1)

#define PORT_PIN_MODE_PE4_U5RX         (1)
#define PORT_PIN_MODE_PE4_I2C2SCL      (3)
#define PORT_PIN_MODE_PE4_M0PWM4       (4)
#define PORT_PIN_MODE_PE4_M1PWM2       (5)
#define PORT_PIN_MODE_PE4_CAN0RX       (8)

#define PORT_PIN_MODE_PE5_U5TX         (1)
#define PORT_PIN_MODE_PE5_I2C2SDA      (3)
#define PORT_PIN_MODE_PE5_M0PWM5       (4)
#define PORT_PIN_MODE_PE5_M1PWM2       (5)
#define PORT_PIN_MODE_PE5_CAN0TX       (8)

#define PORT_PIN_MODE_PF0_U1RTS        (1)
#define PORT_PIN_MODE_PF0_SSI1RX       (2)
#define PORT_PIN_MODE_PF0_CAN0RX       (3)
#define PORT_PIN_MODE_PF0_M1PWM4       (5)
#define PORT_PIN_MODE_PF0_PHA0         (6)
#define PORT_PIN_MODE_PF0_T0CCP0       (7)
#define PORT_PIN_MODE_PF0_NMI          (8)
#define PORT_PIN_MODE_PF0_C0O          (9)

#define PORT_PIN_MODE_PF1_U1CTS        (1)
#define PORT_PIN_MODE_PF1_SSI1TX       (2)
#define PORT_PIN_MODE_PF1_M1PWM5       (5)
#define PORT_PIN_MODE_PF1_PHB0         (6)
#define PORT_PIN_MODE_PF1_T0CCP1       (7)
#define PORT_PIN_MODE_PF1_C1O          (9)
#define PORT_PIN_MODE_PF1_TRD1         (14)

#define PORT_PIN_MODE_PF2_SSI1CLK      (2)
#define PORT_PIN_MODE_PF2_M0FAULT0     (4)
#define PORT_PIN_MODE_PF2_M1PWM6       (5)
#define PORT_PIN_MODE_PF2_T1CCP0       (7)
#define PORT_PIN_MODE_PF2_TRD10        (14)

#define PORT_PIN_MODE_PF3_SSI1FSS      (2)
#define PORT_PIN_MODE_PF3_CAN0TX       (3)
#define PORT_PIN_MODE_PF3_M1PWM7       (5)
#define PORT_PIN_MODE_PF3_T1CCP1       (7)
#define PORT_PIN_MODE_PF3_TRCLK        (14)

#define PORT_PIN_MODE_PF4_M1FAULT0     (5)
#define PORT_PIN_MODE_PF4_IDX0         (6)
#define PORT_PIN_MODE_PF4_T2CCP0       (7)
#define PORT_PIN_MODE_PF4_USB0EPEN     (8)
typedef uint16 Port_PinModeType;


typedef enum
{
    PORT_DIR_INPUT = 0,
    PORT_DIR_OUTPUT,

}Port_PinDirectionType;

typedef enum
{
   	PORT_ATTACH_PULLUP,
	PORT_ATTACH_PULLDOWN,
	PORT_ATTACH_OPENDRAIN,
    PORT_ATTACH_DEFAULT,	 
}Port_PinInternalAttachType;

typedef enum
{
    PORT_PIN_2mA,
    PORT_PIN_4mA,
    PORT_PIN_8mA,
    PORT_PIN_NA,
}Port_PinOutputCurrentType;


typedef struct
{
    Port_PinType pin;
    Port_PinModeType pinMode;
    Port_PinDirectionType pinDirection;
    Port_PinInternalAttachType pinAttach;
    Port_PinOutputCurrentType pinCurrent;
}Port_ConfigType;


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

 
#endif  /* _PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/

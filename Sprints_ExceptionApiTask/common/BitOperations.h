#ifndef _BIT_OPERATIONS_H
#define _BIT_OPERATIONS_H

#include "Platform_Types.h"

/* bit operation of registers (32 bits)*/
#define SET_BIT(RegAddress, bit)     (*((uint32*)RegAddress) |= (1<<bit))
#define CLR_BIT(RegAddress, bit)     (*((uint32*)RegAddress) &= ~(1<<bit))
#define FLIP_BIT(RegAddress, bit)    (*((uint32*)RegAddress) |= (1<<bit))
#define IS_BIT_SET(RegAddress, bit)  (((*((uint32*)RegAddress)) & (1<<(bit))) >> bit)

/* get alias for peripheral bit banding */
#define GET_REGISTER_ALIAS(RegAddress, bit)        (PERIPHERALS_ALIS_BASE_ADDRESS + ((((RegAddress - PERIPHERALS_BASE_ADDRESS)*8) + bit)*4))


#endif
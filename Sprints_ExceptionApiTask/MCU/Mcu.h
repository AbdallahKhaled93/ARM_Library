#ifndef _MCU_H
#define _MCU_H

#include "Mcu_types.h"


void Mcu_EnableException(Mcu_ExceptionType u8ExceptionType);
void Mcu_DisableException(Mcu_ExceptionType u8ExceptionType);

#endif
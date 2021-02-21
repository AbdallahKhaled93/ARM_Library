#ifndef _MCU_H
#define _MCU_H

#include "CpuDriver_types.h"


void CpuDriver_EnableGlobalInterrupt(void);
void CpuDriver_DisableGlobalInterrupt(void);

void CpuDriver_StartCriticalSection(void);
void CpuDriver_StopCriticalSection(void);

#endif
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  CpuDriver
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _CPU_DRIVER_H
#define _CPU_DRIVER_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "CpuDriver_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


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

void CpuDriver_EnableGlobalInterrupt(void);
void CpuDriver_DisableGlobalInterrupt(void);

void CpuDriver_StartCriticalSection(void);
void CpuDriver_StopCriticalSection(void);

 
#endif  /* _CPU_DRIVER_H */

/**********************************************************************************************************************
 *  END OF FILE: CpuDriver.h
 *********************************************************************************************************************/
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  Mcu
 *
 *  Description:  Header file for Mcu driver     
 *  
 *********************************************************************************************************************/
#ifndef _MCU_H
#define _MCU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Mcu_Types.h"
#include "Mcu_Cfg.h"

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

void Mcu_Init(const Mcu_ConfigType* ConfigPtr);
Mcu_RawResetType Mcu_GetResetRawValue(void);
void Mcu_PerformReset(void);
 
#endif  /* _MCU_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  IntCtrl
 *
 *  Description:  header file for IntCtrl preprocessing configuration    
 *  
 *********************************************************************************************************************/
#ifndef _INTCTRL_CFG_H
#define _INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* The user should enter the desired number of priority groups, and the subgroups number will be deduced automatically */
/* Acceptable values are: 8, 4, 2, 1 */
#define INTCTRL_GRP_PRIO_COUNT                  2

/*  Number of configured system interrupts and MCU peripherals interrupts */
#define INTCTRL_ENABLED_SYS_EXCEPTIONS_COUNT    7
#define INTCTRL_ENABLED_INTERRUPTS_COUNT        4

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

extern const IntCtrl_ExceptionCfgType IntCtrl_ExceptionsCfg[INTCTRL_ENABLED_SYS_EXCEPTIONS_COUNT];
extern const IntCtrl_ExceptionCfgType IntCtrl_InterruptsCfg[INTCTRL_ENABLED_INTERRUPTS_COUNT];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/

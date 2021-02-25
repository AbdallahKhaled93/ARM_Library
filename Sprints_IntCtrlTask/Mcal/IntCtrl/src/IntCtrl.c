/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Interrupt control driver
 *
 *      \details  Implementation of the driver for system peripheral NVIC\SCB
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"
#include "CortexM4_Registers.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/* APINT */ 
#define INTCTRL_APINT_KEY           (0xFA050000)
#define INTCTRL_PRIGROUP_OFFSET     (0x8)

#define INTCTRL_PRIGROUP_XXX        (0x4)
#define INTCTRL_PRIGROUP_XXY        (0x5)
#define INTCTRL_PRIGROUP_XYY        (0x6)
#define INTCTRL_PRIGROUP_YYY        (0x7)

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : void IntCtrl_init(void)     
* \Description     : Init function for the interrupt control peripheral                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
void IntCtrl_init(void)
{

#if !defined(INTCTRL_GRP_PRIO_COUNT)
#error "INTCTRL_GRP_PRIO_COUNT is missing"
#endif

    /* Assign bits to groups and subgroups */
#if   INTCTRL_GRP_PRIO_COUNT == 8
    APINT = INTCTRL_APINT_KEY | (INTCTRL_PRIGROUP_XXX << INTCTRL_PRIGROUP_OFFSET)
#elif INTCTRL_GRP_PRIO_COUNT == 4
    APINT = INTCTRL_APINT_KEY | (INTCTRL_PRIGROUP_XXY << INTCTRL_PRIGROUP_OFFSET)
#elif INTCTRL_GRP_PRIO_COUNT == 2
    APINT = INTCTRL_APINT_KEY | (INTCTRL_PRIGROUP_XYY << INTCTRL_PRIGROUP_OFFSET)
#elif INTCTRL_GRP_PRIO_COUNT == 1
    APINT = INTCTRL_APINT_KEY | (INTCTRL_PRIGROUP_YYY << INTCTRL_PRIGROUP_OFFSET)
#else
#error "Invalid value for INTCTRL_GRP_PRIO_COUNT"
#endif /* INTCTRL_GRP_PRIO_COUNT */
    
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/

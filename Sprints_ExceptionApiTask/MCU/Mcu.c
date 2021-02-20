#include "Mcu.h"



/**
 * Enable exception whether it is programmable or fault exceptions
 * Input : Mcu_ExceptionType 
 * Return : void
 * */
void Mcu_EnableException(Mcu_ExceptionType u8ExceptionType)
{

    /* Trigger exceptio to go to handler mode in order to go to privilege mode */
    __asm("svc #0");

    if (MCU_EXCEPTION_TYPE_PROGRAMMABLE == u8ExceptionType)
    {
        __asm("CPSIE i");
    }
    else if (MCU_EXCEPTION_TYPE_FAULT == u8ExceptionType)
    {
        __asm("CPSIE f");
    }
    else
    {
        /* do nothing */
    }

    /* go to user mode */
  __asm("MOV R0, #0x1");
  __asm("MSR control, R0");
}


/**
 * Disable exception whether it is programmable or fault exceptions
 * Input : Mcu_ExceptionType 
 * Return : void
 * */
void Mcu_DisableException(Mcu_ExceptionType u8ExceptionType)
{

    /* Trigger exceptio to go to handler mode in order to go to privilege mode */
    __asm("svc #0");

    if (MCU_EXCEPTION_TYPE_PROGRAMMABLE == u8ExceptionType)
    {
        __asm("CPSID i");
    }
    else if (MCU_EXCEPTION_TYPE_FAULT == u8ExceptionType)
    {
        __asm("CPSID f");
    }
    else
    {
        /* do nothing */
    }

    /* go to user mode */
  __asm("MOV R0, #0x1");
  __asm("MSR control, R0");
}
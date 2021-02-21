#include "CpuDriver.h"


/* Keeps track of how many nested critical section are entered */
static uint8 u8CriticalSectionCounter = 0;

/**
 * Enable exception whether it is programmable or fault exceptions
 * Input : void 
 * Return : void
 * */
void CpuDriver_EnableGlobalInterrupt(void)
{

    /* Trigger exception to go to handler mode in order to go to privilege mode */
    __asm("svc #0");
    __asm("CPSIE i");
    __asm("CPSIE f");

    /* go to user mode */
    __asm("MOV R0, #0x1");
    __asm("MSR control, R0");
}


/**
 * Disable exception whether it is programmable or fault exceptions
 * Input : void 
 * Return : void
 * */
void CpuDriver_DisableGlobalInterrupt(void)
{

    /* Trigger exception to go to handler mode in order to go to privilege mode */
    __asm("svc #0");
    __asm("CPSID i");
    __asm("CPSID f");

    /* go to user mode */
    __asm("MOV R0, #0x1");
    __asm("MSR control, R0");
}


/**
 * Enter critical section by disabling interrupts
 * Input : void 
 * Return : void
 * */
void CpuDriver_StartCriticalSection(void)
{
    CpuDriver_DisableGlobalInterrupt();
    u8CriticalSectionCounter++;
}

/**
 * Exit critical section by enabling interrupts
 * Input : void 
 * Return : void
 * */
void CpuDriver_StopCriticalSection(void)
{
    u8CriticalSectionCounter--;

    /* Ensure that this is the last exit critical section */
    if(0 == u8CriticalSectionCounter)
    {
        CpuDriver_EnableGlobalInterrupt();
    }
}

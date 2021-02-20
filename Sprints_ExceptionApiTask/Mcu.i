# 1 "MCU/Mcu.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "MCU/Mcu.c"
# 1 "MCU/Mcu.h" 1



# 1 "MCU/Mcu_types.h" 1
# 9 "MCU/Mcu_types.h"
typedef unsigned char Mcu_ExceptionType;
# 5 "MCU/Mcu.h" 2


void Mcu_EnableException(Mcu_ExceptionType u8ExceptionType);
void Mcu_DisableException(Mcu_ExceptionType u8ExceptionType);
# 2 "MCU/Mcu.c" 2
# 10 "MCU/Mcu.c"
void Mcu_EnableException(Mcu_ExceptionType u8ExceptionType)
{


    __asm("svc #0");

    if ((0x1) == u8ExceptionType)
    {
        __asm("CPSIE i");
    }
    else if ((0x2) == u8ExceptionType)
    {
        __asm("CPSIE f");
    }
    else
    {

    }


  __asm("MOV R0, #0x1");
  __asm("MSR control, R0");
}







void Mcu_DisableException(Mcu_ExceptionType u8ExceptionType)
{


    __asm("svc #0");

    if ((0x1) == u8ExceptionType)
    {
        __asm("CPSID i");
    }
    else if ((0x2) == u8ExceptionType)
    {
        __asm("CPSID f");
    }
    else
    {

    }


  __asm("MOV R0, #0x1");
  __asm("MSR control, R0");
}

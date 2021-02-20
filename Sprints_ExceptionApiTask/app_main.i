# 1 "app_main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "app_main.c"
# 1 "app_main.h" 1



extern void vidFunc(short int *u16FuncArgPtr);
# 2 "app_main.c" 2
# 1 "MCU/Mcu.h" 1



# 1 "MCU/Mcu_types.h" 1
# 9 "MCU/Mcu_types.h"
typedef unsigned char Mcu_ExceptionType;
# 5 "MCU/Mcu.h" 2


void Mcu_EnableException(Mcu_ExceptionType u8ExceptionType);
void Mcu_DisableException(Mcu_ExceptionType u8ExceptionType);
# 3 "app_main.c" 2

char u8InitGLobalVar = 2;
static long int u32NonInitStaticGlobalVar;
const short int u16ConstGlobalVar = 3;

void executeFromRam(void) __attribute__((section(".flashDrv")));

const char au32SprintsArray[] __attribute__((section(".sprints"))) = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

char bFlashBlocked = 1;

void executeFromRam(void)
{
 if(bFlashBlocked)
 {
  bFlashBlocked = 0;
 }
}

void main(void)
{
 short int u16LocVar = 4;
 static char u8InitStaticLocVar = 5;
 if(u16ConstGlobalVar == 3)
 {
  u32NonInitStaticGlobalVar = 6;
  vidFunc(&u16LocVar);
 }
 else
 {
  u32NonInitStaticGlobalVar = 7;
 }

 Mcu_EnableException((0x1));
 Mcu_DisableException((0x1));
 Mcu_EnableException((0x2));
 Mcu_DisableException((0x2));

 while(1)
 {
  executeFromRam();
  bFlashBlocked = 1;
 }
}

#include "app_main.h"
#include "Mcu.h"

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
	
	Mcu_EnableException(MCU_EXCEPTION_TYPE_PROGRAMMABLE);
	Mcu_DisableException(MCU_EXCEPTION_TYPE_PROGRAMMABLE);
	Mcu_EnableException(MCU_EXCEPTION_TYPE_FAULT);
	Mcu_DisableException(MCU_EXCEPTION_TYPE_FAULT);

	while(1)
	{
		executeFromRam();
		bFlashBlocked = 1;
	}
}





extern unsigned int __data_load__  ;
extern unsigned int __data_start__ ;
extern unsigned int __data_end__   ;
extern unsigned int __bss_start__  ;
extern unsigned int __bss_end__    ;
extern unsigned int _stack         ;
extern unsigned int __fls_drv_load__;
extern unsigned int __fls_drv_start__;
extern unsigned int __fls_drv_end__;

void ResetHandler(void);

const unsigned int au32VectorTable[] __attribute__((section(".intvecs"))) = {
  0x20007FFC,  // Dummy value for SP (need to know stack direction)
  (unsigned int)&ResetHandler, // Reset handler
};

void ResetHandler(void)
{
  /*Init Stack pointer: Done By HW */
  
  
  
  unsigned int *Ptr2Sbss = (unsigned int*)&__bss_start__;
  unsigned int *Ptr2Ebss = (unsigned int*)&__bss_end__;
  
  unsigned int *Ptr2Src =  (unsigned int*)&__data_load__;
  unsigned int *Ptr2sDes = (unsigned int*)&__data_start__;
  unsigned int *Ptr2eDes = (unsigned int*)&__data_end__;
  
  /* Init .BSS */
  while(Ptr2Sbss< Ptr2Ebss)
  {
	  *(Ptr2Sbss++) = 0;
  }
  
  
  /*Init .DATA */
	while(Ptr2sDes< Ptr2eDes)
	{
		
		
		*(Ptr2sDes++) = *(Ptr2Src++);
	}

  /*Copy flash driver */
  Ptr2Src =  (unsigned int*)&__fls_drv_load__;
  Ptr2sDes = (unsigned int*)&__fls_drv_start__;
  Ptr2eDes = (unsigned int*)&__fls_drv_end__;
	while(Ptr2sDes< Ptr2eDes)
	{
		
		
		*(Ptr2sDes++) = *(Ptr2Src++);
	}
	

	/*jUMB tO MAIN */
	main();
	
	while(1);

}

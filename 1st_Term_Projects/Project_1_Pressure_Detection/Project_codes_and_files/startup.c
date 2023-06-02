//Startup script
// Eng.Youssef Adel
#include<stdint.h>
extern void main(void);
extern uint32_t _stack_top;
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;


void Reset_Handler(void){
  //1st copy data from flash to sram
  uint32_t Data_size = (uint8_t*)&_E_data - (uint8_t*)&_S_data;
  uint8_t* p_src = (uint8_t*) &_E_text;
  uint8_t* p_dst = (uint8_t*)&_S_data;
  uint32_t i;
  for( i=0 ;i < Data_size; i++)
    *((uint8_t*)p_dst++) = *((uint8_t*)p_src++);
  
  //init bss with 0
  uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
  p_dst = (uint8_t*)&_S_bss;
  for( i=0 ;i < bss_size; i++)
    *((uint8_t*)p_dst++) = (uint8_t)0;
  
  // Now jumb to main function
  main();
}

void Default_Handler(void){
  Reset_Handler();
}
void NMI_Handler(void)      __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak,alias("Default_Handler")));
void MemoryManage_Handler(void) __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak,alias("Default_Handler")));



void (*g_p_vectors[])() __attribute__((section (".vectors")))=
{
  (void(*)())&_stack_top,
  &Reset_Handler,
  &NMI_Handler,
  &HardFault_Handler,
  &MemoryManage_Handler,
  &BusFault_Handler,
  &UsageFault_Handler
};
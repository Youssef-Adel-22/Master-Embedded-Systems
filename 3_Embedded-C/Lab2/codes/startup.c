//Startup script
// Eng.Youssef Adel
#include<Platform_Types.h>
extern void main(void);
extern uint32 _stack_top;
extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;


void Reset_Handler(void){
	//1st copy data from flash to sram
	uint32 Data_size = (uint8*)&_E_data - (uint8*)&_S_data;
	uint8* p_src = (uint8*) &_E_text;
	uint8* p_dst = (uint8*)&_S_data;
	uint32 i;
	for( i=0 ;i < Data_size; i++)
		*((uint8*)p_dst++) = *((uint8*)p_src++);
	
	//init bss with 0
	uint32 bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	p_dst = (uint8*)&_S_bss;
	for( i=0 ;i < bss_size; i++)
		*((uint8*)p_dst++) = (uint8)0;
	
	// Now jumb to main function
	main();
}

void Default_Handler(void){
	Reset_Handler();
}
void NMI_Handler(void) 			__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler(void) 	__attribute__((weak,alias("Default_Handler")));
void MemoryManage_Handler(void) __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler(void) 	__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler(void) 	__attribute__((weak,alias("Default_Handler")));

uint32 vectors[] __attribute__((section (".vectors"))) =
{
	(uint32)&_stack_top,
	(uint32)&Reset_Handler,
	(uint32)&NMI_Handler,
	(uint32)&HardFault_Handler,
	(uint32)&MemoryManage_Handler,
	(uint32)&BusFault_Handler,
	(uint32)&UsageFault_Handler
};
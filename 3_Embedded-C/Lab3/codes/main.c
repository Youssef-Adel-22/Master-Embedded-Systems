//Lab4

#include"stdint.h"
#define SYSCTL_RCGC2_R 		(*((volatile uint32_t*)(0x400FE108)))
#define GPIO_PORTF_DIR_R 	(*((volatile uint32_t*)(0x40025400)))
#define GPIO_PORTF_DEN_R 	(*((volatile uint32_t*)(0x4002551C)))
#define GPIO_PORTF_DATA_R 	(*((volatile uint32_t*)(0x400253FC)))

int main(void)
{
SYSCTL_RCGC2_R = 0x20;
//delay to GPIO up 
volatile uint32_t d;
for(d=0 ; d<250 ; d++);
//pinmode bit 3 output
GPIO_PORTF_DIR_R |=(1<<3); 
//Enable it
GPIO_PORTF_DEN_R |=(1<<3); 
while(1){
	GPIO_PORTF_DATA_R ^=(1<<3);
	for(d=0 ; d<500000 ; d++);
	}

}

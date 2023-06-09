#include "uart.h"
#define UART0DDR *((volatile unsigned int * const)((unsigned int *)0x101f1000))

void uart_send_string( unsigned char * P_tx_str){
	while(*P_tx_str !='\0'){
		UART0DDR = (unsigned int)(*P_tx_str);
		P_tx_str++;
	}
}
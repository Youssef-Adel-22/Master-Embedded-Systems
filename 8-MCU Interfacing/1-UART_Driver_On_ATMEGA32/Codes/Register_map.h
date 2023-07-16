/*
 * GPIO_Reg.h
 *
 * Created: 6/20/2023 3:01:15 PM
 *  Author: Harby
 */ 


#ifndef GPIO_REG_H_
#define GPIO_REG_H_
#include<stdint.h>
#define SFIOR *((uint8_t*)0x50)
#define PORTA *((uint8_t*)0x3B)
#define DDRA *((uint8_t*)0x3A)
#define PINA *((uint8_t*)0x39)

#define PORTB *((uint8_t*)0x38)
#define DDRB *((uint8_t*)0x37)
#define PINB *((uint8_t*)0x36)

#define PORTC *((uint8_t*)0x35)
#define DDRC *((uint8_t*)0x34)
#define PINC *((uint8_t*)0x33)

#define PORTD *((uint8_t*)0x32)
#define DDRD *((uint8_t*)0x31)
#define PIND *((uint8_t*)0x30)

/* USART Registers */
#define UDR		*((uint8_t*)0x2C)
#define UCSRA	*((uint8_t*)0x2B)
#define UCSRB	*((uint8_t*)0x2A)
#define UCSRC	*((uint8_t*)0x20)
#define UBRRL	*((uint8_t*)0x29)
#define UBRRH	*((uint8_t*)0x20)

// typedef struct{
// 	uint8_t	 MPCM:1;
// 	uint8_t  U2X:1;
// 	uint8_t  PE:1;
// 	uint8_t  DOR:1;
// 	uint8_t  FE:1;
// 	uint8_t  UDRE:1;
// 	uint8_t  TXC:1;
// 	uint8_t  RXC:1;
// 	}UCSRA_R;
// typedef struct{
// 	uint8_t	 TXB8:1;
// 	uint8_t  RXB8:1;
// 	uint8_t  UCSZ2:1;
// 	uint8_t  TXEN:1;
// 	uint8_t  RXEN:1;
// 	uint8_t  UDRIE:1;
// 	uint8_t  TXCIE:1;
// 	uint8_t  RXCIE:1;
// }UCSRB_R;
// typedef struct{
// 	uint8_t	 UCPOL:1;
// 	uint8_t  UCSZ0:1;
// 	uint8_t  UCSZ1:1;
// 	uint8_t  USBS:1;
// 	uint8_t  UPM0:1;
// 	uint8_t  UPM1:1;
// 	uint8_t  UMSEL:1;
// 	uint8_t  URSEL:1;
// }UCSRC_R;

#endif /* GPIO_REG_H_ */
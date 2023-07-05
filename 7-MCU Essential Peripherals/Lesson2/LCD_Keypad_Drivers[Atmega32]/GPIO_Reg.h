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




#endif /* GPIO_REG_H_ */
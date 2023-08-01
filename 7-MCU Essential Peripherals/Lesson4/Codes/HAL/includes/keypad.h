/*
* keypad.h
*
* Created: 6/20/2023 2:55:46 PM
*  Author: Harby
*/


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include"stdint.h"
#include "Register_map.h"
#include "Utils.h"
extern uint8_t row[4];
extern uint8_t col[4];

#define keypad_PORT PORTD
#define Keypad_Dir DDRD
#define Keypad_PIN PIND

void Keypad_init(void);
char Keypad_Getkey(void);



#endif /* KEYPAD_H_ */
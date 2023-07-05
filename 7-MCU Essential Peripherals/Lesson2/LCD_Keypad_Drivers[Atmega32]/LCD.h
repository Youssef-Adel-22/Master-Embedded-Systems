/*
 * LCD.h
 *
 * Created: 6/20/2023 2:56:50 PM
 *  Author: Harby
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "GPIO_Reg.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#define LCD_DATA PORTA
#define LCD_DATA_Dir DDRA
#define LCD_CTRL PORTB
#define LCD_CTRL_Dir DDRB
#define RS_signal 1
#define RW_signal 2
#define EN_signal 3
#define LCD_MODE 8 //Select 8 bit mode or 4 bit mode

//commands
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


void LCD_init(void);
void LCD_Set_Command(uint8_t command);
void LCD_W_char(char c);
void LCD_W_str(char* str);
void LCD_Busy(void);
void LCD_ReEnable(void);
void LCD_clear(void);
void LCD_char(void);
void LCD_Set_XY(uint8_t x,uint8_t y);
void LCD_cursor_update(void);
#endif /* LCD_H_ */
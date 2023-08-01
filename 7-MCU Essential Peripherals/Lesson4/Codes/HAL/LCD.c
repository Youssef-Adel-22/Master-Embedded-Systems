/*
* LCD.c
*
* Created: 6/20/2023 2:56:35 PM
*  Author: Harby
*/
#include "LCD.h"
#include "Utils.h"
uint8_t x=0;		// for col of LCD(2x16) 0->15
uint8_t y=0;		// for Row of LCD(2x16) 0->1
void LCD_clear()
{
	LCD_Set_Command(LCD_CLEAR_SCREEN);
	x=y=0;
	LCD_Set_XY(x,y);
}
void LCD_ReEnable(void)
{
	Set_bit(LCD_CTRL,EN_signal);
	_delay_ms(50);
	Clear_bit(LCD_CTRL,EN_signal);
	
}
void LCD_Busy(void)
{
	#if (LCD_MODE ==8)
	LCD_DATA_Dir = 0x00;
	Set_bit(LCD_CTRL,RW_signal);
	Clear_bit(LCD_CTRL,RS_signal);
	LCD_ReEnable();
	LCD_DATA_Dir = 0xFF;
	Clear_bit(LCD_CTRL,RW_signal);
	#endif
	#if (LCD_MODE == 4)
	LCD_DATA_Dir &=~(0xFF <<4);
	Set_bit(LCD_CTRL,RW_signal);
	Clear_bit(LCD_CTRL,RS_signal);
	LCD_ReEnable();
	LCD_DATA_Dir |=(0xFF <<4);
	Clear_bit(LCD_CTRL,RW_signal);
	#endif

	
}
void LCD_init(void){
	_delay_ms(20);
	//LCD_DATA_Dir=0xFF;
	LCD_CTRL_Dir |=((1<<RS_signal)|(1<<RW_signal)|(1<<EN_signal));
	LCD_CTRL &= ~((1<<RS_signal)|(1<<RW_signal)|(1<<EN_signal));
	LCD_DATA_Dir= 0xFF;
	_delay_ms(15);
	LCD_clear();
	//Write the command on D0…D7
	#if (LCD_MODE ==8)
	LCD_Set_Command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#if (LCD_MODE == 4)
	LCD_Set_Command(0x02);
	LCD_Set_Command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_Set_Command(LCD_ENTRY_MODE);
	LCD_Set_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Set_Command(LCD_DISP_ON_BLINK);
	
	
}
void LCD_Set_Command(uint8_t command){
	//LCD_Busy();
	#if (LCD_MODE ==8)
	LCD_DATA = command;
	LCD_CTRL&=~((1<<RW_signal)|(1<<RS_signal));
	_delay_ms(1);
	LCD_ReEnable();
	#endif
	
	#if (LCD_MODE ==4)
	LCD_DATA = (LCD_DATA & 0x0F) |(command & 0xF0);
	LCD_CTRL&=~((1<<RW_signal)|(1<<RS_signal));
	LCD_ReEnable();
	LCD_DATA = (LCD_DATA &0x0F) |(command << 4);
	LCD_CTRL&=~((1<<RW_signal)|(1<<RS_signal));
	LCD_ReEnable();
	#endif
	
	
}

void LCD_W_char(char c){
	LCD_DATA_Dir =0xFF;
	_delay_ms(20);

	//LCD_Busy();
	if(c == backSpace){
		x--;
		LCD_Set_XY(x,y);
	}
	#if (LCD_MODE ==8)
	ENABLE_WRITE_MODE;
	ENABLE_DATA_REG;
	LCD_DATA = c;
	_delay_ms(1);
	LCD_ReEnable();
	#endif
	
	#if (LCD_MODE ==4)
	
	ENABLE_WRITE_MODE;
	ENABLE_DATA_REG;
	LCD_DATA = (LCD_DATA & 0x0F) |(c & 0xF0);
	_delay_ms(1);
	LCD_ReEnable();
	
	ENABLE_WRITE_MODE;
	ENABLE_DATA_REG;
	LCD_DATA = (LCD_DATA &0x0F) |(c << 4);
	_delay_ms(1);
	LCD_ReEnable();
	#endif
	
	(c == backSpace)?(LCD_Set_XY(x,y)):(LCD_cursor_update());
}

void LCD_Set_XY(uint8_t X,uint8_t Y)
{
	x=X;
	y=Y;
	if(y == 0)
	{
		if(x >= 0 && x<16)
		LCD_Set_Command(LCD_BEGIN_AT_FIRST_ROW + x);
	}
	else if(y == 1)
	{
		if(x >= 0 && x<16)
		LCD_Set_Command(LCD_BEGIN_AT_SECOND_ROW + x);
	}
}

void LCD_W_str(char* str){

	while(*str > 0)
	{
		LCD_W_char(*str++);
	}
}

void LCD_cursor_update(void)
{
	//Edit your position
	if(x>15 && y==0)
	{
		x=0;
		y=1;
		LCD_Set_XY(x,y);
	}
	else if(x>15 && y==1)
	{
		x=0;
		y=0;
		LCD_clear();
		LCD_Set_XY(x,y);
		
	}
	else
	x++;

}
/*
 * LCD.c
 *
 * Created: 6/20/2023 2:56:35 PM
 *  Author: Harby
 */

#include <LCD.h>
#include <sys/_stdint.h>

uint8_t x=0;		// for col of LCD(2x16) 0->15
uint8_t y=0;		// for Row of LCD(2x16) 0->1
GPIO_PinConfig_t pinConfig;
uint16_t GPIO_PINs[16]={GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};
void _delay_ms(uint32_t d)
{
	uint32_t i,j;
	for(i=0;i<=d;i++)
		for(j=0;j<=255;j++);
}
void LCD_clear()
{
	LCD_Set_Command(LCD_CLEAR_SCREEN);
	x=y=0;
	LCD_Set_XY(x, y);
}
void LCD_ReEnable(void)
{
	//Set_bit(LCD_CTRL,EN_signal);
	MCAL_GPIO_WritePin(LCD_PORT, EN_signal, GPIO_PIN_HIGH);
	_delay_ms(50);
	//Clear_bit(LCD_CTRL,EN_signal);
	MCAL_GPIO_WritePin(LCD_PORT, EN_signal, GPIO_PIN_LOW);

}
void LCD_Busy(void)
{
#if (LCD_MODE ==8)
	//LCD_DATA_Dir = 0x00;
	uint8_t i=0;
	for(i=0;i<=7;i++)
	{
		pinConfig.GPIO_PinNumber = 			GPIO_PINs[i] ;
		pinConfig.GPIO_PinMODE   = 			GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_PORT, &pinConfig);
	}
	//Set_bit(LCD_CTRL,RW_signal);
	MCAL_GPIO_WritePin(LCD_PORT, RW_signal, GPIO_PIN_HIGH);
	//Clear_bit(LCD_CTRL,RS_signal);
	MCAL_GPIO_WritePin(LCD_PORT, RS_signal, GPIO_PIN_LOW);
	LCD_ReEnable();
	//LCD_DATA_Dir = 0xFF;
	for(i=0;i<=7;i++)
	{
		pinConfig.GPIO_PinNumber = 			GPIO_PINs[i] ;
		pinConfig.GPIO_PinMODE   = 			GPIO_MODE_OUTPUT_PP;
		pinConfig.GPIO_Pin_OutputSpeed =  	GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_PORT, &pinConfig);
	}
	//Clear_bit(LCD_CTRL,RW_signal);
	MCAL_GPIO_WritePin(LCD_PORT, RW_signal, GPIO_PIN_LOW);
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
	//LCD_CTRL_Dir |=((1<<RS_signal)|(1<<RW_signal)|(1<<EN_signal));
	uint8_t i;
	for(i=8;i<=10;i++)
	{
		pinConfig.GPIO_PinNumber = 			GPIO_PINs[i] ;
		pinConfig.GPIO_PinMODE   = 			GPIO_MODE_OUTPUT_PP;
		pinConfig.GPIO_Pin_OutputSpeed =  	GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_PORT, &pinConfig);
	}
	//LCD_CTRL &= ~((1<<RS_signal)|(1<<RW_signal)|(1<<EN_signal));
	MCAL_GPIO_WritePin(LCD_PORT, RS_signal, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_PORT, RW_signal, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_PORT, EN_signal, GPIO_PIN_LOW);
	//LCD_DATA_Dir= 0xFF;
	for(i=0;i<=7;i++)
	{
		pinConfig.GPIO_PinNumber = 			GPIO_PINs[i] ;
		pinConfig.GPIO_PinMODE   = 			GPIO_MODE_OUTPUT_PP;
		pinConfig.GPIO_Pin_OutputSpeed =  	GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_PORT, &pinConfig);
	}
	_delay_ms(15);
	LCD_clear();
	//Write the command on D0�D7
#if (LCD_MODE ==8)
	LCD_Set_Command(LCD_FUNCTION_8BIT_2LINES);
#endif
#if (LCD_MODE == 4)
	LCD_Set_Command(0x02);
	LCD_Set_Command(LCD_FUNCTION_4BIT_2LINES);
#endif
	LCD_Set_Command(LCD_ENTRY_MODE);
	LCD_Set_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Set_Command(LCD_DISP_ON);


}
void LCD_Set_Command(uint8_t command){
	LCD_Busy();
#if (LCD_MODE ==8)
	//LCD_DATA = command;
	MCAL_GPIO_WritePort(LCD_PORT, command);
	//LCD_CTRL&=~((1<<RW_signal)|(1<<RS_signal));
	MCAL_GPIO_WritePin(LCD_PORT, RS_signal, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_PORT, RW_signal, GPIO_PIN_LOW);
	_delay_ms(1);
	LCD_ReEnable();
#endif

#if (LCD_MODE ==4)
	LCD_DATA = (LCD_DATA & 0x0F) |(command & 0xF0);
	LCD_CTRL&=~((1<<RW_signal)|(1<<RS_signal));
	LCD_ReEnable();
	LCD_DATA = (LCD_DATA &0x0F) |((command << 4)&0xF0);
	LCD_CTRL&=~((1<<RW_signal)|(1<<RS_signal));
	LCD_ReEnable();
#endif


}

void LCD_W_char(char c){
	LCD_cursor_update();
	//LCD_DATA_Dir =0xFF;
	uint8_t i;
	for(i=0;i<=7;i++)
	{
		pinConfig.GPIO_PinNumber = 			GPIO_PINs[i] ;
		pinConfig.GPIO_PinMODE   = 			GPIO_MODE_OUTPUT_PP;
		pinConfig.GPIO_Pin_OutputSpeed =  	GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_PORT, &pinConfig);
	}
	LCD_Busy();

#if (LCD_MODE ==8)
	//LCD_DATA = c;
	MCAL_GPIO_WritePort(LCD_PORT, c);
	//Set_bit(LCD_CTRL,RS_signal);
	//Clear_bit(LCD_CTRL,RW_signal);
	MCAL_GPIO_WritePin(LCD_PORT, RS_signal, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_PORT, RW_signal, GPIO_PIN_LOW);
	_delay_ms(1);
	LCD_ReEnable();
#endif

#if (LCD_MODE ==4)
	LCD_DATA = (LCD_DATA &0x0F) |(c & 0xF0);
	Set_bit(LCD_CTRL,RS_signal);
	Clear_bit(LCD_CTRL,RW_signal);
	LCD_ReEnable();
	LCD_DATA = (LCD_DATA &0x0F) |(c <<4);
	_delay_ms(1);
	LCD_ReEnable();
#endif


}

void LCD_Set_XY(uint8_t x_pos,uint8_t y_pos)
{
	if(y_pos == 0)
	{
		if(x_pos >= 0 && x_pos<16){
			LCD_Set_Command(LCD_BEGIN_AT_FIRST_ROW + x_pos);
			x=x_pos;
			y=y_pos;
		}
	}
	else if(y_pos == 1)
	{
		if(x_pos >= 0 && x_pos<16)
		{
			LCD_Set_Command(LCD_BEGIN_AT_SECOND_ROW + x_pos);
			x=x_pos;
			y=y_pos;
		}
	}
}

void LCD_W_str(char* str){

	while(*str > 0)
	{
		LCD_W_char(*str++);
		//LCD_cursor_update();
	}
}

void LCD_cursor_update(void)
{
	//Edit x_pos_posour position
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
		LCD_Set_XY(x,y);
		LCD_clear();
	}
	else
		x++;

}

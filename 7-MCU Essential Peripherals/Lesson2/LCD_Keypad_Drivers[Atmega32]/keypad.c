/*
* CFile1.c
*
* Created: 6/20/2023 2:55:52 PM
*  Author: Harby
*/
#include "keypad.h"
#include "LCD.h"
uint8_t row[4]= {0,1,2,3};
uint8_t col[4]= {4,5,6,7};
//char keys[4][4] = {'7','8','9','/','4','5','6','X','1','2','3','-','K','0','=','+'};
char keys[4][4]= {"789/","456X","123-","K0=+"};
void Keypad_init(void)
{
	Keypad_Dir = 0xF0;
	keypad_PORT = 0xFF;		//oxCol Row
}
char Keypad_Getkey(void)
{
	uint8_t c=0,r=0;
	char p='N';
	for(c=0;c<4;c++)
	{
		keypad_PORT|=0xF0;
		keypad_PORT&=~(1<<col[c]);
		for(r=0;r<4;r++)
		{
			if(!(Keypad_PIN & (1<<row[r])))
			{
				_delay_ms(10);
				while(1)
				{
					if((Keypad_PIN & (1<<row[r])))
					break;
				}
				p=keys[r][c];
				
				
			}
		}
	}
	return p;
}

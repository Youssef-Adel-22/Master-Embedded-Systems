#include"uart.h"

unsigned char str_buffer[100]= "Learn-in-depth:Youssef";
void main(void)
{
uart_send_string(str_buffer);

}
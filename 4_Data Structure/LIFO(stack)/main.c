/*
 * main.c
 *
 *  Created on: May 10, 2023
 *      Author: Harby
 */
#include "LIFO.h"

elementType buf1[5];
elementType buf2[5];
int main(){
	unsigned int i;
	elementType item;

	LIFO_Buf_t uart_lifo,i2c_lifo;

	LIFO_init(&uart_lifo, buf1, sizeof(buf1)/sizeof(elementType));
	LIFO_init(&i2c_lifo,buf2,sizeof(buf1)/sizeof(elementType));
	for(i=0;i<7;i++){
		if(LIFO_push(&uart_lifo,i)== LIFO_no_Error)
			printf("%d is pushed in stack\n",i);
		else{
			printf("pushed %d in stack failed Stack is Full\n",i);
		}

	}
	if(LIFO_pop(&uart_lifo , &item)== LIFO_no_Error)
		printf("%d is Poped in stack\n",item);
	if(LIFO_pop(&uart_lifo , &item)== LIFO_no_Error)
		printf("%d is Poped in stack\n",item);

	for(i=0;i<7;i++){
		if(LIFO_pop(&uart_lifo , &item)== LIFO_no_Error)
			printf("%d is Poped in stack\n",item);
		else{
			printf("Pop Failed Empty Stack !!!\n");
		}

	}
	return 1;
}


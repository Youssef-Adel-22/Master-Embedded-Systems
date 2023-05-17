/*
 * main.c
 *
 *  Created on: May 11, 2023
 *      Author: Harby
 */

#include "fifo.h"

extern element_type buff[length];
int main(){
	FIFO_buf_t uart_fifo;
	if(FIFO_init(&uart_fifo,buff,length) == FIFO_no_error)
		printf("FIFO init is DONE \n");
	int i;
	element_type item;
	for(i=0; i<7; i++){
		if(FIFO_enqueue(&uart_fifo,i) == FIFO_no_error)
			printf(" Enqueue %d is DONE\n",i);
		else
			printf(" Enqueue %d is Failed\n",i);
	}
	for(i=0; i<7; i++){
			if(FIFO_dequeue(&uart_fifo,&item) == FIFO_no_error)
				printf(" dequeue %d is done\n",item);

			else
				printf(" dequeue %d is Failed\n",i);
		}
	FIFO_print(&uart_fifo);
	return 1;
}

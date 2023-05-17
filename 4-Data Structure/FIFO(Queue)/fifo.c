/*
 * fifo.c
 *
 *  Created on: May 11, 2023
 *      Author: Harby
 */

#include "fifo.h"
//FIFI_APIs
FIFO_status FIFO_init(FIFO_buf_t* fifo_buff, element_type* buff,uint32_t len){
	if(buff == NULL)
		return FIFO_null;

	fifo_buff->base = buff;
	fifo_buff->head = fifo_buff->base ;
	fifo_buff->till = fifo_buff->base ;
	fifo_buff->len = len;
	fifo_buff->count = 0;
	return FIFO_no_error;
}
FIFO_status FIFO_enqueue(FIFO_buf_t* fifo_buff, element_type item){
	if(!fifo_buff->base || !fifo_buff->head || !fifo_buff->till)
		return FIFO_null;
	if(FIFO_is_full(fifo_buff) == FIFO_full)
		return FIFO_full;

	*(fifo_buff->head) = item;
	(fifo_buff->head == (fifo_buff->base +(fifo_buff->len* sizeof(element_type))))? (fifo_buff->head = fifo_buff->base):fifo_buff->head++;
	fifo_buff->count++;
	return FIFO_no_error;

}
FIFO_status FIFO_dequeue(FIFO_buf_t* fifo_buff, element_type* item){
	if(!fifo_buff->base || !fifo_buff->head || !fifo_buff->till)
		return FIFO_null;
	if(fifo_buff->count == 0)
		return FIFO_empty;
	*item=*(fifo_buff->till);
	(fifo_buff->till == (fifo_buff->base +(fifo_buff->len* sizeof(element_type))))? (fifo_buff->till = fifo_buff->base):fifo_buff->till++;
	fifo_buff->count--;
	return FIFO_no_error;
}
FIFO_status FIFO_is_full(FIFO_buf_t* fifo_buff){
	if(!fifo_buff->base || !fifo_buff->head || !fifo_buff->till)
		return FIFO_null;
	if(fifo_buff->count == fifo_buff->len)
		return FIFO_full;
	return FIFO_no_error;
}
void FIFO_print(FIFO_buf_t* fifo_buff){
	int i;
	element_type* temp = fifo_buff->till;
	for(i=0;i<fifo_buff->count;i++){
		printf("\n %X \n",*temp++);
	}

}

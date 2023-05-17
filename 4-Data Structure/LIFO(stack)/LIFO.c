/*
 ============================================================================
 Name        : LIFO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "LIFO.h"
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf, elementType* buf, unsigned int len){

	if(!buf)
		return LIFO_Null;

	lifo_buf->base=buf;
	lifo_buf->count =0;
	lifo_buf->len=len;
	lifo_buf->head =buf;
	return LIFO_no_Error;
}

LIFO_status LIFO_push(LIFO_Buf_t* lifo_buf, elementType item){
	if(!lifo_buf || !lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	else if(lifo_buf->count == lifo_buf->len){
		return LIFO_Full;
	}
	else{
		*(lifo_buf->head) = item;
		lifo_buf->head++;
		lifo_buf->count++;
		return LIFO_no_Error;
	}

}

LIFO_status LIFO_pop(LIFO_Buf_t* lifo_buf, elementType* item){
	if(!lifo_buf || !lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	else if(lifo_buf->head == lifo_buf->base)
		return LIFO_Empty;
	else{
		lifo_buf->head --;
		*item = *(lifo_buf->head);
		lifo_buf->count--;
		return LIFO_no_Error;
	}


}


/*
 * fifo.h
 *
 *  Created on: May 11, 2023
 *      Author: Harby
 */

#ifndef FIFO_H_
#define FIFO_H_
#include<stdio.h>
#include<stdint.h>

// define the data type(unit8_t,unit16_t,unit32_t,unit64_t,..)
#define element_type uint8_t
#define length 5
//
element_type buff[length];

typedef struct{
	uint32_t count;
	uint32_t len;
	element_type* base;
	element_type* head;
	element_type* till;
}FIFO_buf_t;
typedef enum{
	FIFO_null,
	FIFO_no_error,
	FIFO_empty,
	FIFO_full
}FIFO_status;
//FIFI_APIs
FIFO_status FIFO_init(FIFO_buf_t* fifo_buff, element_type* buff,uint32_t len);
FIFO_status FIFO_enqueue(FIFO_buf_t* fifo_buff, element_type item);
FIFO_status FIFO_dequeue(FIFO_buf_t* fifo_buff, element_type* item);
FIFO_status FIFO_is_full(FIFO_buf_t* fifo_buff);
void FIFO_print(FIFO_buf_t* fifo_buff);

#endif /* FIFO_H_ */

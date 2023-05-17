/*
 * LIFO.H
 *
 *  Created on: May 10, 2023
 *      Author: Harby
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdio.h>
#include "stdint.h"
// define LIFO Type uint8_8 / uint16_t ....
#define elementType uint32_t
//define LIFO
typedef struct {
	unsigned int len;
	unsigned int count;
	elementType* base;
	elementType* head;

}LIFO_Buf_t;

typedef enum{
	LIFO_no_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null
}LIFO_status;
//APIs
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf, elementType* buf, unsigned int len);
LIFO_status LIFO_push(LIFO_Buf_t* lifo_buf, elementType item);
LIFO_status LIFO_pop(LIFO_Buf_t* lifo_buf, elementType* item);

#endif /* LIFO_H_ */

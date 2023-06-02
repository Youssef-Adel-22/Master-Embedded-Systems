/*
 * fifo.h
 *
 *  Created on: May 11, 2023
 *      Author: Harby
 */

#ifndef STUDENT_INF_H_
#define STUDENT_INF_H_
#include<stdio.h>
#include<stdint.h>
#include<string.h>
//Define attr.
#define N_students 50
#define N_Courses 5
//Declaration of student info
typedef struct{
	char FirstName[20];
		char LastName[20];
		uint32_t ID ;
		float GPA;
		uint32_t coursesIDs[N_Courses] ;
}Sstudent_t;

#define element_type Sstudent_t
element_type buff[N_students];
//element_type buff[length];

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
	FIFO_full,
	FIFO_Error,
	FIFO_upper_limit
}FIFO_status;

typedef enum{
	ID_NOT_Exist,
	ID_Exist,
}Student_ID_status;

//FIFI_APIs
FIFO_status FIFO_init(FIFO_buf_t* fifo_buff, element_type* buff,uint32_t len);
FIFO_status add_student_Manually(FIFO_buf_t* fifo_buff);
FIFO_status add_student_from_file(FIFO_buf_t* fifo_buff);
Student_ID_status search_by_id(FIFO_buf_t* fifo_buff);
Student_ID_status search_by_first_name(FIFO_buf_t* fifo_buff);
Student_ID_status search_by_course_id(FIFO_buf_t* fifo_buff);
FIFO_status delete_student(FIFO_buf_t* fifo_buff);
FIFO_status update_student(FIFO_buf_t* fifo_buff);
void student_count(FIFO_buf_t* fifo_buff);
void students_print(FIFO_buf_t* fifo_buff);

#endif /* STUDENT_INF_H_ */

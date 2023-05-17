/*
 * linkedList.h
 *
 *  Created on: May 12, 2023
 *      Author: Harby
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include"stdio.h"
#include"stdint.h"
#include "stdlib.h"
#include "string.h"

struct Sdata{
	uint32_t ID;
	char name[40];
	float height;
};

struct Sstudent{
	struct Sdata StudentData;
	struct Sstudent* PNextStudent;
};
typedef struct Sstudent Sstudent_t;
void AddStudent();
void ViewStudents();
int Delete_Student();
int DeleteAll();
Sstudent_t* print_Student_By_Index();
uint32_t List_length(Sstudent_t* student);
Sstudent_t* Find_Node_From_End(Sstudent_t* List);
Sstudent_t* FindMiddle(Sstudent_t* List);
uint32_t Detectloop(Sstudent_t* List);
Sstudent_t* ReverseList(Sstudent_t* List);
#endif /* LINKEDLIST_H_ */

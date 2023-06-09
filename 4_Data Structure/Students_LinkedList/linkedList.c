/*
 * linkedList.c
 *
 *  Created on: May 12, 2023
 *      Author: Harby
 */

#include "linkedList.h"
Sstudent_t* gpFristStudent = NULL;

void AddStudent(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	Sstudent_t* pLStudent = NULL;
	char temp[40];
	//create new recode
	Sstudent_t* pNStudent =(Sstudent_t*) malloc(sizeof(Sstudent_t));;

	if(gpFristStudent == NULL){
		//Assign it to gpFristStudent
		gpFristStudent = pNStudent;
	}
	//if list is not empty
	else{
		//navigate until reach the last record
		pLStudent = gpFristStudent;
		while(pLStudent ->PNextStudent){
			pLStudent = pLStudent->PNextStudent;
		}
		// now PLast student point to NULL at PNextStudent
		pLStudent->PNextStudent= pNStudent;

	}
	//then create the new record
	printf("\nEnter Student ID: ");
	//scanf("%u",&pNStudent->StudentData.ID);
	scanf("\n");
	pNStudent->StudentData.ID = atoi(gets(temp));

	printf("\nEnter Student Name: ");
	gets(pNStudent->StudentData.name);
	printf("\nEnter Student Height: ");
	gets(temp);
	pNStudent->StudentData.height = atof(temp);
	pNStudent->PNextStudent =NULL;
}

void ViewStudents(){

	//if the list is empty then gpFristStudent is point to null
	if(gpFristStudent == NULL){
		printf(" \n\n ========== \n\n Empty List \n\n ==========\n");
	}
	// if not empty then gpFristStudent is not point to null so we have to navigate
	else{
		Sstudent_t* selectedStudent = gpFristStudent;
		uint32_t i=1;
		printf(" \n\n ========== \n\n Students List \n\n ");
		while(selectedStudent){
			printf("\nStudent %d\n\tID: %u\n\tStudent Name: %s \n\tStudent Height: %0.2f\n\n",i, selectedStudent->StudentData.ID,selectedStudent->StudentData.name,selectedStudent->StudentData.height);
			i++;
			selectedStudent = selectedStudent->PNextStudent;

		}
		printf(" ==========\n");
	}
}

int Delete_Student(){
	printf("\nEnter Student ID: ");
	uint32_t ID;
	scanf("%u",&ID);
	//if the List is Empty
	if(gpFristStudent == NULL){
		printf("\n ==========\n Empty List \n ==========\n\n");
		return 0;
	}
	//if The list not Empty Navigate for this ID
	else{
		Sstudent_t* Select = gpFristStudent;
		Sstudent_t* previous= NULL;
		while(Select){
			//if found it
			if(Select->StudentData.ID == ID){
				//if the selected id = gp First Student
				if(previous == NULL){
					gpFristStudent= Select->PNextStudent;
				}
				else{
					previous->PNextStudent = Select->PNextStudent;
				}
				free(Select);
				printf("\nStudent %u is Deleted..\n",ID);
				return 1;
			}
			previous = Select;
			Select=Select->PNextStudent;
		}
		printf(" Student is Not Exit on the List");
		return 0;
	}
}

int DeleteAll(){
	if(gpFristStudent ==NULL){
		printf("\n\nThe List is already Empty !!!\n==========\n\n");
		return 0;
	}
	else{
		Sstudent_t* Select= gpFristStudent;
		Sstudent_t* temp =NULL;
		while(Select){
			temp = Select;
			Select= Select->PNextStudent;
			free(temp);
		}

	}
	gpFristStudent =NULL;
	printf("\n\nDeletion is DONE !!!\n");
	return 1;
}

Sstudent_t* print_Student_By_Index(){
	uint32_t i, index;
	printf("Enter Student Index: ");
	scanf("%u",&index);
	Sstudent_t * Select = gpFristStudent;
	for(i=0 ; i<index;i++){
		Select=Select->PNextStudent;
	}
	return Select;
}

uint32_t List_length(Sstudent_t* student){
	if(student == NULL){
		return 0;
	}
	else{
		return(1+ List_length(student->PNextStudent));
	}
}

Sstudent_t* Find_Node_From_End(Sstudent_t* List){
	uint32_t index,count=0;
	Sstudent_t* ref =List;
	Sstudent_t* Selected =ref;
	printf("\n Enter the Index of The Student: ");
	scanf("%u",&index);
	if(ref == NULL){
		printf("\n\nEmpty List !!!\n\n");
		return NULL;
	}
	while(ref){
		if(count < index){

			if(ref->PNextStudent){
				ref= ref->PNextStudent;
				count++;
				printf("%u",count);
			}
			else{
				printf("This index Exceeds the List Length !!!\n\n");
				return NULL;
			}
		}
		else{
			if(ref->PNextStudent ==NULL)
				break;
			ref= ref->PNextStudent;
			Selected = Selected->PNextStudent;
		}
	}
	return(Selected);
}

Sstudent_t* FindMiddle(Sstudent_t* List){
	//if empty list return Null
	if(List ==NULL)
		return NULL;
	//else y
	Sstudent_t* slow = List;
	Sstudent_t* fast= slow;
	while(fast->PNextStudent){
		slow=slow->PNextStudent;
		fast= fast->PNextStudent->PNextStudent;
	}
	return slow;
}

uint32_t Detectloop(Sstudent_t* List){
	if(List == NULL || List->PNextStudent == NULL)
		return 0;
	Sstudent_t* follower = List;
	Sstudent_t* fast = follower->PNextStudent;

	while(fast->PNextStudent){
		if(fast == follower)
			return 1;
		else{
			fast=fast->PNextStudent->PNextStudent;
			follower=follower->PNextStudent;
		}
	}
	return 0;
}

Sstudent_t* ReverseList( Sstudent_t* List){
if(List ==NULL){
	printf("Empty List !!!");
	return List;
}
else{
	Sstudent_t* per=List;
	Sstudent_t* current= List->PNextStudent;
	Sstudent_t* next =NULL;
	per->PNextStudent =NULL;
	while(current){
		next = current->PNextStudent;
		current->PNextStudent= per;
		per =current;
		current =next;
	}
	return per;
}

}

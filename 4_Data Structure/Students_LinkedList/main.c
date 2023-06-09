/*
 * main.c
 *
 *  Created on: May 12, 2023
 *      Author: Harby
 */
#include "linkedList.h"
extern Sstudent_t* gpFristStudent;
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i =0;
	while(1){
		printf("\t ========== \n choose on of the following Options \n\n"
				"1- Add New Student\n"
				"2- View Students\n"
				"3- Delete Student\n"
				"4- Delete All Students\n"
				"5- Get Student By Index \n"
				"6- Get List Length\n"
				"7- Get Node By Index from the End\n"
				"8- Find Middle of the List\n"
				"9- Detecting Loop\n"
				"10- Reverse Students List\n");

		scanf("%d",&i);
		switch(i){
		case 1:
			AddStudent();
			break;
		case 2:
			ViewStudents();
			break;
		case 3:
			Delete_Student();
			break;
		case 4:
			DeleteAll();
			break;
		case 6:
			printf("\n\nStudents Count is: %u\n\n",List_length(gpFristStudent));
			break;
		}
		if(i==5){
			Sstudent_t* Select= print_Student_By_Index();
			printf("\nStudent ID: %u\nStudent Name: %s \nStudent Height: %0.2f\n",Select->StudentData.ID,Select->StudentData.name,Select->StudentData.height);

		}
		else if(i== 7){
			Sstudent_t* Select= Find_Node_From_End(gpFristStudent);
			if(Select != NULL)
				printf("\nStudent ID: %u\nStudent Name: %s \nStudent Height: %0.2f\n",Select->StudentData.ID,Select->StudentData.name,Select->StudentData.height);
		}
		else if(i== 8){
			Sstudent_t* Select= FindMiddle(gpFristStudent);
			if(Select != NULL)
				printf("\nStudent ID: %u\nStudent Name: %s \nStudent Height: %0.2f\n",Select->StudentData.ID,Select->StudentData.name,Select->StudentData.height);
		}
		else if(i== 9){
			(Detectloop(gpFristStudent))? printf("LOOP Detected"):printf("there is No LOOP Detected");
		}
		else if(i== 10){
			printf("List Before Reverse");
			ViewStudents();
			gpFristStudent= ReverseList(gpFristStudent);
			printf("List After Reverse");
			ViewStudents();
		}
	}
}

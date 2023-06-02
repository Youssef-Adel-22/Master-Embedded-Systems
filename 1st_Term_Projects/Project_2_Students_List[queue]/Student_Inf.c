/*
 * fifo.c
 *
 *  Created on: May 11, 2023
 *      Author: Harby
 */

#include "Student_Inf.h"

//FIFO status Functions
FIFO_status get_FIFO_status(FIFO_buf_t* fifo_buff){
	if(!fifo_buff->base || !fifo_buff->head || !fifo_buff->till){
		printf("ERROR !!!!, NULL is passed\n");
		return FIFO_null;
	}
	if(fifo_buff->count == fifo_buff->len){
		printf("The List is Full !!!");
		return FIFO_full;
	}
	if(fifo_buff->count == 0){
		printf("The List is Empty !!!");
		return FIFO_empty;
	}
	if(fifo_buff->head == (fifo_buff->base + fifo_buff->len-1))
		return FIFO_upper_limit;
	return FIFO_no_error;
}

Student_ID_status check_this_id(FIFO_buf_t* fifo_buff, uint32_t ID ){
	Sstudent_t *temp = fifo_buff->till;
	volatile uint32_t i=0;
	for(i=0; i<fifo_buff->count ;i++){
		if(ID == temp->ID)
			return ID_Exist;
		else if(temp == (fifo_buff->base + fifo_buff->len-1) )
			temp = fifo_buff->base;
		else{
			temp++;
		}
	}
	return ID_NOT_Exist;
}

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
FIFO_status add_student_Manually(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{

		uint32_t ID =0,i=0;
		printf("Add The Student Details\n-----------------------\n");
		printf("Enter The Roll Number: ");
		scanf("%u",&ID);
		if(check_this_id(fifo_buff, ID )){
			printf("ID already taken!!! ");
			return FIFO_Error;
		}
		else{
			Sstudent_t *temp = fifo_buff->head;
			temp->ID=ID;
			printf("Enter The first name of student: ");
			scanf("%s",(char*)&temp->FirstName);
			printf("Enter The last name of student: ");
			scanf("%s",(char*)&temp->LastName);
			printf("Enter The GPA you obtained: ");
			scanf("%f",&temp->GPA);
			printf("Enter The course ID of each course: \n");
			for(i=0;i<N_Courses;i++){
				printf("Course %u id: ",i+1);
				scanf("%u",&temp->coursesIDs[i]);
			}
			printf("\nDone\n");
			fifo_buff->count++;
			fifo_buff->head++;
		}
	}
	printf("[INFO] Student Details is added Successfully");
	printf("\n----------------------------\n");
	student_count(fifo_buff);
	return FIFO_no_error;
}

FIFO_status add_student_from_file(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{
		FILE *student_data_file;
		Sstudent_t temp_student;
		uint32_t count=0;
		student_data_file = fopen("StudentData.txt","r");
		if(!student_data_file){
			printf(" Can't open the text file!!");
			return FIFO_Error;
		}
		else{
			while(!feof(student_data_file)){ //returns nonzero if and only if the end-of-file
				fscanf(student_data_file,"%d",&temp_student.ID);
				//check if ID already exist
				if(check_this_id(fifo_buff, temp_student.ID)){
					printf("[Error] Roll Number %u is already taken\n",temp_student.ID);
					fscanf(student_data_file, "%*[^\n]");
					continue;
				}
				fscanf(student_data_file,"%s",temp_student.FirstName);
				fscanf(student_data_file,"%s",temp_student.LastName);
				fscanf(student_data_file,"%f",&temp_student.GPA);
				for (int i=0;i<N_Courses;i++)
				{
					fscanf(student_data_file,"%u",&temp_student.coursesIDs[i]);
				}
				//now add to the list
				*(fifo_buff->head) = temp_student;
				if(get_FIFO_status(fifo_buff)== FIFO_upper_limit && get_FIFO_status(fifo_buff)!= FIFO_full)
					fifo_buff->head = fifo_buff->base;
				else
					fifo_buff->head++;
				fifo_buff->count++;
				count++;
				printf("[INFO] Roll Number %u saved successfully\n",temp_student.ID);
			}
			fclose(student_data_file);
			printf("[INFO] Students Details Added Successfully\n-------------------------------------\n");
		}
		printf("[INFO] Student Details is added Successfully");
		printf("\n----------------------------\n");
		student_count(fifo_buff);
		return FIFO_no_error;
	}

}

Student_ID_status search_by_id(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{
		uint32_t ID =0,i=0;
		printf("Enter the Roll Number of the student: ");
		scanf("%u",&ID);
		Sstudent_t* temp = fifo_buff->till;
		for(i=0;i<fifo_buff->count;i++){
			if(temp->ID == ID){ //if found it
				printf("The student Details\n");
				printf("The First Name is %s\n",temp->FirstName);
				printf("The Last Name is %s\n",temp->LastName);
				printf("The GPA is %.2f\n",temp->GPA);
				printf("Enrolled courses are:\n");
				for(i=0;i<N_Courses;i++)
					printf("The Course %u ID is: %u\n",i+1,temp->coursesIDs[i]);

				return ID_Exist;
			}
			if(temp == (fifo_buff->base + fifo_buff->len-1))
				temp = fifo_buff->base;
			else{
				temp++;
			}
		}
		//if Not found it ..
		printf("[ERROR] Roll Number Not Found\n");
		return ID_NOT_Exist;
	}
}
Student_ID_status search_by_first_name(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{
		char name[20]="";
		uint32_t i=0;
		printf("Enter the First Name of the student: ");
		scanf("%s",name);
		Sstudent_t* temp = fifo_buff->till;
		for(i=0;i<fifo_buff->count;i++){
			if(!strcmp(temp->FirstName,name)){ //if found it
				printf("The student Details\n");
				printf("The First Name is %s\n",temp->FirstName);
				printf("The Last Name is %s\n",temp->LastName);
				printf("The GPA is %.2f\n",temp->GPA);
				printf("Enrolled courses are:\n");
				for(i=0;i<N_Courses;i++)
					printf("The Course %u ID is: %u\n",i+1,temp->coursesIDs[i]);

				return ID_Exist;
			}
			if(temp == (fifo_buff->base + fifo_buff->len-1))
				temp = fifo_buff->base;
			else{
				temp++;
			}
		}
		//if Not found it ..
		printf("[ERROR] First Name Not Found\n");
		return ID_NOT_Exist;
	}
}
Student_ID_status search_by_course_id(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{
		uint32_t ID =0,i=0,n=0;
		printf("Enter the Course ID of the student: ");
		scanf("%u",&ID);
		Sstudent_t* temp = fifo_buff->till;
		for(i=0;i<fifo_buff->count;i++){
			for(n=0;n<N_Courses;n++){
				if(temp->coursesIDs[n] == ID){ //if found it
					printf("The student Details\n");
					printf("The First Name is %s\n",temp->FirstName);
					printf("The Last Name is %s\n",temp->LastName);
					printf("The GPA is %.2f\n",temp->GPA);
				}
			}
			if(temp == (fifo_buff->base + fifo_buff->len-1))
				temp = fifo_buff->base;
			else{
				temp++;
			}
		}
		//if Not found it ..
		printf("[ERROR] Course ID %u Not Found\n",ID);
		return ID_NOT_Exist;
	}
}
void student_count(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)==FIFO_no_error){
		printf("[INFO] The Total Number of Students is %u\n",fifo_buff->count);
		printf("[INFO] You can add up to %u Students\n",fifo_buff->len);
		printf("[INFO] You can add %u more Students\n",fifo_buff->len-fifo_buff->count);
	}
}
FIFO_status delete_student(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{
		uint32_t ID =0,i=0,flag=0;
		printf("Enter the Roll Number which you want to delete: ");
		scanf("%u",&ID);
		if(check_this_id(fifo_buff,ID)== ID_Exist){
			Sstudent_t *current = fifo_buff->till;
			Sstudent_t *next= current+1;
			for(;i<fifo_buff->count;i++){
				if(current->ID == ID){
					flag=1;
				}
				if(flag)
					*current = *next;
				if(current == (fifo_buff->base + fifo_buff->len-1))
					current = fifo_buff->base;
				else
					current++;
				if(next == (fifo_buff->base + fifo_buff->len-1))
					next = fifo_buff->base;
				else
					next++;
			}
			fifo_buff->head--;
			fifo_buff->count--;
			printf("[INFO] The Roll Number is Removed Successfully \n");
			return ID_Exist;
		}
		else{
			//if Not found it ..
			printf("[ERROR] Roll Number Not Found\n");
			return ID_NOT_Exist;
		}
	}

}
FIFO_status update_student(FIFO_buf_t* fifo_buff){
	if(get_FIFO_status(fifo_buff)== FIFO_null){
		return FIFO_null;
	}
	else if(get_FIFO_status(fifo_buff) == FIFO_full){
		return FIFO_full;
	}
	else{
		uint32_t ID =0,i=0;
		printf("Enter the Roll Number to update the Entry: ");
		scanf("%u",&ID);
		if(check_this_id(fifo_buff,ID)== ID_Exist){
			Sstudent_t *temp_ptr = fifo_buff->till;

			for(;i<fifo_buff->count;i++){
				if(temp_ptr->ID == ID){
					printf("1- first name\n");
					printf("2- last name\n");
					printf("3- roll number\n");
					printf("4- GPA\n");
					printf("5- Courses\n");
					scanf("%u",&i);
					if(i == 1){
						printf("Enter the new first name: ");
						scanf("%s",temp_ptr->FirstName);
					}
					else if(i == 2){
						printf("Enter the new last name: ");
						scanf("%s",temp_ptr->LastName);
					}
					else if(i == 3){
						printf("Enter the new roll number: ");
						scanf("%u",&ID);
						if(check_this_id(fifo_buff,ID)){
							printf("ID already taken!!! ");
							return FIFO_Error;
						}
						else
							temp_ptr->ID = ID;
					}
					else if(i == 4){
						printf("Enter the new GPA number: ");
						scanf("%u",temp_ptr->GPA);
					}
					else if(i == 5){
						printf("Enter The new course ID of each course: \n");
						for(i=0;i<N_Courses;i++){
							printf("Course %u id: ",i+1);
							scanf("%u",&temp_ptr->coursesIDs[i]);
						}
					}
					printf("[INFO] UPDATED SUCCESSFULLY\n");
					return FIFO_no_error;
				}
				else
					temp_ptr++;
			}
		}
		else{
			//if Not found it ..
			printf("[ERROR] Roll Number Not Found\n");
			return ID_NOT_Exist;
		}
	}

}
void students_print(FIFO_buf_t* fifo_buff){
	int i,j;
	element_type* temp = fifo_buff->till;
	for(i=0;i<fifo_buff->count;i++){
		printf("The student %d Details\n",i+1);
		printf("Student First Name: %s\n",temp->FirstName);
		printf("Student Last Name: %s\n",temp->LastName);
		printf("Student Roll Number: %u\n",temp->ID);
		printf("Student GPA Number: %.2f\n",temp->GPA);
		printf("Enrolled courses are:\n");
		for(j=0;j<N_Courses;j++)
			printf("The Course %u ID is: %u\n",j+1,temp->coursesIDs[j]);
		printf("-------------------------------------\n");
		temp++;
	}

}
/*FIFO_status FIFO_enqueue(FIFO_buf_t* fifo_buff, element_type item){
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


 */



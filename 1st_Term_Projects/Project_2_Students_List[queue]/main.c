/*
 * main.c
 *
 *  Created on: May 11, 2023
 *      Author: Harby
 */

#include "Student_Inf.h"



int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	FIFO_buf_t student_list;
	uint32_t i=0;
	if(FIFO_init(&student_list,buff,N_students) == FIFO_no_error){
		printf("FIFO init is DONE \n");
	}

	while(i!=10){
		printf("\n	============================\n");
		printf("\tChoose on the following options\n\n");
		printf ("1 : Add the Student Details Manually  \n") ;
		printf ("2 : Add the Student Details From Text File \n") ;
		printf ("3 : Find the Student Details by Roll Number \n") ;
		printf ("4 : Find the Student Details by First Name \n") ;
		printf ("5 : Find the Student Details by CourseID \n") ;
		printf ("6 : Find Total Number Of Students \n") ;
		printf ("7 : Delete the Student Details by Roll Number \n") ;
		printf ("8 : Update the Student Details by Roll Number \n") ;
		printf ("9 : Show All Information \n") ;
		printf ("10: To Exit  \n\n") ;
		printf ("Enter Your Choice to perform the task: ") ;
		scanf("%u",&i);
		printf("-----------------------\n");
		switch(i){
		case 1:
			add_student_Manually(&student_list);

			break;
		case 2:
			add_student_from_file(&student_list);
			break;
		case 3:
			search_by_id(&student_list);
			break;
		case 4:
			search_by_first_name(&student_list);
			break;
		case 5:
			search_by_course_id(&student_list);
			break;
		case 6:
			student_count(&student_list);
			break;

		case 7:
			delete_student(&student_list);
			break;
		case 8:
			update_student(&student_list);
			break;
		case 9:
			students_print(&student_list);
			break;
		}
	}

	return 1;
}

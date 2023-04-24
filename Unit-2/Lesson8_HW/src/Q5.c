/*
 * Q5.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Harby
 */

void Q5_function(){
struct employee{
	char *empName;
	int empID;
};

struct employee emp1={"Youssef" , 180},emp2={"Harby" , 100},emp3={"Adel" , 1010};
struct employee *arr[]={&emp1,&emp2,&emp3};
struct employee (*(*ptr)[3]) = &arr;

printf("Exmployee Name : %s \n", (*(*ptr+1))->empName);
printf("Employee ID : %d \n", (*(*ptr+1))->empID);

}

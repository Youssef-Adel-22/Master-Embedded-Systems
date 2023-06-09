/*
 ============================================================================
 Name        : Lesson1_HW1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Print_an_Integer_Entered_by_a_User();
void Add_Two_Integers();
void Multiply_two_Floating_Point_Numbers();
void Find_ASCII_Value_of_a_Character();
void Swap_Two_Numbers();
void Swap_Two_Numbers_without_temp_variable();
int main(void) {
	int choose =0;
	while(choose != 8){
		puts("Choose a program:\n");
		puts("1- C Program to Print a Sentence");
		puts("2- Print an Integer Entered by a User");
		puts("3- Add Two Integers");
		puts("4- Multiply two Floating Point Numbers");
		puts("5- Find ASCII Value of a Character");
		puts("6- Swap Two Numbers");
		puts("7- Swap Two Numbers without temp variable");

		fflush(stdout);
		scanf("%d",&choose);
		switch(choose){
		case 1:
			puts("C Programming");
			break;
		case 2:
			Print_an_Integer_Entered_by_a_User();
			break;
		case 3:
			Add_Two_Integers();
			break;
		case 4:
			Multiply_two_Floating_Point_Numbers();
			break;
		case 5:
			Find_ASCII_Value_of_a_Character();
			break;
		case 6:
			Swap_Two_Numbers();
			break;
		case 7:
			Swap_Two_Numbers_without_temp_variable();
			break;
		case 8:
			puts("The Program Terminated");
			break;
		}

		puts("\n\nEnter 0 to Continue or 8 to Exit");
		fflush(stdout);
		scanf("%d",&choose);
	}
	puts("Program Terminated");
	return EXIT_SUCCESS;
}

void Print_an_Integer_Entered_by_a_User(){
	int x;
	puts("Enter an Integer:");
	fflush(stdout);
	scanf("%d",&x);
	puts("You Entered:");
	fflush(stdin);
	printf("%d",x);
}
void Add_Two_Integers(){
	int a,b;
	puts("Enter two integers:");
	fflush(stdout);
	scanf("%d %d",&a,&b);
	puts("Sum:");
	fflush(stdin);
	printf("%d",a+b);
}
void Multiply_two_Floating_Point_Numbers(){
	float a,b;
	puts("Enter two numbers:");
	fflush(stdout);
	scanf("%f %f",&a,&b);
	puts("Sum:");
	fflush(stdin);
	printf("%f",a*b);
}
void Find_ASCII_Value_of_a_Character(){
	char c;
	puts("Enter a character:");
	fflush(stdout);
	scanf("\n%c",&c);
	fflush(stdin);
	printf("ASCII value of %c = %d",c,c);



}
void Swap_Two_Numbers(){
	float a,b,temp;
	puts("Enter value of a:");
	fflush(stdout);
	scanf("%f",&a);
	puts("Enter value of b:");
	fflush(stdout);
	scanf("%f",&b);
	temp =a;
	a=b;
	b=temp;
	fflush(stdin);
	printf("After swapping, value of a = %0.2f\n",a);
	fflush(stdin);
	printf("After swapping, value of b = %0.2f\n",b);
}
void Swap_Two_Numbers_without_temp_variable(){
	float a,b;
	puts("Enter value of a:");
	fflush(stdout);
	scanf("%f",&a);
	puts("Enter value of b:");
	fflush(stdout);
	scanf("%f",&b);
	a =a+b;
	b=a-b;
	a=a-b;
	fflush(stdin);
	printf("After swapping, value of a = %0.2f\n",a);
	fflush(stdin);
	printf("After swapping, value of b = %0.2f\n",b);
}

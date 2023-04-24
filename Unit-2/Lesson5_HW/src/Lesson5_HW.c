/*
 ============================================================================
 Name        : Lesson5_HW.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : Lesson4_HW1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Prime_Numbers_Between_two_Intervals();
int Calculate_Factorial_of_a_Number(int num);
void Reverse_a_Sentence();
int Calculate_the_Power_of_a_Number(int num,int p);



int main(void) {

	int choose =0,num,p;

	while(choose != 8){
		puts("Choose a program:\n");
		puts("1- Prime Numbers Between two Intervals");
		puts("2- Calculate Factorial of a Number");
		puts("3- Reverse a Sentence");
		puts("4- Calculate the Power of a Number");

		fflush(stdout);
		scanf("%d",&choose);

		switch(choose){

		case 1:
			Prime_Numbers_Between_two_Intervals();
			break;

		case 2:
			fflush(stdin);
			printf("Enter an integer:");
			fflush(stdout);
			scanf("%d",&num);
			(num <0)? puts("Error!!! Factorial of negative number doesn't exist."):printf("%d",Calculate_Factorial_of_a_Number(num));
			break;

		case 3:
			fflush(stdin);
			printf("Enter a senten: ");
			Reverse_a_Sentence();
			break;

		case 4:
			fflush(stdin);
			printf("Enter base number: ");
			fflush(stdout);
			scanf("%d",&num);
			fflush(stdin);
			printf("Enter power number(positive integer): ");
			fflush(stdout);
			scanf("%d",&p);
			fflush(stdin);
			printf("%d^%d = ",num,p);
			printf("%d",Calculate_the_Power_of_a_Number(num,p));
			break;
		}

		puts("\n\nEnter 0 to Continue or 8 to Exit");
		fflush(stdout);
		scanf("%d",&choose);
	}
	puts("The Program Terminated");
	return EXIT_SUCCESS;
}

void Prime_Numbers_Between_two_Intervals(){
	int i,j;
	puts("Enter two numbers(intervals)");
	fflush(stdout);
	scanf("%d %d",&i,&j);
	printf("Prime numbers between %d and %d are:",i,j);
	for(++i;i<j;i++){
		(i%2 !=0 && i%3!=0 && i%5!=0 && i%7!=0)? printf("%d ",i) :0;
	}

}
int Calculate_Factorial_of_a_Number(int num){
	if(num == 0){
		return 1;
	}
	else{
		return(num* Calculate_Factorial_of_a_Number(num-1));
	}


}
void Reverse_a_Sentence(){
	char c;
	fflush(stdout);
	scanf("%c",&c);

	if(c !='\n'){
		Reverse_a_Sentence();
		printf("%c",c);
	}
}
int Calculate_the_Power_of_a_Number(int num,int p){
	if(p == 0){
		return 1;
	}
	else{
		return(num * Calculate_the_Power_of_a_Number(num , p-1));
	}
}

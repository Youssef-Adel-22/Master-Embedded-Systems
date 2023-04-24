/*
 ============================================================================
 Name        : Lesson3_HW2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Check_Whether_a_Number_is_Even_or_Odd();
void Check__Whether_a_Character_is_Vowel_or_Consonant();
void Find_the_Largest_Number_Among_Three_Numbers();
void Check_Whether_a_Number_is_Positive_or_Negative();
void Check_Whether_a_Character_is_an_Alphabet_or_not();
void Calculate_Sum_of_Natural_Numbers();
int Find_Factorial_of_a_Number(int n);
void Calcolator();
int main(void) {
	int choose =0,n;
	while(choose != 8){
		puts("Choose a program:\n");
		puts("1- Check Whether a Number is Even or Odd");
		puts("2- Check Whether a_Character is Vowel or Consonant");
		puts("3- Find the Largest Number Among Three Numbers");
		puts("4- Check Whether a Number is Positive or Negative");
		puts("5- Check Whether a Character is an Alphabet or not");
		puts("6- Calculate Sum of Natural Numbers");
		puts("7- Find Factorial of a Number");
		puts("8- Simple Calculator to Add, Subtract, Multiply or Divide");
		fflush(stdout);
		scanf("%d",&choose);
		switch(choose){
		case 1:
			Check_Whether_a_Number_is_Even_or_Odd();
			break;
		case 2:
			Check__Whether_a_Character_is_Vowel_or_Consonant();
			break;
		case 3:
			Find_the_Largest_Number_Among_Three_Numbers();
			break;
		case 4:
			Check_Whether_a_Number_is_Positive_or_Negative();
			break;
		case 5:
			Check_Whether_a_Character_is_an_Alphabet_or_not();
			break;
		case 6:
			Calculate_Sum_of_Natural_Numbers();
			break;
		case 7:

			puts("Enter an integer:");
			fflush(stdout);
			scanf("%d",&n);
			(n <0)? puts("Error!!! Factorial of negative number doesn't exist."):printf("%d",Find_Factorial_of_a_Number(n));

			break;
		case 8:
			Calcolator();
			break;
		}

		puts("\n\nEnter 0 to Continue or 8 to Exit");
		fflush(stdout);
		scanf("%d",&choose);
	}
	puts("The Program Terminated");
	return EXIT_SUCCESS;
}

void Check_Whether_a_Number_is_Even_or_Odd(){
	int x;
	puts("Enter an integer you want to check:");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdin);
	(x%2==0)? printf("%d is even",x) : printf("%d is odd",x);

}
void Check__Whether_a_Character_is_Vowel_or_Consonant(){
	char c;
	puts("Enter an alphabet:");
	fflush(stdout);
	scanf("\n%c",&c);
	fflush(stdin);
	(c== 'a' || c== 'e' || c== 'i' ||c== 'o' ||c== 'u')? printf("%c is vowel",c):printf("%c is constant",c);





}
void Find_the_Largest_Number_Among_Three_Numbers(){
	float a,b,c,L;
	puts("Enter two integers:");
	fflush(stdout);
	scanf("%f %f %f",&a,&b,&c);
	if(a>b){
		if (a>c){
			L=a;
		}
		else{
			L=c;
		}
	}
	else {
		if(b>c){
			L=b;
		}
		else{
			L=c;
		}
	}
	fflush(stdin);
	printf("Largest number = %0.2f",L);
}
void Check_Whether_a_Number_is_Positive_or_Negative(){
	float a;
	puts("Enter a number:");
	fflush(stdout);
	scanf("%f",&a);
	if(a > 0)
		printf("%0.2f is positive.",a);
	else if(a<0)
		printf("%0.2f is negative.",a);
	else
		printf("You entered zero.");

}
void Check_Whether_a_Character_is_an_Alphabet_or_not(){
	char c;
	puts("Enter a character:");
	fflush(stdout);
	scanf("\n%c",&c);
	((c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z'))? printf("%c is an alphabet",c): printf("%c is not an alphabet",c);
}
void Calculate_Sum_of_Natural_Numbers(){
	int n,sum=0,i;
	puts("Enter an integer:");
	fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		sum+=i;
	fflush(stdin);
	printf("Sum   %d",sum);
}
int Find_Factorial_of_a_Number(int n){
	if(n == 0){
		return 1;
	}
	else{
		return(n* Find_Factorial_of_a_Number(n-1));
	}
}
void Calcolator(){
	float a,b;
	char c;
	puts("Enter operator either + or - or * or divide :");
	fflush(stdout);
	scanf("\n%c",&c);
	puts("Enter two operands:");
	fflush(stdout);
	scanf("%f %f",&a,&b);
	switch (c){
	case '+':
		printf("%0.2f + %0.2f = %0.2f",a,b,a+b);
		break;
	case '-':
			printf("%0.2f - %0.2f = %0.2f",a,b,a-b);
			break;
	case '*':
			printf("%0.2f x %0.2f = %0.2f",a,b,a*b);
			break;
	case '/':
			printf("%0.2f / %0.2f = %0.2f",a,b,a/b);
			break;
	}

}


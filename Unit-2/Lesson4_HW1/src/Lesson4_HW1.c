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
#include <string.h>
void find_sum_of_two_matrix_of_order_2x2();
void Calculate_Average_Using_Arrays();
void Find_Transpose_of_a_Matrix();
void Insert_an_element_in_an_Array();
void Search_an_element_in_Array();
void Find_the_Frequency_of_Characters_in_a_String();
void Find_the_Length_of_a_String();
void Reverse_String_Without_Using_Library_Function();


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int choose =0;
	while(choose != 8){
		puts("Choose a program:\n");
		puts("1- find sum of two matrix of order 2*2");
		puts("2- Calculate Average Using Arrays");
		puts("3- Find Transpose of a Matrix");
		puts("4- Insert an element in an Array");
		puts("5- Search an element in Array");
		puts("6- Find the Frequency of Characters in a String");
		puts("7- Find the Length of a String");
		puts("8- Reverse String Without Using Library Function");
		fflush(stdout);
		scanf("%d\n",&choose);
		switch(choose){
		case 1:
			find_sum_of_two_matrix_of_order_2x2();
			break;
		case 2:
			Calculate_Average_Using_Arrays();
			break;
		case 3:
			Find_Transpose_of_a_Matrix();
			break;
		case 4:
			Insert_an_element_in_an_Array();
			break;
		case 5:
			Search_an_element_in_Array();
			break;
		case 6:
			Find_the_Frequency_of_Characters_in_a_String();
			break;
		case 7:

			Find_the_Length_of_a_String();

			break;
		case 8:
			Reverse_String_Without_Using_Library_Function();
			break;
		}

		puts("\n\nEnter 0 to Continue or 8 to Exit");
		fflush(stdout);
		scanf("%d",&choose);
	}
	puts("The Program Terminated");
	return EXIT_SUCCESS;
}

void find_sum_of_two_matrix_of_order_2x2(){
	float a[2][2],b[2][2],sum[2][2];
	int i,j;
	puts("Enter the elements of 1st matrix ");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			fflush(stdin);
			printf("Enter a%d%d:",i+1,j+1);
			fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	puts("Enter the elements of 2nd matrix ");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			fflush(stdin);
			printf("Enter b%d%d:",i+1,j+1);
			fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	puts("Sum Of Matrix:");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			sum[i][j]=a[i][j]+b[i][j];
			fflush(stdin);
			printf("%0.2f  ",sum[i][j]);

		}
		printf("\n");
	}

}
void Calculate_Average_Using_Arrays(){
	int n,i;
	puts("Enter the numbers of data:");
	fflush(stdout);
	scanf("%d",&n);
	float a[n],avr=0;
	for(i=0;i<n;i++){
		fflush(stdin);
		printf("%d. Enter number: ",i+1);
		fflush(stdout);
		scanf("%f",&a[i]);
	}
	for(i=0;i<n;i++){
		avr += a[i];
	}
	avr/=n;
	fflush(stdin);
	printf("Average = %0.2f",avr);


}
void Find_Transpose_of_a_Matrix(){
	int r,c,i,j;

	puts("Enter rows and column of matrix:");
	fflush(stdout);
	scanf("%d %d",&r,&c);
	float a[r][c],b[c][r];

	puts("Enter elements of matrix:");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			fflush(stdin);
			printf("Enter elements a%d%d:",i+1,j+1);
			fflush(stdout);
			scanf("%f",&a[i][j]);
			b[j][i]=a[i][j];
		}
	}
	puts("Entered Matrix:");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			fflush(stdin);
			printf("%0.2f  ",a[i][j]);
		}
		printf("\n");
	}
	puts("Transpose of Matrix:");
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			fflush(stdin);
			printf("%0.2f  ",b[i][j]);
		}
		printf("\n");
	}

}
void Insert_an_element_in_an_Array(){
	int n,i;
	puts("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&n);
	float a[n],e;
	for(i=0;i<n;i++){

		fflush(stdout);
		scanf("%f ",&a[i]);
	}
	fflush(stdin);
	puts("Enter the element to be inserted : ");
	fflush(stdout);
	scanf("%f",&e);
	puts("Enter the location : ");
	fflush(stdout);
	scanf("%d",&i);
	a[i-1]=e;
	for(i=0;i<n;i++){

		fflush(stdin);
		printf("%0.2f ",a[i]);
	}
}
void Search_an_element_in_Array(){
	int n,i;
	puts("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&n);
	int a[n],e;
	for(i=0;i<n;i++){

		fflush(stdout);
		scanf("%d ",&a[i]);
	}
	fflush(stdin);
	printf("Enter the elements to be searched : ");
	fflush(stdout);
	scanf("%d",&e);

	for(i=0;i<n;i++){
		(a[i]== e)? printf("Number found at the location = %d",i+1): 0;

	}
}
void  Find_the_Frequency_of_Characters_in_a_String(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char text[100],c;
	int frq=0,i;
	printf("Enter a string:");
	gets(text);
	printf("Enter a character to find frequency: %s",text);
	scanf("%c",&c);
	for(i=0;i<=strlen(text);i++)
		(text[i]==c)?frq++:0;

	printf("Frequency of %c = %d",c,frq);
}
void Find_the_Length_of_a_String(){
	puts("Enter a string: ");
	char t[100];
	int i,count=0;
	fflush(stdout);
	scanf("%s",t);
	for(i=0 ;t[i]!='\0';i++){
		count++;
	}
	fflush(stdin);
	printf("Length of string: %d",count);
}
void Reverse_String_Without_Using_Library_Function(){
	puts("Enter a string: ");
	char t[100];
	int i;
	fflush(stdout);
	scanf("%s",t);
	for(i=0 ;t[i]!='\0';i++);
	fflush(stdin);
	printf("Reverse string is : ");
	for(i ;i>=0;i--){
		fflush(stdin);
		printf("%c",t[i]);
	}

}


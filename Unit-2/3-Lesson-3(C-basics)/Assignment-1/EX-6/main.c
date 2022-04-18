/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: youss
 */
#include<stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a,b,temp;
	printf("Enter value of a: ");
	scanf("%f",&a);
	printf("Enter value of b: ");
	scanf("%f",&b);
	/*SWAP a & b */
	temp=b;
	b=a;
	a=temp;

	printf("After swapping, value of a = %.3f\n",a);
	printf("After swapping, value of b = %.3f",b);

	return 0;
}


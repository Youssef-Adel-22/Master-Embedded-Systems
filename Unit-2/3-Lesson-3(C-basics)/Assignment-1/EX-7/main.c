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
	int a,b;
	printf("Enter value of a: ");
	scanf("%d",&a);
	printf("Enter value of b: ");
	scanf("%d",&b);
	/*SWAP a & b */
	a^=b;
	b^=a;
	a^=b;

	printf("After swapping, value of a = %d\n",a);
	printf("After swapping, value of b = %d",b);

	return 0;
}


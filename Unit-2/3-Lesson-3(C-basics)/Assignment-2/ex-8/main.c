/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: youss
 */

#include<stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a,b;
	char operator;
	while(1){

	printf("Enter operator either + or - or * or /: ");
	fflush(stdin);
	scanf("%c", &operator);
	fflush(stdout);
	printf("Enter two operands: ");
		scanf("%f %f", &a,&b);
	switch(operator){
	case '+':
		printf("%0.3f + %0.3f = %.3f\n",a,b,a+b);
		break;
	case '-':
		printf("%0.3f - %0.3f = %.3f\n",a,b,a-b);
		break;
	case '*':
		printf("%0.3f * %0.3f = %.3f\n",a,b,a*b);
		break;
	case '/':
		printf("%0.3f / %0.3f = %.3f\n",a,b,a/b);
		break;
	}
	}

	return 0;
}

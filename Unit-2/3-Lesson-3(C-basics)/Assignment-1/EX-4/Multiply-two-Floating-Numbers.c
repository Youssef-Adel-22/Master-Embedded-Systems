/*
 ============================================================================
 Name        : Multiply-two-Floating-Numbers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/* Solving I/O form console Problem*/
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a,b;
	printf("Enter two numbers: ");
	scanf("%f %f",&a,&b);
	printf("Product: %f", a*b);

	return EXIT_SUCCESS;
}

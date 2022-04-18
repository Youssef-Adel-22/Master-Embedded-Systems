/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: youss
 */
#include <stdio.h>
int main(){
	/* Solving I/O form console Problem*/
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int a,b;
	printf("Enter two integers: ");
	scanf("%d %d",&a,&b);
	fflush(stdin);
	printf("Sum: %d", a+b);


return 0;
}


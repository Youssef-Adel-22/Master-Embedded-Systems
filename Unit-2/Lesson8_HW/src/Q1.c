/*
 ============================================================================
 Name        : Lesson8_HW.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Q1_function(void) {
	int m =29;
	printf("Address of m : 0x%X  \nValue of m : %d",&m,m);

	int *ab=&m;
	printf("\nAddress of ab : 0x%X  \nContent of pointer ab : %d",ab,ab[0]);
	m=34;
	printf("\nAddress of ab : 0x%X  \nContent of pointer ab : %d",ab,*ab);
	*ab=7;
	printf("\nAddress of m : 0x%X  \nValue of m : %d",&m,m);

}

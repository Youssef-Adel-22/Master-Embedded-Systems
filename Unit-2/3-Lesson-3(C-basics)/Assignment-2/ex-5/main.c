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
	char c;
	while (1) {
		fflush(stdin);
		printf("Enter a character: ");
		scanf("%c", &c);
		printf("%c is %s.\n", c,(c >= 0x41 && c <= 0x5A) || (c >= 0x61 && c <= 0x7A) ?"an alphabet" : "not an alphabet");
	}
	return 0;
}

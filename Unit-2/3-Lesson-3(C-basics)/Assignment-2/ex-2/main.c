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
	char c;

		printf("\nEnter an alphabet: ");
		scanf("%c",&c);
		switch(c){
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'E':
		case 'e':
		case 'U':
		case 'u':
		case 'A':
		case 'a':
			printf("%c is a vowel",c);
			break;
		default:
			printf("%c is a constant",c);
			break;

	}

	return 0;
}


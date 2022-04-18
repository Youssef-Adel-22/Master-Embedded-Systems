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
	int n,i,sum=0;
		printf("Enter an integer: ");
		scanf("%d", &n);
		for(i=n;i>=1;i--){

			sum+=i;
		}
		printf("Sum= %d",sum);
	return 0;
}



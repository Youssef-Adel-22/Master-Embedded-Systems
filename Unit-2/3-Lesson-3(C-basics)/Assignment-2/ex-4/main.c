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
	float a;
	while(1){
		printf("\nEnter a number: ");
		scanf("%f",&a);
		if(a==0)
			printf("You entered zero.");
		else
			printf("%.2f is %s.",a,(a>0)?"positive":"negative");
	}
	return 0;
}

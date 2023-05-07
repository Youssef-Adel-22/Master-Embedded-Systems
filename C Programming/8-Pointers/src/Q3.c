/*
 * Q3.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Harby
 */

void Q3_function(){
	char str[100]={0};
	char *ptr =str;
	printf("Pointer : Print a string in reverse order : \n------------------------------------------------\n");
	printf("Input a string : ");
	while (*(ptr-1) !='\n'){
		scanf("%c",ptr);
		ptr++;
	}
	printf("\nReverse of the string is : ");
	while(ptr>= str){
		printf("%c",*ptr);
		ptr--;
	}
}

/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: youss
 */

#include <stdio.h>

int main(){
setvbuf(stdout,NULL,_IONBF,0);
setvbuf(stderr,NULL,_IONBF,0);
char c;
printf("Enter a character: ");
scanf("%c",&c);
printf("ASCII value of G = %d",c);


return 0;
}

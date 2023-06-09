/*
 * Q2.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Harby
 */


void Q2_function(){
	char alph[26],*ptr;
	int i,n;
	ptr =alph;
	for(i=0; i<26; i++){
		*ptr='A'+i;
		ptr++;
	}
	ptr =alph;
	for(int i=0; i<26; i++){
			printf("%c  ",*ptr);
			ptr++;
		}
}

/*
 * Q4.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Harby
 */


void Q4_function(){
	int arr[15],*ptr;
	int i,n;
	ptr =arr;
	printf("Input the number of elements to store in the array (max 15) :");
	scanf("%d",&n);

	for(i=0; i<n; i++){
		printf("element - %d :",i+1);
		scanf("%d",ptr);
		ptr++;
	}
	ptr--;
	for(i=n; i>0; i--){
		printf("element - %d :",i);
			printf("%d\n",*ptr);
			ptr--;
		}
}

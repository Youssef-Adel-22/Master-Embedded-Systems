#include<stdio.h>
void Revers_arr(int* arr,int n){
	int i,temp;
	for(i=0;i<n/2;i++){
		temp =arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1] =temp;
	}
	
}

void main(){
	int a[5]={1,2,3,4,5};
	int size = sizeof(a)/sizeof(a[0]);
	int i;
	
	Revers_arr(a,size);
	for(i=0 ; i<size ; i++){
		printf("%d ",a[i]);
		
	}
}
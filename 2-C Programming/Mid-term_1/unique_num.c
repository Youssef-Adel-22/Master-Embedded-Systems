#include<stdio.h>
int unique_num(int* arr, int n){
	int i,unique=0;
	for(i=0;i<n;i++){
		unique^=arr[i];
	}
	return unique;
	
}

void main(){
	int arr[]= {4,2,5,2,5,7,4};
	int size= sizeof(arr)/sizeof(arr[0]);
	printf("%d",unique_num(arr,size));
	
}
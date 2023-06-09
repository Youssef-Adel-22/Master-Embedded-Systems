#include<stdio.h>

int count_Ones( int num){
	int count=0;
	while(num!=0){
		num&=(num<<1);
		count++;
	}
	return count;
}
void main(){

	int num;
	scanf("%d",&num);
		
	printf("%d",count_Ones(num));
}
#include<stdio.h>
int sum_1_100(int num){
	static int sum;
	if (num <=100){
		sum=num+sum_1_100(num+1);
	}
	else
		return 0;
	return sum;
}

void main(){
	printf("%d",sum_1_100(1));
	
}
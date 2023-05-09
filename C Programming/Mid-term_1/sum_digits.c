#include<stdio.h>
int sum_digits(int num){
	static int sum=0;
	int rem;
	if(num!=0){
		rem=num%10;
		sum+=rem;
		sum_digits(num/10);
	}
	else 
		return 0;
	
	return sum;
	
}
void main(){
	int num;
	scanf("%d",&num);
	
	printf("%d",sum_digits(num));
	
}
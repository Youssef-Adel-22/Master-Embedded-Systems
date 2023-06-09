#include<stdio.h>

void revers_digit(int num){

	while(num!=0){
		printf("%d", (num%10));
		num/=10;
	}

}

void main(){
	int num;
	scanf("%d",&num);
	revers_digit(num);
}
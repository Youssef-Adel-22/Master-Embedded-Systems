#include<stdio.h>

void prime_numbers(int a, int b){
	int i;
	for(i=a ; i<=b ; i++){
		if(i==1)
			continue;
		if((i==2 || i==3 || i==5 || i==7) || (i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 )){
			printf("%d ",i);
		}	
	}
}

void main(){
	int n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);
	prime_numbers(n1, n2);

}
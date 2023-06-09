#include<stdio.h>
#include<math.h>
double sqroot(int num){

	return (sqrt(num));

}

void main(){
	int num;
	scanf("%d",&num);
	printf("%0.3lf",sqroot(num));
}
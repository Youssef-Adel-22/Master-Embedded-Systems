#include<stdio.h>
#include<math.h>
int count_Ones( int num){
	int count=0;
	double LOG = (log(num)/log(2)) ;
	if(LOG -(int)LOG == 0)
		return 1;
	while(num!=0){
		if((num&1) ==1)
			count++;
		num>>=1;
	}
	return count;
}
void main(){

	int num;
	scanf("%d",&num);
		
	printf("%d",count_Ones(num));
}

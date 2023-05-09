#include<stdio.h>
#include<string.h>
void R_W_Arr(char* arr, int n){
	int i=0,j=0,count=0,s,E;
	char n_arr[n];
	for(i=n-1;i>=0;i--){
		if(arr[i] != ' ' && i >0){
			count ++;
		}
		else{
			
			s=i+1;
			E=j+count-1;
			for(j; j<=E;j++){
				n_arr[j]= arr[s++];
			printf("\n%s",n_arr);
			}
			n_arr[j++]=' ';
			count=0;
			i--;
		}
	}
	printf("%s",n_arr);
	
}
void main(){
	char arr[1000]="";
		gets(arr);
		int size= strlen(arr);
		R_W_Arr(arr, size);
	//printf("%s",R_W_Arr(arr, size));
}
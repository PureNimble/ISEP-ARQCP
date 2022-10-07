#include <stdio.h>


//Data
int n1,n2,soma;
//Sum function	
int sum(int a, int b){
	
	int c = 0;
	c = a + b;
		
return c;	

}

	int main(void){
		
		printf("Enter the value of a:");
		scanf("%d", &n1);
		printf("\nEnter the value of b:");
		scanf("%d", &n2);
		soma = sum(n1, n2);
		
		while(soma>=10){
			printf("\nThe sum of two integers need to be less than 10!!");
			printf("\nEnter the value of a:");
			scanf("%d", &n1);
			printf("\nEnter the value of b:");
			scanf("%d", &n2);
			soma = sum(n1, n2);
		}  
		return 0;   
	}  

#include <stdio.h>
#include "asm.h"


int main(void)
{	
	
	printf("----Calculator----\n");
	printf("Which operation you want to do?\n");
	printf("1-Sum\n");
	printf("2-Subtraction\n");
	printf("3-Multiplication\n");
	printf("4-Divison\n");
	printf("5-Modulus\n");
	printf("6-Power of 2\n");
	printf("7-Power of 3\n");
	scanf("%i",&i);
	switch(i)
	{
		case 1:
		printf("Number of x:\n");
		scanf("%d",&x);
		printf("Number of y:\n");
		scanf("%d",&y);
		ret = sum();
		break;
		
		case 2:
		printf("Number of x:\n");
		scanf("%d",&x);
		printf("Number of y:\n");
		scanf("%d",&y);
		ret = subtraction();
		break;
		
		case 3:
		printf("Number of x:\n");
		scanf("%d",&x);
		printf("Number of y:\n");
		scanf("%d",&y);
		ret = multiplication();
		break;
		
		case 4:
		printf("Dividend:\n");
		scanf("%d",&x);
		printf("Divisor:\n");
		scanf("%d",&y);
		ret = division();
		break;
		
		case 5:
		printf("Number of x:\n");
		scanf("%d",&x);
		ret = modulus();
		break;
		
		case 6:
		printf("Number of x:\n");
		scanf("%d",&x);
		ret = power2();
		break;
		
		case 7:
		printf("Number of x:\n");
		scanf("%d",&x);
		ret = power3();
		break;
		
		default:
		printf("Error!! \n");
	}
	if(i > 0 && i < 8)
	{
		printf("Value = %d\n",ret);
	}
	return 0;
}

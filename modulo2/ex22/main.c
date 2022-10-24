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
	printf("6-Powers of 2 and 3\n");
	scanf("%i",&i);
	if(i == 1)
	{
		printf("Number of x:\n");
		scanf("%d",&x);
		printf("Number of y:\n");
		scanf("%d",&y);
		ret = sum();
	}	
	if(i == 2)
	{
		printf("Number of x:\n");
		scanf("%d",&x);
		printf("Number of y:\n");
		scanf("%d",&y);
		ret = subtraction();
	}
	if(i == 3)
	{
		printf("Number of x:\n");
		scanf("%d",&x);
		printf("Number of y:\n");
		scanf("%d",&y);
		ret = multiplication();
	}
	if(i == 4)
	{
		printf("Dividend:\n");
		scanf("%d",&x);
		printf("Divisor:\n");
		scanf("%d",&y);
		ret = division();
	}
	if(i == 5)
	{
		printf("Number of x:\n");
		scanf("%d",&x);
		ret = modulus();
	}
	if(i == 6)
	{
		printf("Number of x:\n");
		scanf("%d",&x);
		ret = power2();
	}
	if(i == 7)
	{
		printf("Number of x:\n");
		scanf("%d",&x);
		ret = power3();
	}
	printf("Value = %d\n",ret);
	return 0;
}

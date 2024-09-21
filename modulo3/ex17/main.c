#include <stdio.h>
#include "asm.h"

short src[]={5,4,3,2,1};
short *ptrsrc = vec;
int num = 5;

int main()
{
	for (int i= 0;i<num;i++)
	{printf("%d, ",vec[i]);}
	
	array_sort();
	printf("\n");
	
	for (int i= 0;i<num;i++)
	{printf("%d, ",vec[i]);}
	
	printf("\n");
	return 0;
}

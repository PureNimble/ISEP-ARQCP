#include <stdio.h>
#include "asm.h"

short src[]={5,4,3,2,1};
short dest[];
short *ptrsrc = src;
short *ptrdest = dest;

int num = 5;

int main()
{
	sort_without_reps();
	
	for (int i= 0;i<num;i++)
	{printf("%d, ",src[i]);}
	
	printf("\n");
	
	for (int i= 0;i<num;i++)
	{printf("%d, ",dest[i]);}
	
	printf("\n");
	return 0;
}

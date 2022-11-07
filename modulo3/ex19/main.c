#include <stdio.h>
#include "asm.h"

char grades[]={0,1,2,3,4};
          // 0 1 2 3 4 5  6 7 8 9 0  1 2 3 4 5  6 7 8 9 0
char freq[]={0,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
char *ptrgrades = grades;
char *ptrfreq = freq;
int num = 5;

int main()
{
	frequencies();
	printf("0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 \n");
	for(int i =0;i<21;i++)
	{printf("%d ",freq[i]);}
	
	printf("\n");
	return 0;
}

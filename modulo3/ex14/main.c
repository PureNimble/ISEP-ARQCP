#include <stdio.h>
#include "asm.h"

int x = 1;
int vec[]={1,2,3,3,3,1};
int *ptrvec = vec;
int num = 3;
int main()
{
	int y = exists();
	if(y==1)
	{printf("The number is duplicate\n");}
	else
	{printf("The number isn't duplicate\n");}
	int z = vec_diff();
	printf("Number of non duplicate numbers = %i \n",z);
	return 0;
}

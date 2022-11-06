#include <stdio.h>
#include "asm.h"

int x = 5;
int vec[]={1,2,3,4,5,5,8};
int *ptrvec = vec;
int num = 7;
int main()
{
	int y = exists();
	if(y==1)
	{printf("The number is duplicate\n");}
	else
	{printf("The number isn't duplicate\n");}
	return 0;
}

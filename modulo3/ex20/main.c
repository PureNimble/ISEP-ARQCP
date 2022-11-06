#include <stdio.h>
#include "asm.h"

int vec[]={1,2,3,4,5}
int *ptrvec = vec;
int num = 5;

int main()
{
	int x = count_max();
	printf("satisfy the condition %i times\n",x);
	return 0;
}

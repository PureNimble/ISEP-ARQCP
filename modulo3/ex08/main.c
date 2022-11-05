#include <stdio.h>
#include "asm.h"

long even = 2;
long vec[] = {1,2,3,4,5,6};
long *ptrvec = vec;
int num = 6;
int main()
{	
	long x = test_even();
	if(x==1)
	{printf("The number is even\n");}
	else
	{printf("The number is odd\n");}
	
	long y = vec_sum_even();
	printf("Sum of the even numbers= %ld \n",y);
}

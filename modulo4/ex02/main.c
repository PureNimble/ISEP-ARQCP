#include <stdio.h>
#include "asm.h"

int main()
{
	int n = 0;
	long y = sum_n2(n);
	printf("Sum of the squares of integers 1 to %d = %ld \n",n,y);
	return 0;
}

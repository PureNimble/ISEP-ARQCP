#include <stdio.h>
#include "asm.h"


long vec[]={1,2,3};
long *ptrvec = vec;
int num = 3;
int main()
{
	int x = sum_first_byte();

	printf("Sum of the 1 byte of the numbers = %i \n",x);
	
	return 0;
}

#include <stdio.h>
#include "asm.h"

int main()
{
	int num1 = 0;
	int num2 = 1;
	int vec;
	int *smaller = &vec;

	
	int y = sum_smaller(num1,num2,&vec);
	printf("The sum of %d + %d = %d\n",num1,num2,y);

	printf("And %d is the smaller\n",*smaller);
	return 0;
}

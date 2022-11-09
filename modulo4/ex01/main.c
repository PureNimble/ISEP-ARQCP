#include <stdio.h>
#include "asm.h"

int main()
{
	int x = 5;
	long y = cube(x);
	printf("The cube of %ld = %ld \n",x,y);
	return 0;
}

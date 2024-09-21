#include <stdio.h>
#include "asm.h"

int main()
{
	int v1 = 1;
	int v2 = 2;

	int y = inc_and_square(&v1,v2);
	printf("v1 + 1 = %d \n",v1);

	printf("Square of v2 = %d\n",y);
	return 0;
}

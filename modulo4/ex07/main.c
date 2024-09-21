#include <stdio.h>
#include "asm.h"

int main()
{
	char vec[10] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	int y = count_odd(&vec,n);
	printf("%i\n", y);
	return 0;
}

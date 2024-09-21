#include <stdio.h>
#include "asm.h"

int main()
{
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	
	
	long y = greatest(a,b,c,d);
	printf("(%d,%d,%d,%d,%d) %d is the greatest\n",a,b,c,d,y);
	return 0;
}

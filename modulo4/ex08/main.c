#include <stdio.h>
#include "asm.h"

int main()
{

	int a = 5;
	int b = 10;
	int c = 5;

	int y = calc(a,&b,c);
	printf("Return = %d",y);
	return 0;
}

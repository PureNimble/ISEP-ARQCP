#include <stdio.h>
#include "asm.h"

short x = 0;
int main(void)
{
	printf("Value of x:");
	scanf("%hu",&x);
	int ret = swapBytes();
	printf("Value of x after the byte swap: %hu\n",ret);
	return 0;
}

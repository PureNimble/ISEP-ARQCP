#include <stdio.h>
#include "asm.h"

short s = 0;
int main(void)
{
	printf("Value of s:");
	scanf("%hu",&s);
	int ret = swapBytes();
	printf("Value of s after the byte swap: %hu\n",ret);
	return 0;
}

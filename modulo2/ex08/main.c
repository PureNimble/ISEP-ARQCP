#include <stdio.h>
#include "asm.h"

int main(void)
{
	short ret = crossSumBytes();

	printf("Value of s after the byte swap: %hd\n",ret);
	return 0;
}

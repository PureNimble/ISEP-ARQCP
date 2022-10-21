#include <stdio.h>
#include "asm.h"

int main(void)
{
	printf("Valor s1:");
	scanf(" %hd ",&s1);
	
	printf("Valor s2:");
	scanf(" %hd ",&s2);
	
	short ret = crossSumBytes();
	
	printf("Value of s after the byte swap: %hd\n",ret);
	return 0;
}

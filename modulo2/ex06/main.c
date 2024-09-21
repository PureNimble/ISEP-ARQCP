#include <stdio.h>
#include "asm.h"

int main(void)
{
	printf("Valor byte1:");
	scanf(" %c ",&byte1);
	
	printf("Valor byte2:");
	scanf(" %c ",&byte2);
	
	short ret = concatBytes();
	
	printf("Value of s after the byte swap: %hu\n",ret);
	return 0;
}

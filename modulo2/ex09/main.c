#include <stdio.h>
#include "asm.h"

int A = 0;
short B = 0;
char C = 0;
char D = 0;

int main(void)
{
	printf("Valor A:");
	scanf("%i",&A);
	printf("Valor B:");
	scanf("%hu",&B);
	printf("Valor C:");
	scanf(" %c",&C);
	printf("Valor D:");
	scanf(" %c",&D);
	long ret = sum_and_subtract();
	printf("Valor = %ld\n",ret);
	return 0;
}

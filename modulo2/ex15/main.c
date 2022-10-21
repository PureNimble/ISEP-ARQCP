#include <stdio.h>
#include "asm.h"

int A = 0;
int B = 0;
int C = 0;
int D = 0;

int main(void)
{
	printf("Valor A:");
	scanf("%i",&A);
	printf("Valor B:");
	scanf("%i",&B);
	printf("Valor C:");
	scanf("%i",&C);
	printf("Valor D:");
	scanf("%i",&D);
	int ret = compute();
	printf("Valor = %d\n",ret);
	return 0;
}

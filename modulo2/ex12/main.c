#include <stdio.h>
#include "asm.h"

int A = 0;
int B = 0;

int main(void)
{
	printf("Valor A:");
	scanf("%i",&A);
	printf("Valor B:");
	scanf("%i",&B);
	char ret = isMultiple();
	printf("Valor = %i\n",ret);
	return 0;
}

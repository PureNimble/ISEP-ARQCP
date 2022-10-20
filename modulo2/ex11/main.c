#include <stdio.h>
#include "asm.h"

int op1 = 0;
int op2 = 0;

int main(void)
{
	printf("Valor A:");
	scanf("%i",&op1);
	printf("Valor B:");
	scanf("%i",&op2);
	char ret = test_flags();
	printf("Valor = %i\n",ret);
	return 0;
}

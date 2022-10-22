#include <stdio.h>
#include "asm.h"

int num;

int main(void)
{
	printf("Número:");
	scanf("%i",&num);
	char ret = check_num();
	printf("Valor = %i\n",ret);
	return 0;
}

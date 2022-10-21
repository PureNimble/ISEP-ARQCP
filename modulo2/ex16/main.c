#include <stdio.h>
#include "asm.h"



int main(void)
{
	printf("Valor de num:");
	scanf("%ld",&num);
	
	long ret = steps();
	printf("Valor = %ld\n",ret);
	return 0;
}

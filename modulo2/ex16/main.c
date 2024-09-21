#include <stdio.h>
#include "asm.h"



int main(void)
{
	printf("Valor de num:");
	scanf("%ld",&num);
	
	int ret = steps();
	printf("Valor = %d\n",ret);
	return 0;
}

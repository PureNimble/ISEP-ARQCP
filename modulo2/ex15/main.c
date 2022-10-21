#include <stdio.h>
#include "asm.h"


int main(void)
{
	printf("Valor A:");
	scanf("%d",&A);
	printf("Valor B:");
	scanf("%d",&B);
	printf("Valor C:");
	scanf("%d",&C);
	printf("Valor D:");
	scanf("%d",&D);
	int ret = compute();
	printf("Valor = %d\n",ret);
	return 0;
}

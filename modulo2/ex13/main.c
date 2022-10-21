#include <stdio.h>
#include "asm.h"

int length1 = 0;
int length2 = 0;
int height = 0;

int main(void)
{
	printf("Valor Length1:");
	scanf("%i",&length1);
	printf("Valor Length2:");
	scanf("%i",&length2);
	printf("Valor Height:");
	scanf("%i",&height);
	int ret = getArea();
	printf("Valor = %i\n",ret);
	return 0;
}

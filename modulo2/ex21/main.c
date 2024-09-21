#include <stdio.h>
#include "asm.h"

short code = 0;
short currentSalary = 0;

int main(void)
{
	printf("Code:");
	scanf("%hu",&code);
	printf("Current salary:");
	scanf("%hu",&currentSalary);
	int ret = new_salary();
	printf("Valor = %i\n",ret);
	return 0;
}

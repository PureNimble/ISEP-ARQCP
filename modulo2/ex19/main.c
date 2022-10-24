#include <stdio.h>
#include "asm.h"

char current = 0;
char desired = 0;

int main(void)
{
	printf("Current:");
	scanf("%hhd",&current);
	printf("Desired:");
	scanf("%hhd",&desired);
	int ret = needed_time();
	printf("Valor = %d\n",ret);
	return 0;
}

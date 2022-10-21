#include <stdio.h>
#include "asm.h"

char current = 4;
char desired = 3;

int main(void)
{
	printf("Current:");
	scanf(" %c",&current);
	printf("Desired:");
	scanf(" %c",&desired);
	int ret = needed_time();
	printf("Valor = %d\n",ret);
	return 0;
}

#include <stdio.h>
#include "asm.h"

char vec[] = "777777777";
char *ptr1 = vec;
int main(void)
{

	int ret = seven_count();
	printf("Numero de 7s = %d\n",ret);
	return 0;
}

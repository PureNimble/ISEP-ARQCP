#include <stdio.h>
#include "asm.h"

char vec[] = "701020370567";
int main(void)
{

	int ret = seven_count();
	printf("Numero de 7s = %d\n",ret);
	return 0;
}

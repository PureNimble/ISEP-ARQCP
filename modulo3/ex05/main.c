#include <stdio.h>
#include "asm.h"


int main()
{
	long i = vec_sum();
	printf("i=%ld\n",i);
	
	return 0;
}

#include <stdio.h>
#include "asm.h"

int main()
{
	int value = vec_sum();
	printf("%i\n",value);
	int average = vec_avg();
	printf("%i\n",average);
	return 0;
}

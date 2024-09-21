#include <stdio.h>
#include "asm.h"


int main()
{
	unsigned char count = vec_zero();
	printf("%i\n", count);
	for(int i = 0; i<num; i++){
		printf("%i ", vec[i]);
	}
	
	return 0;
}

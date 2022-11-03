#include <stdio.h>
#include "asm.h"

int ptrvec[num] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void main(void)
{
	vec_add_two();
	for(int i = 0; i < num; i++){
		printf(" %i", ptrvec[i]);
	}
	printf("\n");
}

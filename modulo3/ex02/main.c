#include <stdio.h>
#include "asm.h"

char ptr1[50] = "O Porto ganhou ao benfica mais uma vez";
char ptr2[50];

void main(void)
{
	str_copy_porto();
	printf("%s\n",ptr1);
	printf("%s\n",ptr2);
}

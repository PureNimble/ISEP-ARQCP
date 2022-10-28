#include <stdio.h>
#include "asm.h"

char ptr1[50] = "O POrto ganhoU ao benfica mais uma vez";
char ptr2[50];

void main(void)
{
	str_copy_porto2();
	printf("%s\n",ptr1);
	printf("%s\n",ptr2);
}

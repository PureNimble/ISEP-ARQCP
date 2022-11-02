#include <stdio.h>
#include "asm.h"

char string1[50] = "O Porto ganhou ao benfica mais uma vez";
char string2[50];
char *ptr1 = string1;
char *ptr2 = string2;
int main()
{
	str_copy_porto();
	printf("%s\n",ptr1);
	printf("%s\n",ptr2);
	
	return 0;
}

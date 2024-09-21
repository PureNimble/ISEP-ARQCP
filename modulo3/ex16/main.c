#include <stdio.h>
#include "asm.h"

int num = 50;
char string1[50] = "O Porto ganhou ao Benfica mais uma vez";
char string2[50] = "O Porto ganhou ao Sporting mais uma vez";
char *ptr1 = string1;
char *ptr2 = string2;

int main()
{
	swap();
	printf("%s\n",string1);
	printf("%s\n",string2);
	
	return 0;
}

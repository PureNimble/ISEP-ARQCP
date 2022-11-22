#include <stdio.h>
#include "asm.h"

int main()
{
	char string1[]="";
	char string2[]="";
	char *a = string1;
	char *b = string2;

	int y = distance(a,b);
	if(y == 1)
	{printf("The strings are equal\n");}
	else{printf("The strings are different\n");}
	return 0;
}

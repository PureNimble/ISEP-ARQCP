#include <stdio.h>
#include "asm.h"


int main()
{	
	encrypt();
	printf("%s\n",string1);
	int value = decrypt();
	printf("%s\n",string1);
	printf("%i\n", value);
	return 0;
}

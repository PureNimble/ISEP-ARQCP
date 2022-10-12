#include <stdio.h>
#include "power_ref.h"


int main()
{	
	int a;
	int b;
	printf("Valor 1:");
    scanf("%i",&a);

    printf("Valor 2:");
    scanf("%i",&b);
   
    power_ref(&a,b);

    printf("a = %i",a);
    return 0;
}


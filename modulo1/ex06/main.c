#include <stdio.h>
#include "power_ref.h"


int main()
{	
	int a;
	int b;
	printf("Valor x:");
    scanf("%i",&a);

    printf("Valor y:");
    scanf("%i",&b);
   
    power_ref(&a,b);

    printf("a = %i\n",a);
    return 0;
}


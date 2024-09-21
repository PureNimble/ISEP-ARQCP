#include <stdio.h>
#include "power_ref.h"


int main()
{	//Declaration of the variables
		int a;
		int b;
	//Print and scan of x
		printf("Valor x:");
		scanf("%i",&a);
	//Print and scan of y
		printf("Valor y:");
		scanf("%i",&b);
	//Use the function power_ref
		power_ref(&a,b);
	//Final print
		printf("a = %i\n",a);
    return 0;
}


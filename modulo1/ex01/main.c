#include <stdio.h>
#include "print.h"
int main(){
	//Declaring the variables
	int x = 5; 
	int *xPtr = &x;
	float y = *xPtr + 3;
	int vec[] = {10, 11, 12, 13};
	

	//print of the value and adresses of the variables
	printf("The value of x = %i \n",x);
	printf("The value of y = %f \n",y);
	printf("The adress of x = %p \n",&x);
	printf("The adress of xPtr = %p \n",&xPtr);
	printf("The value pointed by xPtr = %i \n",*xPtr);
	printf("The adress of vec = %p \n",&vec);
	printValue(vec);
	printAdress(vec);
	
	return 0;
}

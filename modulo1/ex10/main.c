#include <stdio.h>
#include "odd_sum.h"

int main(){
	int vec[] = {5,1,4,7,8};
	
	printf("Array: ");
	for (int i = 0; i < vec[0]; i++) {     
        printf("%d ", vec[i]);     
    }   
	printf("\nsum of odd numbers in the array: %d \n", odd_sum(vec));
}

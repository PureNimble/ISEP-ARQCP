#include <stdio.h>
#include "odd_sum.h"

int main(){
	//Declaration of the size
		int size;
	//Print and scan of the size
		printf("Enter the size of the array: ");
		scanf("%d",&size);
	//Declaration of the array
		int vec[size];
		vec[0] = size;
	// Scan the elemets
		for (int i = 1; i < size; i++){
			printf("Enter the elemetns of the array: ");
			scanf("%d",&vec[i]);
		}
	printf("Array: ");
	for (int i = 0; i < vec[0]; i++) {     
        printf("%d ", vec[i]);     
    }   
	printf("\nsum of odd numbers in the array: %d \n", odd_sum(vec));
}

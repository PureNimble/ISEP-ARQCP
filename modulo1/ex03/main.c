#include <stdio.h>
#include "sum_even.h"
int main()
{
	
	//Declaration of variables
	
		int size;

    //Print and scan size of array
		printf("Enter the size of the array: ");
		scanf("%i",&size);
		printf("\n");
    //Declaration of the array
		int arr[size];
	
	//Scan the elements of the array
		for(int i=0; i<size; i++){
				printf("Enter the Array elements: ");
				scanf("%i",&arr[i]);
		}
    //Use of the function sum_even
		int evenSum = sum_even(arr, size);
		
    //Final print of the return
		printf("\nThe sum of even numbers are: %i",evenSum);
		printf("\nThe address of the array is: %p \n", arr);
    
    return 0;
}


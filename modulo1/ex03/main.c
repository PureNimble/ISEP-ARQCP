#include <stdio.h>
#include "sum_even.h"
int main()
{
	
	
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%i",&size);
    
    int arr[size];
    
    for(int i=0; i<size; i++){
			printf("Enter the Array elements: ");
            scanf("%i",&arr[i]);
    }
    sum_even(arr, size);
    
    
    return 0;
}


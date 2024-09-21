#include <stdio.h>
#include "array_sort1.h"
int main()
{	
	//Declaration of variables
		int size;
    //Print and scan of the size
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    //Declaration of the array
    int arr[size];
	//Print and scan of the array
		for(int i=0; i<size; i++){
			printf("Enter the 1º Array elements: ");
				scanf("%d",&arr[i]);
		}
    //Use of the function
		array_sort1(arr,size);
    //Final Print
		for ( int i=0;i<size;i++) {
			printf("Numbers in order: %i \n", arr[i]);
		}
		return 0;
}


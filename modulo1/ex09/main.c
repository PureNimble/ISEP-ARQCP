#include <stdio.h>
#include "sort_without_reps.h"

int main()
{
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    
    int arr[size];

    for(int i=0; i<size; i++){
        printf("Enter the 1º Array elements: ");
            scanf("%d",&arr[i]);
    }
    int ary[size];
    
    int counter = sort_without_reps(arr,size,ary);
    
    for ( int i=0;i<counter;i++) {
        printf("Value of 2º array: %i \n", ary[i]);
    }
    printf("Number of elements: %i \n", counter);
}

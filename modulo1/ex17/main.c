#include <stdio.h>
#include "swap.h"
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
    
     ;
    for(int i=0; i<size; i++){
        printf("Enter the 2º Array elements: ");
            scanf("%d",&ary[i]);
    }
    swap(arr,ary,size);
    
    return 0;
}


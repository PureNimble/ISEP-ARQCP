#include <stdio.h>

int main()
{
    int* vec1;
    int* vec2;
    int size;
    int i;
    int j;
    int k;
    int a;
    
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    
    int arr[size];

    for(i=0; i<size; i++){
        printf("Enter the 1º Array elements: ");
            scanf("%d",&arr[i]);
    }
    int ary[size];
    
    vec1 = arr;
    vec2 = ary;
    for(i=0;i<size;i++){
        vec2[i] = vec1[i];
    }
    for(i=0;i<size;i++){
        for(j = i+1; j < size; j++){
            if(vec2[i] == vec2[j]){
                for(k = j; k <size; k++){
                    vec2[k] = vec2[k+1];
                }
                j--;
                size--;
            }
        }
    }
    for (i = 0; i < size; ++i) {
        for (j = i + 1; j < size; ++j)
        {
            if (vec2[i] > vec2[j]) 
            {
                a =  vec2[i];
                vec2[i] = vec2[j];
                vec2[j] = a;
            }
        }
     }
    for (i=0;i<size;i++) {
        printf("Valor do 2º array: %i \n", vec2[i]);
    }
}

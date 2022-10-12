#include <stdio.h>
//funcao swap
void swap(int* vec1, int* vec2, int size)
{
	int t = 0;
    for (int i=0;i<size;i++) {
        t=vec2[i];
        vec2[i]=vec1[i];
        vec1[i]=t;
    }
     for (int i=0;i<size;i++) {
        printf("Valor do 1º array: %i \n", vec1[i]);
     }
     for (int i=0;i<size;i++) {
        printf("Valor do 2º array: %i \n", vec2[i]);
     }
	
	
}

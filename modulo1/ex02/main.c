#include <stdio.h>
#include "copy_vec.h"


int main(){
        
        int n;
        printf("\nQual o tamanho do array? ");
        scanf("%i", &n);
        int vec1[n];
        int vec2[n];
        for(int i = 0; i<n; i++){
                printf("\nQual o inteiro? ");
                scanf("%i", &vec1[i]);
                }
        for(int i = 0; i<n; i++){
                printf("\nValor do elemento antes da cópia: %i ", vec2[i]);
                }
        copy_vec(vec1, vec2, n);
        for(int i = 0; i<n; i++){
                printf("\nValor do elemento depois da cópia: %i ", vec2[i]);
                }
        return 0;
}

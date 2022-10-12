#include <stdio.h>

int main(void){
    
    int n;
    printf("\nQual o tamanho do array? ");
    scanf("%i", &n);
    int vec1[n];
    for(int i = 0; i<n; i++){
        printf("\nQual o inteiro? ");
        scanf("%i", &vec1[i]);
        }
    int vec2[n];
    for (int i = 0; i<n; i++){

        vec2[i] = vec1[i];
        printf("\nValor do elemento: %i ", vec2[i]);

        }
    return 0;
}

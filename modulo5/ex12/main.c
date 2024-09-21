#include <stdio.h>
#include "new_matrix.h"
#include "fill_matrix.h"
#include "find_matrix.h"

int main(){
    int nLinhas = 3;
    int nColunas = 3;
    //invoca a funçao e imprime o endereço da matrix
    int ** matrix = new_matrix(nLinhas, nColunas);
    printf("Address of matrix = %p\n", (*matrix));

    //enche a matrix
    fill_matrix(matrix, nLinhas, nColunas);

    //Imprime a matriz
    printf("\nMatriz m:\n");
    int i, j;
    for (i = 0; i < nLinhas; i++){
        for(j = 0; j < nColunas; j++){
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    
    //Declara o número a ser procurado e verifica se existe na matriz. Imprime o resultado
    int num = 9;
    int resultado = find_matrix(matrix, nLinhas, nColunas, num);
    printf("Resultado: %d (1 encontrou, 0 não encontrou)\n", resultado);

    return 0;

}
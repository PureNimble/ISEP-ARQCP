#include <stdio.h>
#include "asm.h"
#include "new_matrix.h"

int main(){
//iniciamos a matriz
int ** matrix = new_matrix(2, 2);
int ** copy = matrix;
int i;
int j;
//preenche a matriz com 1
for(i = 0; i < 2; i++){
    int * ptr = (*copy);
    for(j = 0; j < 2; j++){
        (*ptr) = 1;
        ptr++;
    }
    copy++;
}
//invoca a funçao e imprime o resultado
int odds = count_odd_matrix(matrix, 2 ,2);
printf("Odds = %d", odds);



    return 0;
}
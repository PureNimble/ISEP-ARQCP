#include <stdlib.h>
#include <stdio.h>
int push(int * stack, int x, int currentsize){
    printf("-------------------Push de %d-------------------\n", x);
    int * copy = stack; //Usamos um apontador copia para o caso de o realloc nao for bem sucedido
    copy = (int *) realloc(stack, (currentsize + 1) * sizeof(int)); // Inserimos mais 4 bytes (um inteiro) ao bloco apontado por stack.
    if(copy != NULL){
        stack = copy; // Caso o realloc resulte, o endereço da stack atualiza para o novo (pode ficar igual)
        
        copy += currentsize; // Vamos ao inicio do ultimo elemento do bloco (stack)
        currentsize++; // Incrementamos o tamanho
        (*copy) = x; // O conteudo ultimo elemento da stack ´atualizado para o valor passado por parametro
    }
    return currentsize;
}
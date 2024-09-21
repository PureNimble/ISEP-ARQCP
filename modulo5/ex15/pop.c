#include <stdlib.h>
#include <stdio.h>
int pop(int * stack, int currentsize){
    printf("-------------------Pop do ultimo valor inserido-------------------\n");
    stack = (int *) realloc(stack, (currentsize - 1) * sizeof(int)); // Usamos realloc para retirar 4 bytes a stack. O endereço fica o mesmo
    currentsize--; // Decrementamos o tamanho da stack
    return currentsize;
}
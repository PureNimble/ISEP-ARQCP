#include <stdio.h>
#include "pop.h"
#include "push.h"
#include <stdlib.h>

int main(){
int i;
int currentsize = 1;
//Iniciamos a stack com o 1º elemento a 0.
int * stack = (int *) calloc(1, sizeof(int));

//Nos proximos blocos, cada um faz um push de um valor e imprime a stack inteira
int * ptr = stack;
printf("Current size = %d\n", currentsize);
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");


currentsize = push(stack, 50, currentsize);
printf("Current size = %d\n", currentsize);
ptr = stack;
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");


currentsize = push(stack, 100, currentsize);
printf("Current size = %d\n", currentsize);
ptr = stack;
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");


currentsize = push(stack, 150, currentsize);
printf("Current size = %d\n", currentsize);
ptr = stack;
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");

//Os proximos blocos dão pop a stack e imprimem a stack toda
currentsize = pop(stack, currentsize);
printf("Current size = %d\n", currentsize);
ptr = stack;
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");

currentsize = pop(stack, currentsize);
printf("Current size = %d\n", currentsize);
ptr = stack;
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");

currentsize = pop(stack, currentsize);
printf("Current size = %d\n", currentsize);
ptr = stack;
for(i = 0; i < currentsize; i++){
    printf("Stack[%d] = %d    ", i, *ptr);
    ptr++;
}
printf("\n\n\n");

    return 0;
}
#include <stdio.h>
#include "asm.h"

int main(){


    structA sa;
    structA * ptra = &sa;
    ptra->x = 1;
    ptra->y = 1000;

    //iniciamos os dados
    structB sb;
    structB * ptrb = &sb;
    ptrb->a = sa;
    ptrb->b = ptra;
    ptrb->c = 12;
    ptrb->e[0] = 1;
    ptrb->e[1] = 1;
    ptrb->e[2] = 1;
    ptrb->x = 2000;
    ptrb->y = 3000;
    ptrb->z = 5;

    // invoca as funçoes e imprime os resultados
    short f1 = fun1(ptrb);
    short f2 = fun2(ptrb);
    short * f3 = fun3(ptrb);
    short f4 = fun4(ptrb);
    printf("fun1 ---> s->a.x = %d\n", f1);
    printf("fun2 ---> s->z = %d\n", f2);
    printf("fun3 ---> &s->z = %p\n", f3);
    printf("fun4 ---> s->b->x = %d\n", f4);

    return 0;
}
#include <stdio.h>
#include "new_str.h"

int main(){
    //String que vai ser colocada no resultado
    char str[80] = "engenharia";
    //Coloca a string em resultado, ocupando apenas o espaço necessário
    char *resultado = new_str(str);
    //Imprime a str
    printf("New Str: %s\n", resultado);
    return 0;
}
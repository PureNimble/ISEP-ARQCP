#include <stdio.h>


int main()
{
    char str[50];
    char c[10];
    int vec[50];
    char* initial_addr;
    int i;
    int n = 0; 
    
    
    printf("Escreva uma frase: ");
    fgets(str, 50, stdin);
    
    for(int i = 0; i < 50; i++) {
        if(str[i] >= 65 + 32 && str[i] <= 90 + 32) {
            str[i] = str[i] - 32;
        }
    }
    printf("Que letra deseja procurar?: ");
    scanf("%s", c);
    
    for(int i = 0; i < 50; i++) {
        if(c[i] >= 65 + 32 && c[i] <= 90 + 32) {
            c[i] = c[i] - 32;
        }
    }
    
    initial_addr = str;
    
    for(i = 0; (str[i] = '\0'); i++){
        n++;
    }
    int contador=0;

    while (i < n) {
        if(initial_addr[i] == c[0]){
            vec[contador] = i;
            contador++;
        }
        ++i;
    }
    
    printf("%s", str);
    printf("%s\n", c);
    printf("contador:%i\n", contador);
    for(i = 0; i<contador;i++){
        printf("%i\n", vec[i]);
    }
    return 0;
}

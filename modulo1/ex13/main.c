#include <stdio.h>
#include "where_is.h"
int main()
{
	
    char str[50];
    char c;
    int vec[50];
  
    printf("Escreva uma frase: ");
    fgets(str, 50, stdin);
    //Uppercase
    for(int i = 0; i < 50; i++) {
        if(str[i] >= 65 + 32 && str[i] <= 90 + 32) {
            str[i] = str[i] - 32;
        }
    }
    //Scan the letter
    printf("Enter a character : ");
    scanf("%c", &c);
    
    //Uppercase
	if(c >= 65 + 32 && c <= 90 + 32) {
          c = c - 32;
    }
	//Use the function
	int contador = where_is(str,c,vec);
    
    //Final print
    printf("%s", str);
    printf("%c\n", c);
    printf("contador:%i\n", contador);
    for(int i = 0; i<contador;i++){
        printf("%i\n", vec[i]);
    }
    return 0;
}


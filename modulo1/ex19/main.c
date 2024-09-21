#include <stdio.h>
#include <string.h>

int main()
{
    char frase[50];
    char word[10];
    char* initial_addr;
    int i;
    int j;
    int flag = -1; 
    int n = 0; 
    int m = 0;
    //scan 
    printf("Escreva uma frase: ");
    fgets(frase, 50, stdin);
    //Uppercase capslock
    for(int i = 0; i < 50; i++) {
        if(frase[i] >= 65 + 32 && frase[i] <= 90 + 32) {
            frase[i] = frase[i] - 32;
        }
    }
    //scan 
    printf("Que palavra deseja procurar?: ");
    scanf("%s", word);
    //uppercase
    for(int i = 0; i < 50; i++) {
        if(word[i] >= 65 + 32 && word[i] <= 90 + 32) {
            word[i] = word[i] - 32;
        }
    }
    
    initial_addr = &frase[0];
    //size of the array
    for(i = 0; (frase[i] == '\0'); i++){
        n++;
    }
    for(i = 0; (word[i] == '\0'); i++){
        m++;
    }
    
    
	// Find the word in the phrase
    while (i < n) {
        j = 0;
        while (i < n && j < m && initial_addr[i] == word[j]) {
            ++i;
            ++j;
        }
        if (( i == n || initial_addr[i] == ' ' || initial_addr[i+1] == '\0') && j == m){
            flag = i-m;
        }
        while (i < n && initial_addr[i] != ' ') {
            ++i;
        }
        ++i;
    }
    //give the adress of the first letter in the word 
    char* final_addr;
    if (flag != -1){
        final_addr = &initial_addr[flag];
    }
    else final_addr = 0;
    
    printf("%s", frase);
    printf("%s\n", word);
    printf("%i\n", flag);
    printf("%p\n", final_addr);
    return 0;
}

#include <string.h>
int where_is (char *str, char c, int *p){
	int i = 0;
	int n = strlen(str);
    int contador=0;
    
    char *x =str;
  
    while (i < n) {
        if(*x == c){
            *(p+contador) = i;
            contador++;
        }
        x++;
        ++i;
    }
	
	
	return contador;
}

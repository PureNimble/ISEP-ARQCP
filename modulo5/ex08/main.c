#include <stdio.h>
#include "fill_s2.h"

int main(){;
    s2 struct2;
    s2 *s = &struct2;
    short vw [3] = {1, 2, 3};
    int vj = 4;
    char vc [3] = {5, 6, 7};
    fill_s2(s, vw, vj, vc);
    
    int i;
    printf("Shorts: ");
    for(i = 0; i < 3; i++){
        printf("  %d  ", s->w[i]);
    }
    printf("\nInteiro: %d\n", s->j);
    printf("Chars: ");
    for(i = 0; i < 3; i++){
        printf("  %d  ", s->c[i]);
    }
    printf("\n");

    return 0;
}
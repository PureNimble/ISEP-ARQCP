#include <stdio.h>
#include "fill_s1.h"

int main(){
    s1 struct1;
    s1 * s = &struct1;
    fill_s1(s, 1000, 1,2000,2);
    printf("i = %d\nc = %d\nj = %d\nd = %d\n", s->i, s->c, s->j, s->d );
    return 0;
}
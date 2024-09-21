#ifndef ASM_H 
#define ASM_H 
typedef struct {
       char c[3];
       short w[3];
       int j;
} s2;
void fill_s2(s2 *s, short vw[3], int vj, char vc[3]); 
#endif 


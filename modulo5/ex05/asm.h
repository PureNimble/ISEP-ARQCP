#ifndef ASM_H 
#define ASM_H 
typedef struct {
       short number;
       char age; 
       char filler; 
       int grades[5];
       char name[60];
       char address[100];
} Student;
void update_grades(Student *s,int *new_grades); 
#endif 


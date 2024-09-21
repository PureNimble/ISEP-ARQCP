#define ASM_H 
typedef struct {
       short number;
       char age;
       int grades[5];
       char name[60];
       char address[100];
} Student;

int locate_greater(Student *s, int minimum , int * greater_grades);
#endif 


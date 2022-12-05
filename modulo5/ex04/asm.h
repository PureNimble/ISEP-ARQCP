typedef struct {
       short number;
       char age; 
       char filler; 
       int grades[5];
       char name[60];
       char address[100];
} Student;
void update_address(Student *s,char *address); 

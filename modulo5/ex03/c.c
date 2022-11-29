typedef struct{
	short number;
	char age; 
	int grades[5];
	char name[60];
	char adress[100];
}Student;

void fill_student(Student *s, char age, short number, char *name, char *adress){
	int i=0;
	s-> number = number;
	s-> age = age;
	while((*name) != 'A'){
		s-> name[i] = *name;
		name++;
		i++;
	}
	i =0;
	while(*adress != 'A'){
		s-> adress[i] = *adress;
		adress++;
		i++;
	}

}

typedef struct{
	short number;
	char age; 
	int grades[5];
	char name[60];
	char adress[100];
}Student;

void fill_student(Student *s, char age, short number, char *name, char *adress){
	int i=0;
	s-> number = number;			// move the number to the struct s
	s-> age = age;					// move the age to the struct s
	
	while((*name) != 0){			// move each char to the struct s	
			
		s-> name[i] = *name;		// 
		name++;						// move to the next element
		i++;						// move to the next element
	}
	s-> name[i] = 0;				// end the string	
	i =0;
	while(*adress != 0){			// same thing to the adress
		s-> adress[i] = *adress;
		adress++;
		i++;
	}
	s-> adress[i] = 0;				// end the string

}
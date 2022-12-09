#include "fill_student.h"
void fill_student(Student *s, char age, short number, char *name, char *address){
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
	while(*address != 0){			// same thing to the adress
		s-> address[i] = *address;
		address++;
		i++;
	}
	s-> address[i] = 0;				// end the string

}

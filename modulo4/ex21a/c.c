int distance(char *a, char *b){
	int sum = 0;				// declaration of the counter	
	while(*a != 0){				// check the end of the string
		
		if(*a != *b){sum ++;}	// count the number of wrong chars
		a++;					// next char a
		b++;					// next char b
	}
	if (*b != 0){				// check if b have the same size
		sum = -1;
	}
	return sum;					// return the value
}

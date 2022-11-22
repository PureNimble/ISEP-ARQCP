int distance(char *a, char *b){
	int sum = 0;
	while(*a != 0){
		
		if(*a != *b){sum ++;}	
		a++;
		b++;	
	}
	if (*b != 0){
		sum = -1;
	}
	return sum;
}

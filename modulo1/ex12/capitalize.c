void capitalize (char *str){
	//Check if the sentence starts with a space
	if(*str != ' '){
		*str -=32;
	}
	int i = 0;
	//Change the value of the first letter of the words
	while(*(str+i)!= 0){
		if(*(str+i) == ' '){
			*(str+(i+1))-=32;
		}
		i++;
	}
}

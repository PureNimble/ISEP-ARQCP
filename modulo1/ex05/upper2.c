void upper2(char *str) {
    
    while(*str != '\0'){
        if(*str >= 97 && *str <= 122){ //97 is "a" and 122 is "z"
			*str = *str - 32;          //-32 is the upper char of the same letter
		}
        str++;// skips one position of the array
    }
}


void upper1(char *str) {
    
    for (int i = 0; str[i] != 0; i++){
		if(str[i] >= 97 && str[i] <= 122){ //97 is "a" and 122 is "z"
			str[i] = str[i] - 32;          //-32 is the upper char of the same letter
		}
	}
}

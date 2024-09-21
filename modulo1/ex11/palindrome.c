int palindrome(char *str){
	int i,j;
	int lenght = 0;
	
	
	//Uppercase convertion
	for (i = 0; str[i] != 0; i++){
		if(str[i] >= 97 && str[i] <= 122){
			str[i] = str[i] - 32;
		}
	}
	//Find the sentence size
	for(i = 0; str[i] != 0; i++){
		lenght++;
	}
	
	for(i = 0; i < lenght; i++){  //for loop to eliminate all non uppercase letters
        if(str[i] < 65 || str[i] > 90){ // if any character is not an uppercase letter it gets elimnated
            for(j = i;j < lenght;j++){  
				str[j]=str[j+1];  
			}  
        lenght--;
        i--;  
        }
    }
    
    int size = lenght -1;
	//for loop that checks if the first element and subsequent increasing order elements are the same as the last element and subsequent decreasing elements
	for(i=0; i<(size/2); i++){ // (size/2) because there is no need to verify over the halfway point
		if(*(str+i) != *(str+size-i)){
			return 0;
		}
	}
	return 1;
	
} 

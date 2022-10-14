void upper1(char *str) {
    
    for(int i = 0; i < 30; i++) {
        if(str[i] >= 65 + 32 && str[i] <= 90 + 32) { //65+32 is "a" and 90+32 is "z"
            str[i] = str[i] - 32;				     //-32 is the upper char of the same letter
        }
        
    }
}

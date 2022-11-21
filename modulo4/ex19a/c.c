void add_byte(char x, int *vec1, int *vec2){
	int n = *vec1;
	*vec2 = *vec1;
	vec2++;
	vec1++;
	for(int i=0; n > i; i++){
		
		char byte1 =(char) *vec1 ;	// get 1 byte
		byte1 += x;					// 1byte + x	
		*vec1 &= 0xFFFFFF00;		// remove the first byte
		*vec2 = byte1 + *vec1;		// sum the number with the new byte1
		vec1++;						// next number
		vec2++;						// next space
	}
}

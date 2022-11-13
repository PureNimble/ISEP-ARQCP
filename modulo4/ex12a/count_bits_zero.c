int count_bits_one(int x){
	
	int i;							// right shift variable
	int carry;						// carry
	int counter = 0;				
						
	for (i = 1; i <= 32; i++){		// cicle for 32 bits (int)
    	carry = x >> i;				// right shift x
    	if (carry & 1){				// 1 & 1 = 1
			counter++;				// is a one
    	}							// if = 0 doesn't do anything
  	}
  	return counter;				// return the counter
}

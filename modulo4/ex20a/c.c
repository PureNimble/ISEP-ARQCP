int sum_multiples_x(char *vec, int x){
	
	int sum = 0;						// Declarate the sum 
	x >>= 8;							// Put the second byte in the first one
	while(*vec != 0){					// Stop the cycle at the end of vec
		if((*vec % (char) x) == 0){		// Check if 2 byte of x is a multiples
			sum += *vec;				// sum the numbers
		}
		vec++;							// Go to the next number
	}
	return sum;							// Return the sum
}

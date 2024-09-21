void changes(int *ptr){
	
	int check = *ptr;				// initiation of the variable	
	check &= 0xFF00;				// number & mask = just the second byte
	check >>= 8;					// second byte
	if(check > 15) {				
		*(ptr) ^= 0xFF0000;			// inverte the bits in the third byte
	}
}

void changes(int *ptr){
	char bits = 16;					// start of the third byte		
	int check = *ptr;				// initiation of the variable	
	check &= 0xFF00;				// number & mask = just the second byte
	check >>= 8;					// second byte
	if(check > 15) {				
		while ( bits != 24) {		// end at the last bit of the 3byte
			*(ptr) ^= (1 << bits);	// num ^ (1 << bits) = inverte the bits

			bits++;					// next bit
		}
	}
}

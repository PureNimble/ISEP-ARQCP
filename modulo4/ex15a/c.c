int activate_bits(int a, int left, int right){
	
	int i;
	for(i = left + 1; i < 32; i++){ 	// Start at the left bit of left
		a |= 1 << i;						//   a|mask -> put a 1 in the position of the mask
	}
	
	for(i = 0; i < right; i++){				// Ends at the right bit of right	
		a |= 1 << i;						// a|mask -> put a 1 in the position of the mask
	}
	
	return a;
}

int reset_bit(int *ptr, int pos){
	
	
	int mask1 = (1 << pos);						// shift left (pos) bits
	int mask2 = ~mask1; 						// reverse the bits of mask1
	int x = mask1 & *ptr;						// ex:. 0010 & 1010 = 0010
	
	*ptr = *ptr & mask2;						// 1010 & 1101 = 1
	
	if (x == 0){								// if x = 0 the bit was 0
		return 0;
	}else{return 1;}							// ohterwise it was a 1 

}

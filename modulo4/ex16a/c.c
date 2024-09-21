int join_bits(int a, int b, int pos){	
	
	

int x=0, y=0;

	y=(1<<pos)-1;		// Shift left (pos) bits 
						// (Shift left (pos) bits) - 1 = mask with 1s before (pos) and 0s after (pos)
	y=(y<<1)+1;			// Shift left to make the (pos) bit active
						// Active the first bit, that was changed in the last line
				
	a = (a & y);		// a & mask ( clear the left bits of a, start at (pos+1) )
	b = (b & (~y));		// b & ~mask ( clear the right bits of b, start at pos )

	x = (a|b);			// a | b ( combine all bits )

	return x;
}

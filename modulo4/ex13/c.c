int rotate_left(int num, int nbits){
	
  	return (num << nbits)|(num >> (32 - nbits)); // nbits shift left (ex:. num=10; nbits=2; 1010 -> 1000 ), the rest of the bits shift right (ex:. num=10; nbits=2;rest=(32-nbits) 1010 -> 0010) 1000 | 0010 = 1010
}
int rotate_right(int num, int nbits){

	return (num >> nbits)|(num << (32 - nbits)); // same thing for the right side
}

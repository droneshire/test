#include "stdio.h"
#include "stdlib.h"

char bitrev(char byte) {
	
	int s;
	char r;
	s = sizeof(char)*8-1;
	r = byte;

	for(byte >>= 1; byte; byte >>= 1) {
		r <<= 1;
		r |= (byte & 1);
		s--;
	}
	r <<= s;
}


int main() {
	char x;
	x = 0x4F;
	printf("Orig: %d, Rev: %d", x, bitrev(x));
	
	return 0;
}

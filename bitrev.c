#include "stdio.h"
#include "stdlib.h"

int bitrev(char byte) {
	
	int i,s;
	char c;
	s = sizeof(char)*8-1;
	c = byte;

	for(byte >>= 1; byte; byte >>= 1) {
		r <<= 1;
		r |= (byte & 1);
		s--;
	}
	r <<= s;
}


int main() {
}

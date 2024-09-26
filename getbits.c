#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);

main() {
	printf("%u\n", getbits(13, 4, 5));
	
	return 0;
}

/* Unsigned Int Int -> Unsigned
   get n bits frm position p */
unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n) & ~(~0 << n));
}
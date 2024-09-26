/* solution by Codybartfast */
#include <stdio.h>

unsigned char setbits(unsigned char x, unsigned char p, unsigned char n, unsigned char y);
void check_expect(unsigned a, unsigned b);

main() {
	check_expect(setbits(60, 0, 1, 13), 61);
	check_expect(setbits(60, 1, 1, 13), 60);
	check_expect(setbits(60, 1, 2, 13), 61);
	check_expect(setbits(60, 4, 1, 13), 44);
	check_expect(setbits(60, 4, 5, 13), 45);
	check_expect(setbits(60, 5, 6, 13), 13);
	
	return 0;
}

/*
 * If n has its maximum value (e.g. 32) then "<< n" is undefined (Reference 
 * Manual A7.8 p206).  So to avoid "<< 32" I use "<< (n - 1) << 1".  (On my
 * machine "<< 32" is treated as "<< 0".)
 */
unsigned char setbits(unsigned char x, unsigned char p, unsigned char n, unsigned char y)
{
	unsigned mask;
	if (n == 0) {
		mask = 0;
	} else {
		mask = ~(~0 << (n - 1) << 1) << (p + 1 - n);
	}
	return (x & ~mask) | (y & mask);
}

/* check for equality between a and b */
void check_expect(unsigned a, unsigned b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %u differs from %u, the expected value.\n", a, b);
}
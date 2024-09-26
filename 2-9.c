/*
Exercise 2-9.
  In a two's complement number system, x &= (x-1) deletes the rightmost
  1-bit in x. Explain why. Use this observation to write a faster
version of bitcount.

when x is a positive number where the rightmost bit is a 1-bit
for example (3 digits binary)

	x = 001		(x-1) = 000
	x = 011		(x-1) = 010
	x = 101		(x-1) = 100

the expression x & (x-1) will preserve the bit representation of x
except the rightmost bit

	001 & 000 = 000
	011 & 010 = 010
	101 & 100 = 100
*/

#include <stdio.h>
int bitcount(unsigned x);
void test(unsigned given, int unsigned);

main() {
	test(0, 0);
	test(1, 1);
	test(2, 1);
	test(3, 2);
	test(4, 1);
	test(5, 2);

	return 0;
}

/* count 1 bits on x */
int bitcount(unsigned x) {
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}

/* compares the actual value of bitcout(given) and the expected value */
void test(unsigned given, unsigned expected) {
	int actual = bitcount(given);

	if (actual == expected)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", actual, expected);
}



























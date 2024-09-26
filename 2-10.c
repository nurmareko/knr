#include <stdio.h>

int lower(int c);
void check_expect(const int a, const int b);

main() {
	check_expect(lower('a'), 'a');
	check_expect(lower('A'), 'a');
	check_expect(lower('z'), 'z');
	check_expect(lower('Z'), 'z');

	return 0;
}

/* Char -> Char
   convert c to lower case; ASCII only.
*/
int lower(int c) {
	return (c>='A' && c<='Z') ? c+'a'-'A' : c;
}

/* Int Int -> String
   check for equality between a and b
*/
void check_expect(const int a, const int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}

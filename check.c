#include <stdio.h>

void check_expect(int a, int b);

main() {
	check_expect("x", "x");

	return 0;
}

/* Int Int -> String
   check for equality between a and b */
void check_expect(int a, int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}
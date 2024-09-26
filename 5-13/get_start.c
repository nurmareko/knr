#include <stdio.h>

int get_start(int, int);
void check(int, int);

main () {
	check(get_start(0, 1), 0);
	check(get_start(0, 4), 0);
	check(get_start(6, 11), 0);
	check(get_start(7, 7), 0);
	check(get_start(14, 3), 11);
}

int get_start(int lines, int n) {
	if (lines <= n)
		return 0;
	else
		return (lines - n);
}

void check(int a, int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}
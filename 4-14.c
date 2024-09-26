#include <stdio.h>

#define swap(t, x, y)		\
	{ t _z;			\
	_z = x;			\
	x = y;			\
	y = _z;			}

main() {
	int a = 10;
	int b = 45;
	printf("before\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	swap(int, a, b);
	printf("after\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);

	return 0;
}
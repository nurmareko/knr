#include <stdio.h>
#include <limits.h>

/* display the possible range of value of data type char, short, int,
   and long, both signed and unsigned. */

main() {
	printf("data type char value range\n");
	printf("unsigned: %4u to %u\n", 0, UCHAR_MAX);
	printf("signed  : %d to %d\n\n", SCHAR_MIN, SCHAR_MAX);

	printf("data type short value range\n");
	printf("unsigned: %6u to %u\n", 0, USHRT_MAX);
	printf("signed  : %d to %d\n\n", SHRT_MIN, SHRT_MAX);

	printf("data type int value range\n");
	printf("unsigned: %11u to %u\n", 0, UINT_MAX);
	printf("signed  : %d to %d\n\n", INT_MIN, INT_MAX);

	printf("data type long value range\n");
	printf("unsigned: %11u to %u\n", 0, ULONG_MAX);
	printf("signed  : %d to %d\n\n", LONG_MIN, LONG_MAX);

	return 0;
}
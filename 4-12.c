#include <stdio.h>
#include <math.h>

void itoa(int, char[]);
void reverse(char[]);

main() {
	char s[100];

	itoa(-123, s);
	printf("%s\n", s);

	return 0;
}

/* itoa: convert n to characters in s				*/
void itoa(int n, char s[]) {
	static int i;

	if (n / 10) {
		itoa(n/10, s);
	} else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i]   = '\0';
}





















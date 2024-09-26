#include <stdio.h>
#include <string.h>

void reverse(char*);

main() {
	char str[] = "fghi";	

	printf("before: %s\n", str);
	reverse(str);
	printf("after:  %s\n", str);

	return 0;
}

/* reverse: reverse string s in place				*/
void reverse(char *s) {
	char c, *t;

	for (t = s + (strlen(s) -1); s < t; s++, t--) {
		c = *s;
		*s = *t;
		*t = c;
	}
}
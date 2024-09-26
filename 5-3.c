#include <stdio.h>

#define SIZE 100

void strcatx(char *, char *);

main() {
	char *b;

	char a[SIZE] = "";
	strcatx(a, b = "");
	printf("\"%s\"\n", a);	/* ""				*/

	char c[SIZE] = "a";
	strcatx(c, b = "");
	printf("\"%s\"\n", c);	/* "a"				*/

	char d[SIZE] = "";
	strcatx(d, b = "b");
	printf("\"%s\"\n", d);	/* "b"				*/

	char e[SIZE] = "x";
	strcatx(e, b = "y");
	printf("\"%s\"\n", e);	/* "xy"				*/

	char f[SIZE] = "dd";
	strcatx(f, b = "ee");
	printf("\"%s\"\n", f);	/* "ddee"			*/

}

/* strcatx: concatenate t to end of s; s must be big enough	*/
void strcatx(char *s, char *t) {
	while (*s) /* find the end of s (NUL character)	*/
		s++;
	while (*s++ = *t++) /* copy t at the end of s		*/
		;
}




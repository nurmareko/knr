#include <stdio.h>

int strindex(char*, char*);

main() {

	return 0;
}

/* strindex: return index of t in s, -1 if none			*/
int strindex(char *s, char *t) {
	char *b = s;		/* beginning of string s	*/
	char *p, *r;

	for (; *s != '\0'; s++) {
		for (p=s, r=t; *r != '\0' && *p == *r; p++, r++)
			;
		if (r > t && *r == '\0')
			return s - b;
	}
	return -1;

}
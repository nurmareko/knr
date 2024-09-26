#include <stdio.h>
#include <string.h>

int  getline(char*, int);
int  atoi(char*);
void itoa(int, char*);
void reverse(char*);
int  strindex(char*, char*);
int  getop(char*);

main() {
	return 0;
}

/* getline: get line into s, return length			*/
int getline(char *s, int lim) {
	int c;
	char *t = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

/* atoi: convert string s to integer				*/
int atoi(char *s) {}

/* itoa: convert n to characters in s				*/
void itoa(int n, char *s) {}

/* reverse: reverse string s in place				*/
void reverse(char *s) {
	char c, *t;

	for (t = s + (strlen(s) -1); s < t; s++, t--) {
		c = *s;
		*s = *t;
		*t = c;
	}
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

/* getop: get next operator or numeric operand			*/
int getop(char *s) {}
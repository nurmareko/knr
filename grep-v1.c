#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length		*/

int getline(char*, int);
int strindex(char*, char*);

char pattern[] = "ould";	/* pattern to search for	*/

/* find all lines matching pattern				*/
main() {
	char line[MAXLINE];
	int found = 0;

	while (getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
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
#include <stdio.h>

#define MAXLINE 100 /* maximum input line length		*/

int getline(char*, int);

main() {
	char line[MAXLINE];
	int length = getline(line, MAXLINE);

	printf("length:  %d\n", length);
	printf("getline: %s", line);

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

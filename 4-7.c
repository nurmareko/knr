#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char 	buf[BUFSIZE];	/* buffer for ungetch			*/
int	bufp = 0;	/* next free position in buf		*/

main() {
	return 0;
}

/* getch: get a (possibly pushed back) character		*/
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input			*/
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else
		buf[bufp++] = c;
}

/* ungets: push string onto the input	*/
void ungets(char s[]) {
	int len = strlen(s);

	while (len > 0)
		ungetch(s[--len]);
}
#include <stdio.h>

#define BUFSIZE 100

int 	buf[BUFSIZE];	/* buffer for ungetch			*/
int	bufp = 0;	/* next free position in buf		*/

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

/*
The problem is storing EOF (-1) in an array of character is more likely
to cause unwanted convertion on some machine, to make the code more
portable we should use an array of integer for buffer.
*/

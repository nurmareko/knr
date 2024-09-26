#include <stdio.h>

#define TABSTOP  4	/* tab stop every multiple of TABSTOP	*/
#define FIRSTCOL 1	/* the beginning position of a column	*/

/* detab: replaces tabs in the input with the proper number of	*/
/*        blanks to space to the nest tab stop.			*/
main() {
	int c;
	int pos = FIRSTCOL; /* the current position of a column	*/
	int spaces; /* # of space needed to reach tabstop	*/

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			spaces = TABSTOP - ((pos - 1) % TABSTOP);
			while (spaces > 0) {
				putchar(' ');
				++pos;
				--spaces;
			}
		} else {
			putchar(c);
			if (c == '\n') {
				pos = FIRSTCOL;
			} else
				++pos;
		}

	}
}
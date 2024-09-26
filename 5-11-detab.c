#include <stdio.h>
#include <stdlib.h>

#define DEFAULT  8	/* default tab increment size		*/
#define FIRSTCOL 1	/* the beginning position of a column	*/

/* detab: replaces tabs in the input with the proper number of	*/
/*        blanks to space to the next tab stop.			*/
main(int argc, char *argv[]) {
	int c, cts, i, pos = FIRSTCOL, spaces, tabstop;

	cts = argc - 1; /* # of custom tab stop	*/
	int custom_value[cts];
	for (i = 0, ++argv; i < cts; i++) /* build list of custom value*/
		custom_value[i] = atoi(argv[i]);
	
	i = 0;		/* re-initialize index for custom value	*/
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			if (cts > 0) {
				tabstop = custom_value[i++];
				spaces = tabstop - ((pos - 1) % tabstop);
				cts--;
			} else
				spaces = DEFAULT - ((pos - 1) % DEFAULT);
			pos += spaces;
			while (spaces--)
				putchar(' ');
		} else {
			putchar(c);
			if (c == '\n') {
				pos = FIRSTCOL;	/* reset column positon	*/
				cts = argc - 1;	/* reset custom tabstop	*/
				i = 0;	/* reset index for custom value	*/
			} else
				++pos;
		}
	}
	return 0;		
}
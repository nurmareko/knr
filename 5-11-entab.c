#include <stdio.h>

#define DEFAULT	8	/* default tab increment size		*/

/* entab: replace strings of blanks with tabs and blanks	*/
main(int argc, char *argv[]) {
	int adjacent, c, blanks, cts_count, cts[argc-1], i, tabstop;
	int *cts_pointer;

	cts_count = argc-1;
	cts_pointer = cts;
	for (i = 0, ++argv; i < cts_count; ++i)
		cts[i] = argv[i];
	cts[cts_count] = 0;
	
	while ((c = getchar()) != EOF)
		if (c == ' ') {
			for (blanks = 1; (adjacent = getchar()) == ' '; ++blanks)
				;
			set current tabstop
			if (one tab enough) {
				reset count
				write tab
			} else {
				while (count is more than tabstop) {
					update count
					update tabstop
					write tab
				}
				while (count is more than zero) {
					update count
					write blank
				}
				write adjacent	
			}
		} else if (c == '\n') {
			cts_pointer = cts;
			putchar('\n');
		} else
			putchar(c);
	return 0;
}


/* pseudo

while (there's another character)
	if (is blank character)
		count strings of blanks
		set current tab stop
		if ((count is less than tabstop) And (the adjacent character is tab character))
			reset count
			write tab
		else
			write tab while count is greater than or equal to tab stop
			write blank while count is greater than zero
			write adjacent character
	else
		write character
*/
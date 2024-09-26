#include <stdio.h>

/* count blanks, tabs, and newlines from the given input */
main() {
	int character, blanks, newlines, tabs;

	blanks 	 = 0;
	tabs 	 = 0;
	newlines = 0;

	while ((character = getchar()) != EOF) {
		if (character == ' ')
			++blanks;
		if (character == '\t')
			++tabs;
		if (character == '\n')
			++newlines;
		}

	printf("blank  : %d\ntab    : %d\nnewline: %d\n", blanks, tabs, newlines);
}
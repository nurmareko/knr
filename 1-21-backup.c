#include <stdio.h>

#define TABSTOP	8

/* entab: replaces strings of blanks by the minimum number of	*/
/*        tabs and blanks to achieve the same spacing.		*/
main() {
	int c;
	int count_space = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			for (count_space = 1; (c = getchar()) == ' '; ++count_space)	/* 1 */
				;
			if (c == '\t' && count_space < TABSTOP) {			/* 2 */
				putchar('\t');
				count_space = 0;
			} else {
				while (count_space > TABSTOP) {				/* 3 */
					putchar('\t');
					count_space = count_space - TABSTOP;
				}
				while (count_space > 0) {				/* 4 */
					putchar(' ');
					--count_space;
				}
				putchar(c);						/* 5 */
			}			
		} else									/* 6 */
			putchar(c);
	}
}

/* 1 Count character in string of blanks,
 *   in onder to count how many character in a string of blanks it
 *   will cause the code to read one character to far.
 *
 * 2 Output tab and forget string of blanks,
 *   when the string of blanks is less than TABSTOP and adjacent to a
 *   tab character we dont need to output the string of blanks because
 *   a single tab will suffice.
 *
 * 3 Output tabs for every TABSTOP that fit inside count_space.
 *
 * 4 Output space for the remaining of count_space.
 *
 * 5 Because we read one character to far to determine the length of
 *   string of blanks we need to output that character.
 *
 * 6 When the current character is not a space character we simply
 *   output that character.
 */
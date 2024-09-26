#include <stdio.h>

#define BLANK 	 ' '
#define	NONBLANK '\0'	/* arbitrary chosen	*/

/* replace each string of one or more blanks by a single blank. */
main() {
	int current_char, previous_char;

	previous_char = NONBLANK;
	while ((current_char = getchar()) != EOF) {
		if (current_char != BLANK)
			putchar(current_char);
		if (current_char == BLANK)
			if (previous_char != BLANK)
				putchar(BLANK);
		previous_char = current_char;
	}
}
/*********************************************************************/
/* replace each string of one or more blanks by a single blank. */

/* given : "ab"
   expect: "ab"

   given : "a b"
   expect: "a b"

   given : "a   b"
   expect: "a b"

   given : "a b  c   d e"
   expect: "a b c d e"

#define FALSE 0
#define TRUE  1

main (){
	int c, is_space;

	is_space = FALSE;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			is_space = FALSE;
		}
		if (c == ' '){
			if (is_space == FALSE) {
 				putchar(c);
				is_space = TRUE;
			}
		}
	}
}
*/
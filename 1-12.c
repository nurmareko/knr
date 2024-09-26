#include <stdio.h>

/* print the given input one word per line.
   restriction:
       - asume there is only one line of words
       - seperated by space or tab

   ; no space nor tab
   given : "firstsecond"
   expect: "firstsecond"

   ; single space
   given : "first second"
   expect: "first
           second"

   ; double space
   given : "first  second"
   expect: "first
           second"

   ; single tab
   given : "first	second"
   expect: "first
           second"

   ; double tab
   given : "first		second"
   expect: "first
           second"

   ; space and tab combination
   given : "first 	second"
   expect: "first
            second"
*/

#define FALSE 0
#define TRUE  1

main() {
	int c, in_space;

	in_space = FALSE;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t') && in_space == FALSE) {
			putchar('\n');
			in_space = TRUE;
		} else {
			putchar(c);
			in_space = FALSE;
		}
	}
}

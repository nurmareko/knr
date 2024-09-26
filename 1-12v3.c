#include <stdio.h>

#define IN  1
#define OUT 0

/* [Stream-of Character] -> [Stream-of Character]
   print the given input one word per line.
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

main()
{
    int c, whitespace;

    whitespace = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            if (whitespace == OUT) {
                putchar('\n');
                whitespace = IN;
            }
        if (c != ' ' && c != '\t') {
            putchar(c);
            whitespace = OUT;
        }
    }
}

#include <stdio.h>

#define IN  1
#define OUT 0

/* [Stream-of Character] -> [Stream-of Character]
   print the given input one word per line.
   restriction:
       asume there is only one line of words seperated by a space.

   given : ab
   expect: ab

   given : ab cd
   expect: ab
           cd

   given : ab cd ef
   expect: ab
           cd
           ef

   given : ab   cd
   expect: ab
           cd

   given : ab   cd     ef
   expect: ab
           cd
           ef
*/

main()
{
    int c, in_space;

    in_space = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            if (in_space == OUT) {
                putchar('\n');
                in_space = IN;
            }       
        if (c != ' ') {
            putchar(c);
            in_space = OUT;
        }
    }
}

#include <stdio.h>

/* [Stream-of Character] -> [Stream-of Character]
   print the given input one word per line.
   restriction:
       asume there is only one line of words seperated by a single space.

   given : ab
   expect: ab

   given : ab cd
   expect: ab
           cd

   given : ab cd ef
   expect: ab
           cd
           ef
*/

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            putchar('\n');
        else
            putchar(c);
    }
}
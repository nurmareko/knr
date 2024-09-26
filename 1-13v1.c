#include <stdio.h>

/* String -> String
   print the length of the given word
   constrain:
       asume there is only one word 

   given : ""
   expect: word length: 0

   given : "a"
   expect: word length: 1

   given : "xxx"
   expect: word length: 3
*/

main() 
{
    int c, length;

    length = 0;
    while ((c = getchar()) != EOF)
        if (c != '\n')
            ++length;
    printf("word length:%d", length);
}
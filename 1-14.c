#include <stdio.h>

/* Print a histogram (chart) of the frequencies of different characters
   in its input */

/* given  : empty
   expect : alphabets  : 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
            digits     : 0 0 0 0 0 0 0 0 0 0
            whitespaces: 0
            other      : 0

  given  : abc
  expect : alphabets  : 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
           digits     : 0 0 0 0 0 0 0 0 0 0
           whitespaces: 0
           other      : 0

  given  : abc123
  expect : alphabets  : 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
           digits     : 0 1 1 1 0 0 0 0 0 0
           whitespaces: 0
           other      : 0

  given  : abc 123
  expect : alphabets  : 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
           digits     : 0 1 1 1 0 0 0 0 0 0
           whitespaces: 1
           other      : 0

  given  : abc 123!@#
  expect : alphabets  : 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
           digits     : 0 1 1 1 0 0 0 0 0 0
           whitespaces: 1
           others     : 3
*/

main() {
	int c, i, others, whitespaces;
	int alphabets[26], digits[10];

	others      = 0;
	whitespaces = 0;
	for (i = 0; i < 26; ++i)
		alphabets[i] = 0;
	for (i = 0; i < 10; ++i)
		digits[i] = 0;		

	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'Z')
			++alphabets[c - 'A'];
		else if (c >= 'a' && c <= 'z')
			++alphabets[c - 'a'];
		else if (c >= '0' && c <= '9')
			++digits[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++whitespaces;
		else
			++others;
	}
	printf("alphabets  :");
	for (i = 0; i < 26; ++i)
		printf(" %d", alphabets[i]);
	printf("\ndigits     :");
	for (i = 0; i < 10; i++)
		printf(" %d", digits[i]);
	printf("\nwhitespaces: %d", whitespaces);
	printf("\nothers     : %d", others);
}
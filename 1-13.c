#include <stdio.h>

#define BAR 223

/* print a histogram of the lengths of words in its input.
     restriction:
       asume every word is seperated by only a single whitespace character.
*/

/* given  : empty
   expect : 1-3: 0
            3-5: 0
            >=5: 0

   given  : a a bb bb
   expect : 1-3: 4 ▀▀▀▀▀▀▀▀▀▀▀▀▄▄▄▄
            3-5: 0
            >=5: 0

   given  : aaa aaa bbbb bbbb
   expect : 1-3: 0
            3-5: 4 ▄▄▄▄
            >=5: 0

   given  : aaaaa aaaaa bbbbbb cccccccccc
   expect : 1-3: 0
            3-5: 0
            >=5: 4 ▄▄▄▄

   given  : a bb cc ddd eeee fffffff
   expect : 1-3: 3 ▄▄▄▄
            3-5: 2 ▄▄
            >=5: 1 ▄

*/

main() {
	int c, i, count, in_word;
	int histogram[3];

	for (i = 0; i < 3; ++i)
		histogram[i] = 0;

	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (count < 3)
				++histogram[0];
			else if (count < 5)
				++histogram[1];
			else
				++histogram[2];
			count = 0;
		}
		else
			++count;
	}

	printf("1-3: %d ", histogram[0]);
	for (i = histogram[0]; i != 0; i--)
		putchar(BAR);
	printf("\n");
	printf("3-5: %d ", histogram[1]);
	for (i = histogram[1]; i != 0; i--)
		putchar(BAR);
	printf("\n");
	printf(">=5: %d ", histogram[2]);
	for (i = histogram[2]; i != 0; i--)
		putchar(BAR);
	printf("\n");
}
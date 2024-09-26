/* inspiration from clc-wiki.net */

#include <stdio.h>
#define MAXLINE 10000

int getline(char s[], int lim);

main() {
	char line[MAXLINE];
	int i, last_char, len;

	while((len = getline(line, MAXLINE)) > 0) {
		last_char = line[len-2];

		/* is the current line contain only a newline and a null?
		 * if true, then the line is entirely blank, skip it (in other word, delete.) 
		 * note: when the current line is entirely blank it only contain newline character therefore len is 1, however,
		 *       when there is atleast one character, the line will be compose of some character and a newline, therefore len is 2 or greater. */
		if (len == 1)
			;

		/* is the last character of the current line excluding newline and null, not a blank? 
		 * if true, then there is no trailing blank, nothing to remove, print the current line unchanged. */
		else if (last_char != ' ' && last_char != '\t')
			printf("%s", line);

		/* there is trailing blank. */
		else {
			/* get the index of the last non blank character.
			 * note: when the line compose of blanks and tabs, i will be -1 */
			for(i = len-2; line[i] == ' ' || line[i] == '\t'; --i)
				;
			
			/* put null after the last non blank character to mark the end of line without trailling blank. */
			line[++i] = '\0';

			/* is the line index after removing trailling blank greater than 0?
			 * if true, the line atleast have a character to print.
			 * if not, the line is entirely blank, skip it.                     */
			if (i > 0)
				printf("%s\n", line);	
		}
	}
	return 0;
}

/* read a line into s, return length */
int getline(char s[], int lim) {
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
#include <stdio.h>
#define MAXCHAR 1000
#define MAXLINE 1000
#define MINIMUM	20

int getline(char aline[]);
int save_line(char aline[], char lines[]);

/* print all input lines that are longer than 20 characters */

/* given  : empty
   expect : empty

   given  : T.T.T.
   expect : empty

   given  : the cryptic admonishment
   expect : the cryptic admonishment

   given  : Put up in a place
	    where it's easy to see
	    the cryptic admonishment
	    T.T.T.
	    
	    When you feel how depressingly
	    slowly you climb,
	    it's well to remember that
	    Things Take Time.
   expect : where it's easy to see
	    the cryptic admonishment
	    When you feel how depressingly
	    it's well to remember that
*/

main() {
	int  index;
	int  stream;
	int  line_length;
	char current_line[MAXCHAR];
	char lines[MAXLINE];

	index = 0;
	while ((line_length = getline(current_line)) > 0)
		if (line_length > MINIMUM)
			index = save_line(current_line, lines);
	lines[++index] = EOF;

	if (line_length > 0)
		for (index = 0; lines[index] != EOF; ++index)
			putchar(lines[index]);
}

/* save line from stream of characters into aline and return its length*/
int getline(char aline[]) {
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		aline[i] = c;
	if (c == '\n') {
		aline[i] = c;
		++i;
	}
	return i;
}

/* save a line into lines and return its length */
int save_line(char aline[], char lines[]) {
	int i;

	for (i = 0; (aline[i] = lines[i]) != '\n'; i++)
		;
	lines[i] = '\n';
	return ++i;
}
		















#include <stdio.h>
#define MAXLINE 1000

enum boolean {FALSE, TRUE};

main() {
	int c, i, lim, loop;
	char s[MAXLINE];

	lim = MAXLINE;
	i = 0;
	loop = TRUE;
	while (loop) {
		if (i<lim-1) {
			if ((c = getchar() != '\n')) {
				if (c != EOF) {
					s[i] = c;
					++i;
				}
				else
					loop = FALSE;
			}
			else 
				loop = FALSE;
		}
		else
			loop = FALSE;
	}

	return 0;
}
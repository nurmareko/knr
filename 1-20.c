#include <stdio.h>
#define TABSTOP 4
#define MAXCHAR 10000

/* detab: replaces tabs in the input with the proper number of blanks. */
main() {
	int c, i, j;
	char detabed[MAXCHAR];

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			for (j = TABSTOP; j > 0; --j) {
				detabed[i] = ' ';
				++i;
			}
		else {
			if (c == '\n') {
				detabed[i] = c;
				detabed[++i] = '\0';
			}
			else {
				detabed[i] = c;
				++i;
			}
		}
	}
	printf("%s", detabed);
	return 0;
}

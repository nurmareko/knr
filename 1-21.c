#include <stdio.h>
#define TABSTOP 8
#define MAXCHAR 10000

/* entab: replaces strings of blanks by the minimum number of tabs and
   blanks to achive the same spacing.                                  */
main() {
	int c, i, column, spaces;
	char entabed[MAXCHAR];

	i = spaces = 0;
	column = 1;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++spaces;
			if ((spaces == TABSTOP) && (column % TABSTOP)) {
				while (column % TABSTOP) {
					--column;
					--i;
				}
				spaces = 0;
			}
		}
		entabed[i] = c;
		++i;
		if (c == '\n')
			column = 1;
		else
			++column;
		if (c != ' ')
			spaces = 0;	
	}
	entabed[i] = '\0';
	printf("%s", entabed);
	return 0;
}

/*

given:
i        i        i
ii        ii        ii
iii        iii        iii
iiii        iiii        iiii
iiiii        iiiii        iiiii
iiiiii        iiiiii        iiiiii
iiiiiii        iiiiiii        iiiiiii
iiiiiiii        iiiiiiii        iiiiiiii
iiiiiiiii        iiiiiiiii        iiiiiiiii
iiiiiiiiii        iiiiiiiiii        iiiiiiiiii

expect:
i	i	i
ii	ii	ii
iii	iii	iii
iiii	iiii	iiii
iiiii	iiiii	iiiii
iiiiii	iiiiii	iiiiii
iiiiiii	iiiiiii	iiiiiii
iiiiiiii	iiiiiiii	iiiiiiii
iiiiiiiii	iiiiiiiii	iiiiiiiii
iiiiiiiiii	iiiiiiiiii	iiiiiiiiii

*/
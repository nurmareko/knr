#include <stdio.h>
#include <stdlib.h>

#define MAXLINE	100	/* maximum line size			*/
#define TABINC	  8	/* default tab increment size		*/	
#define YES	  1
#define NO	  0

void settab(int, char* [], char*);
void detab(char*);
int tabpos(int, char*);

/* replace tabs with blanks					*/
main(int argc, char *argv[]) {
	char tab[MAXLINE+1];

	settab(argc, argv, tab);	/* initialize tab stops	*/
	detab(tab);			/* replace tab w/ blanks*/
	return 0;
}

/* detab: replace tab with blanks				*/
void detab(char *tab) {
	int c, pos = 1;
	
	while ((c = getchar()) != EOF)
		if (c == '\t') {	/* tab character	*/
			do {
				putchar(' ');
			} while (tabpos(pos++, tab) != YES);
		} else if (c == '\n') {	/* newline character	*/
			putchar(c);
			pos = 1;
		} else {		/* all other characters	*/
			putchar(c);
			++pos;
		}
}
/****************************************************************/
/* settab: set tab stops in array tab				*/
void settab(int argc, char *argv[], char *tab) {
	int i, pos;

	if (argc <= 1) {		/* default tab stops	*/
		for (i = 1; i <= MAXLINE; i++)
			if (i % TABINC == 0) {
				tab[i] = YES;
			} else
				tab[i] = NO;
	} else {		/* user provided tab stops	*/
		for (i = 1; i <= MAXLINE; i++)
			tab[i] = NO; /* turn off all tab stops	*/
		while (--argc > 0) {/*walk through argument list*/
			pos = atoi(*++argv);
			if (pos > 0 && pos <= MAXLINE)
				tab[pos] = YES;
		}
	}
}
/****************************************************************/
/* tabpos: determine if pos is at a tab stop			*/
int tabpos(int pos, char *tab) {
	if (pos > MAXLINE) {
		return YES;
	} else
		return tab[pos];

}
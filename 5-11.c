#include <stdio.h>
#include <stdlib.h>

#define MAXLINE	100		/* maximum line size		*/
#define TABINC	  8		/* default tab increment size	*/
#define YES	  1
#define NO	  0

void settab(int, char* [], char*);
void entab(char*);
int tabpos(int, char*);

/* replace strings of blanks with tabs				*/
main(int argc, char *argv[]) {
	char tab[MAXLINE];

	settab(argc, argv, tab);	/* initialize tab stops	*/
	entab(tab);			/* replace blanks w/ tab	*/
	return 0;
}

/* entab: replace strings of blanks with tabs and blanks	*/
void entab(char *tab) {
	int c, pos;
	int nb = 0;		/* # of blanks necessary	*/
	int nt = 0;		/* # of tabs necessary		*/

	for (pos = 1; (c = getchar()) != EOF; pos++)
		if (c == ' ') {
			if (tabpos(pos, tab) == NO) {
				++nb;	/* increment # of blanks*/
			} else {
				nb = 0;	/* reset # of blanks	*/
				++nt;	/* one more tab		*/
			}
		} else {
			for (; nt > 0; nt--)
				putchar('\t');	/* output tab(s)	*/
			if (c == '\t') {	/* forget the blank(s)	*/
				nb = 0;
			} else 
				for (; nb > 0; nb--);
			putchar(c);
			if (c == '\n') {
				pos = 0;
			} else if (c == '\t') 
				while (tabpos(pos, tab) != YES) 
					++pos;
		}
}
/****************************************************************/
/* settab: set tab stops in array tab				*/
void settab(int argc, char *argv[], char *tab) {
	int i, pos;

	if (argc <= 1) {	/* default tab stops		*/
		for (i = 1; i <= MAXLINE; i++)
			if (i % TABINC == 0) {
				tab[i] = YES;
			} else
				tab[i] = NO;
	} else {		/* user provided tab stops	*/
		for (i = 1; i <= MAXLINE; i++)
			tab[i] = NO;	/* turn off all tab stops	*/
		while (--argc > 0) {	/* walk through argument list	*/
			pos = atoi(*++argv);
			if (pos > 0 && pos <= MAXLINE)
				tab[pos] = YES;
		}
	}
}
/****************************************************************/
/* tabpos: determine if pos is at a tab stop			*/
int tabpos(int pos, char *tab) {
	if (pos > MAXLINE)
		return YES;
	else 
		return tab[pos];
}
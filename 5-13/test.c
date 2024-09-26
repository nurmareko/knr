#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max #lines to be sorted	*/
char *lineptr[MAXLINES];	/* pointers to text lines	*/
enum Boolean{FALSE, TRUE};

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines						*/
main(int argc, char *argv[]) {
	int nlines;		/* number of input lines read	*/
	int numeric = FALSE;
}

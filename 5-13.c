#include <stdio.h>

#define MAXLINES 1000	/* maximum number of lines			*/
#define N	   10	/* the number of lines to be printed		*/

char *lineptr[MAXLINES];

void writelines(char* [], int, int);
int readlines(char* [], int);

/* tail: print the last 10 lines of the given input			*/
main() {
	int i, nlines;
	char *ptr;

	i = 0;
	if (nlines = readlines(lineptr, MAXLINES) >= 0) {
		if (nlines > N) {
			nlines = N;
			i = nlines - N;
		}
		writelines(lineptr, nlines, i);
	} else {
		printf("error: error message\n");
		return 1;
	}
	return 0;
}
/************************************************************************/
#include <string.h>

#define MAXLEN 1000		/* max lenght of any input line		*/
int getline(char *s, int lim);
char *alloc(int);

/* readlines: read input lines						*/
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; 	/* delete newline	*/
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines					*/
void writelines(char *lineptr[], int nlines, int i) {
	for (; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
/************************************************************************/
#define ALLOCSIZE 10000		/* size of available space		*/

static char allocbuf[ALLOCSIZE];	/* storage for alloc		*/
static char *allocp = allocbuf;		/* next free position		*/

char *alloc(int n) {	/* return pointer to n characters		*/
	if (allocbuf + ALLOCSIZE - allocp) {	/* it fits		*/
		allocp += n;
		return allocp - n;	/* old p			*/
	} else		/* not enough room				*/
		return 0;
}

/* getline: get line into s, return length			*/
int getline(char *s, int lim) {
	int c;
	char *t = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}







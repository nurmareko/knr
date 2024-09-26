#include <stdio.h>
#include <math.h>

void tail(char *afile[], int n);
int get_start(int lines, int n);
int get_length(char *afile[]);
char **build_file(void);

main(int argc, char *argv[]) {
	int n = 10;
	char **file;

	if (argc > 1) {
		n = atoi(*++argv);
		if (n <= 0)
			return 1;
	}
	file = build_file();
	tail(file, n);
	return 0;
}
/****************************************************************/
/* write the last n lines of afile				*/
void tail(char *afile[], int n) {
	int i, j;
	int length = get_length(afile);
	int start = get_start(length, n);

	for (i = 0; i < length; ++i)
		if (i < start)
			;
		else
			for (j = 0; afile[i][j] != '\0'; ++j)
				if (afile[i][j] == EOF || afile[i][j] == 26)
					;
				else
					putchar(afile[i][j]);
}

/* find out the starting line to write				*/
int get_start(int lines, int n) {
	if (lines <= n)
		return 0;
	else
		return (lines - n);
}

/* find out the length of afile					*/
int get_length(char *afile[]) {
	int i;

	for (i = 0; afile[i] != NULL; ++i)
		;
	return i;
}
/****************************************************************/
#define MAX 10000

/* build array of line from the given standard input		*/
char **build_file(void) {
	char count, ch, i, j, lines, n;
	char str[MAX];

	for (i = 0; (ch = getchar()) != EOF; ++i) {
		if (ch == '\n') {
			str[i] = '\n';
			str[++i] = '\0';
		} else
			str[i] = ch;
	}
	str[i] = EOF;

	for (i = 0, lines = 1; str[i] != EOF; ++i)
		if (str[i] == '\n')
			++lines;

	char *ptr[lines+1];
	ptr[0] = str;
	for (i = 0, j = 1; str[i] != EOF; ++i)
		if (str[i] == '\0') {
			ptr[j] = str + i + 1;
			j++;
		}
	ptr[lines] = NULL;

	char **x = ptr;
	return x;
}


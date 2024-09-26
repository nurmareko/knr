#include <stdio.h>
#include <math.h>

#define MAXIN   10000

void tail(char *afile[], int n);
int get_start(int lines, int n);
int get_length(char *afile[]);
char **build_file(void);
char *build_input(void);
int count_line(char *stream);
char **build_lines(char *stream, int lines);

main(int argc, char *argv[]) {
	int n = 10;
	char **file;

	if (argc > 1) {
		n = atoi(*++argv);
		if (n <= 0)
			return 1;
	} else {
		file = build_file();
		tail(file, n);
		return 0;
	}
}
/****************************************************************/
/* write the last n lines of afile				*/
void tail(char *afile[], int n) {
	int i;
	int length = get_length(afile);
	int start = get_start(length, n);

	for (i = 0; i < length; ++i)
		if (i < start)
			;
		else
			printf(afile[i]);
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
/* build array of line from the given standard input		*/
char **build_file(void) {
	int length;
	char *stream;

	stream = build_input();
	length = count_line(stream);
	return build_lines(stream, length);
}

/* collect characters from standard input			*/
char *build_input(void) {
	int ch, i;
	char str[MAXIN];
	char *ptr = str;

	for (i = 0; (ch = getchar()) != EOF; ++i) {
		if (ch == '\n') {
			str[i] = '\n';
			str[++i] = '\0';
		} else
			str[i] = ch;
	}
	str[i] = EOF;
	return ptr;
}

/* count how many line in the given stream			*/
int count_line(char *stream) {
	int i, lines;

	for (i = 0, lines = 1; stream[i] != EOF; ++i)
		if (stream[i] == '\n')
			++lines;
	return lines;
}

/* build array of line from the given stream and length		*/
char **build_lines(char *stream, int lines) {
	int i, j;
	char *file[lines+1];
	char **ptr = file;

	file[0] = stream;
	for (i = 0, j = 1; stream[i] != EOF; ++i)
		if (stream[i] == '\0') {
			file[j] = stream + i + 1;
			j++;
		}
	file[lines] = NULL;
	return ptr;
}

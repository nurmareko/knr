#include <stdio.h>

#define MAXIN   10000

char **build_file(void);
char *build_input(void);
int count_line(char *stream);

main() {
	int i;
	char **file;

	file = build_file();
	for (i = 0; file[i] != NULL; ++i)
		printf(file[i]);
}

/* build array of line from the given standard input		*/
char **build_file(void) {
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

}



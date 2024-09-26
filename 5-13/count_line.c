#include <stdio.h>

#define MAXIN   10000

char *build_input(void);
int count_line(char*);

main() {
	int len;
	char *stream = build_input();
	
	len = count_line(stream);
	printf("line count: %d\n", len);
	
}

/* count how many line in the given stream			*/
int count_line(char *stream) {
	int i, lines;

	for (i = 0, lines = 1; stream[i] != EOF; ++i)
		if (stream[i] == '\n')
			++lines;
	return lines;
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




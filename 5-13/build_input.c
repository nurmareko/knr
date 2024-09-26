#include <stdio.h>

#define MAXIN   10000

char *build_input(void);

main() {
	int i;
	char *stream;

	stream = build_input();

	for (i = 0; stream[i] != EOF; ++i)
		putchar(stream[i]);
	
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




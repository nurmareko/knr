#include <stdio.h>

#define MAX 10000

main() {
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

	for (i = 0; ptr[i] != NULL; ++i)
		printf(ptr[i]);
}
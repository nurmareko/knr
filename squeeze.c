#include <stdio.h>

void squeeze(char s[], int c);

main() {
	char str[] = "hello";
	
	squeeze (str, 'x');
	printf("%s\n", str);

	return 0;
}

/* String Character -> String 						*/
/* delete all c from s.							*/

void squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
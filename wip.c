#include <stdio.h>
#define MAXCHAR 100

void reverse(char s[]);
void copy(char from[], char to[]);
int string_length(char s[]);
int getline(char line[]);

/* reverse the input a line at a time */
main() {
	int achar;
	int line_length;
	int index;
	char current_line[MAXCHAR];

	while ((line_length = getline(current_line)) > 0) {

		if (line_length > 2) {
			reverse(current_line);
			printf("%s", current_line);
		}
		else
			printf("%s", current_line);
	}
	return 0;
}

/* reverse the given string */
void reverse(char s[]) {
	int length, index_b, index_s;
	char buffer[MAXCHAR];

	length = string_length(s);
	if (length > 1) {
		index_b = 0;
		index_s = --length;
		while (index_b <= length) {
			buffer[index_b] = s[index_s];
			++index_b;
			--index_s;
		}
	copy(buffer, s);
	}
}

/* get the length of the string  */
int string_length(char s[]){
	int index;

	index = 0;
	while (s[index] != '\0')
		++index;
	return index;
}

/* copy string 'from' into 'to' */
void copy(char from[], char to[]) {
	int index;

	index = 0;
	while ((to[index] = from[index]) != '\0')
		++index;
}

/* read a line into s, return length */
int getline(char s[]) {
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

















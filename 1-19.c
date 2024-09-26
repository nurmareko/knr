#include <stdio.h>

void reverse(char s[]);
int string_length(char s[]);
void copy(char from[], char to[]);

main() {
	char example[] = "hello";
	
	printf("input : %s (before)\n", example);
	reverse(example);
	printf("output: %s (after)\n", example);

	return 0;
}

/* reverse the given string */
void reverse(char s[]) {
	int length, index_b, index_s;
	char buffer[100];

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
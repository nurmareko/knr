#include <stdio.h>
#include <string.h>

void reverse(char[]);

main() {
	char example[] = "hello";
	
	printf("input : %s (before)\n", example);
	reverse(example);
	printf("output: %s (after)\n", example);

	return 0;
}

/* reverse: reverse string s					*/
void reverse(char s[]) {
	void reverser(char[], int, int);

	reverser(s, 0, strlen(s));
}

/* reverser: reverse string s, recursive			*/
void reverser(char s[], int i, int len) {
	int c, j;

	j = len - (i + 1);
	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}

}
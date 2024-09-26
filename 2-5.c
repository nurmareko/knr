#include <stdio.h>

#define TRUE  1
#define FALSE 0

int any(char s1[], char s2[]);
int is_member(char c, char str[]);
void check_expect(int a, int b);

main() {


	check_expect(any("", ""), -1);
	check_expect(any("abc", ""), -1);
	check_expect(any("", "abc"), -1);
	check_expect(any("abc", "def"), -1);
	check_expect(any("abc", "a"), 0);
	check_expect(any("abc", "b"), 1);
	check_expect(any("abc", "c"), 2);
	check_expect(any("abc", "c"), 2);
	check_expect(any("def", "ce"), 1);
	check_expect(any("def", "ef"), 1);

	return 0;
}

/* String String -> Int
   return the first location in the string s1 where any character from
   the string s2 occurs. */
int any(char s1[], char s2[]) {
	int i;

	for (i = 0; s1[i] != '\0'; i++)
		if (is_member(s1[i], s2))
			return i;
	return -1;
}

/* Character String -> Int
   is the character c appear in string str? */
int is_member(char c, char str[]) {
	int i;
	
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return TRUE;
	return FALSE;
}

/* Int Int -> String
   check for equality between a and b */
void check_expect(int a, int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value \"%s\" differs from \"%s\", the expected value.\n", a, b);
}
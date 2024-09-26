#include <stdio.h>

enum Boolean {FALSE, TRUE};
void squeeze(char s1[], const char s2[]);
void check_expect(char a[], char b[]);
int is_member(char c, const char str[]);


main() {
	char ex0[] = "";
	char ex1[] = "Put up in a place";
	char ex2[] = "Put up in a place";
	char ex3[] = "Put up in a place";
	char ex4[] = "Put up in a place";
	char ex5[] = "Put up in a place";
	char ex6[] = "Put up in a place";
	char ex7[] = "";

	squeeze(ex0, "");
	check_expect(ex0, "");

	squeeze(ex1, "x");
	check_expect(ex1, "Put up in a place");

	squeeze(ex2, "p");
	check_expect(ex2, "Put u in a lace");

	squeeze(ex3, "Pp");
	check_expect(ex3, "ut u in a lace");

	squeeze(ex4, " ");
	check_expect(ex4, "Putupinaplace");

	squeeze(ex5, "in");
	check_expect(ex5, "Put up  a place");

	squeeze(ex6, "");
	check_expect(ex6, "Put up in a place");

	squeeze(ex7, "put");
	check_expect(ex7, "");
}

/* String String -> String
   deletes each character in s1 that matches any character in the string s2 */
void squeeze(char s1[], const char s2[]){
	int i, j;

	for (i = j = 0; s1[i] != '\0'; i++)
		if (!(is_member( s1[i], s2)))
			s1[j++] = s1[i];
	s1[j] = '\0';
}

/* String String -> String
   check for equality between a and b */
void check_expect(char a[], char b[]) {
	int answer, i;

	answer = TRUE;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == b[i])
			answer = TRUE;
		else
			answer = FALSE;
	}
	if (answer == TRUE)
		printf("The test passed!\n");
	else
		printf("Actual value \"%s\" differs from \"%s\", the expected value.\n", a, b);
}

/* Character String -> Int
   is the character c appear in string str? */
int is_member(char c, const char str[]) {
	int i;
	
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return TRUE;
	return FALSE;
}
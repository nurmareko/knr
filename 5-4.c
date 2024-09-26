#include <stdio.h>
#include <string.h>

enum Boolean {FALSE, TRUE};

void check_expect(int, int);
int  strend(char*, char*);

main() {
	check_expect(strend("", ""), 			TRUE);
	check_expect(strend("a", ""), 			TRUE);
	check_expect(strend("", "b"),			FALSE);
	check_expect(strend("a", "b"), 			FALSE);
	check_expect(strend("a", "a"), 			TRUE);
	check_expect(strend("shiga matcha", "matcha"), 	TRUE);
	check_expect(strend("shiga ramen", "matcha"), 	FALSE);
	check_expect(strend("woman", "man"), 		TRUE);
	check_expect(strend("woman", "mon"), 		FALSE);
	check_expect(strend("woman", "ma"), 		FALSE);
	check_expect(strend("mwoman", "man"), 		TRUE);
	check_expect(strend("ma", "man"), 		FALSE);
	check_expect(strend("ma", "oma"), 		FALSE);
	check_expect(strend("man", "man"), 		TRUE);

	return 0;
}

/* strend: is the string t appear at the end of the string s?	*/
int strend(char *s, char *t) {
	int i = strlen(s);		/* the length of s	*/
	int j = strlen(t);		/* the length of t	*/

	if (j > i) {		/* j must be less than i for	*/
		return 0;	/* t to be appear at the end s  */
	} else {
		s += i - j;
		while(*s)
			if (*s++ != *t++)
				return 0;
		return 1;
	}
}

/* check_expect: is the actual value equal the expected value?	*/
void check_expect(int actual, int expected) {
	if (actual == expected)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", actual, expected);
}

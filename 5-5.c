#include <stdio.h>
#include <string.h>

#define SIZE 10

void strn_cpy(char*, char*, int);
void strn_cat(char*, char*, int);
int  strn_cmp(char*, char*, int);
void test(int, char*, char*, int, char*);
void test_cmp(char*, char*, int, int);
enum Fun {CPY, CAT};

main() {
	printf("strn_cpy test case\n");
	test(CPY, "xxx", "", 	 0, "xxx");
	test(CPY, "xxx", "",	 1, "");
	test(CPY, "xxx", "", 	 5, "");
	test(CPY, "xxx", "a", 	 0, "xxx");
	test(CPY, "xxx", "a", 	 1, "axx");
	test(CPY, "xxx", "a", 	 2, "a");
	test(CPY, "xxx", "yyyy", 3, "yyy");
	test(CPY, "xxx", "yyyy", 4, "yyyy");
	putchar('\n');

	printf("strn_cat test case\n");
	test(CAT, "",    "", 	0, "");
	test(CAT, "",    "", 	1, "");
	test(CAT, "",    "y",	0, "");
	test(CAT, "",    "y", 	1, "y");
	test(CAT, "",    "y",	2, "y");
	test(CAT, "",    "ab", 	0, "");
	test(CAT, "",    "ab", 	1, "a");
	test(CAT, "",    "ab", 	2, "ab");
	test(CAT, "",    "ab", 	3, "ab");
	test(CAT, "ggg", "", 	0, "ggg");
	test(CAT, "ggg", "", 	1, "ggg");
	test(CAT, "xxx", "abc", 0, "xxx");
	test(CAT, "xxx", "abc", 1, "xxxa");
	test(CAT, "xxx", "abc", 2, "xxxab");
	test(CAT, "xxx", "abc", 3, "xxxabc");
	test(CAT, "xxx", "abc", 4, "xxxabc");
	putchar('\n');

	printf("strn_cmp test case\n");
	test_cmp("",     "",     0,  0);
	test_cmp("",     "",     1,  0);
	test_cmp("a",    "",     0,  0);
	test_cmp("a",    "",     1,  97);
	test_cmp("a",    "",     2,  97);
	test_cmp("",     "s",    0,  0);
	test_cmp("",     "s",    1, -115);
	test_cmp("",     "s",    2, -115);
	test_cmp("a",    "b",    0,  0);
	test_cmp("a",    "b",    1, -1);
	test_cmp("a",    "b",    2, -1);
	test_cmp("b",    "a",    0,  0);
	test_cmp("b",    "a",    1,  1);
	test_cmp("b",    "a",    2,  1);
	test_cmp("abx",  "aby",  2,  0);
	test_cmp("Abx",  "aby",  2, -32);
	test_cmp("abx",  "Aby",  2,  32);
	test_cmp("aBx",  "abx",  2, -32);
	test_cmp("aBx",  "Abx",  2,  32);
	test_cmp("this", "that", 4,  8);
	putchar('\n');

	return 0;
}
/****************************************************************/
/* strn_cpy: copies up to n characters from the string		*/
/*	    pointed to, by t to s.				*/
void strn_cpy(char *s, char *t, int n) {	
	while (n--)
		(*t != '\0') ? (*s++ = *t++) : (*s++ = '\0');
}

/* strn_cat: appends up to n character of the string		*/
/*	     pointed to, by t to the end of s 			*/
void strn_cat(char *s, char *t, int n) {
	while (*s)
		s++;
	strn_cpy(s, t, n);
}

/* strn_cmp: compares at most the first n bytes of str1 and str2 */
int strn_cmp(char *s, char *t, int n) {
	if (n == 0) {
		return 0;
	} else {
		for (; *s == *t; s++, t++)
			if (*s == '\0' || --n <= 0)
				return 0;
		return *s - *t;
	}
}
/****************************************************************/
/* test: test case for strn_cpy and strn_cat			*/
void test(int fun, char *initial, char *src, int n, char *expected) {
	char actual[SIZE];

	strncpy(actual, initial, SIZE);
	switch (fun) {
	case CPY:
		strn_cpy(actual, src, n);
		break;
	case CAT:
		strn_cat(actual, src, n);
		break;
	default:
		printf("error: unknown function identifier: %d\n", fun);
	}
	if (0 == strcmp(actual, expected)) {
		printf("The test passed!\n");
	} else
		printf("Actual value %s differs from %s, the expected value.\n", actual, expected);
}

/* test_cmp: test case for strn_cmp				*/
void test_cmp(char *initial1, char *initial2, int n, int expected) {
	char str1[SIZE];
	char str2[SIZE];
	int actual;

	strncpy(str1, initial1, SIZE);
	strncpy(str2, initial2, SIZE);
	printf("before compare str1: %s str2: %s\n", str1, str2);
	actual = strn_cmp(str1, str2, n);
	printf("after compare  str1: %s str2: %s\n", str1, str2);	

	if (actual == expected)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", actual, expected);
}

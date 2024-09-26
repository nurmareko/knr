#include <stdio.h>
#include <ctype.h>
void test (double actual, double expect);
double atof(char s[]);

main() {
	double atof(char s[]);

	test(atof("hello"), 0.0);
	test(atof("  -6"), -6.0);
	test(atof("0"),     0.0);
	test(atof("5"),     5.0);
	test(atof("0.3"),   0.3);
	test(atof(".30"),   0.3);

	return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) 		/* skip white space			*/
		;
	sign = (s[i] == '-' ? -1 : 1); 			/* save sign				*/
	if (s[i] == '+' || s[i] == '-') 		/* skip sign symbol			*/
		i++;
	for (val = 0.0; isdigit(s[i]); i++)		/* process whole number			*/
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')				/* skip decimal symbol			*/
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {		/* process fraction 			*/
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;			/* apply sign 				*/
}

/* test: compare the actual value of atof to the expected value */
void test (double actual, double expect) {
	if (actual == expect)
		printf("The test passed!\n");
	else
		printf("Actual value %f differs from %f, the expected value.\n", actual, expect);
}
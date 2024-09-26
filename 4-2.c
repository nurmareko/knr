#include <stdio.h>
#include <ctype.h>
void test (double actual, double expect);
double atof(char s[]);

main() {
	double xatof(char s[]);

	test(atof("hello"), 0);
	test(atof("  -6"), -6);
	test(atof("0"),     0);
	test(atof("5"),     5);
	test(atof("5.6"),   5.6);
	test(atof("0.3"),   0.3);
	test(atof(".30"),    .3);

	test(atof("0.0e+0"),    0.0);
	test(atof("1.0e+0"),    1.0);
	test(atof("9.0e+2"),  900.0);
	test(atof("0.5e-1"),    0.05);
	test(atof("2.5e+0"),    2.5);
	test(atof("-4.0e+0"),  -4.0);
	test(atof("-6.2e+0"),  -6.2);
	test(atof("123.45e-6"), 0.000123);

	test(atof("0.0E+0"),    0.0);
	test(atof("1.0E+0"),    1.0);
	test(atof("9.0E+2"),  900.0);
	test(atof("0.5E-1"),    0.05);
	test(atof("2.5E+0"),    2.5);
	test(atof("-4.0E+0"),  -4.0);
	test(atof("-6.2E+0"),  -6.2);
	test(atof("   123.E5e-6"), 0.000123);


	return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
	double esign, eval, val, power;
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
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		esign = (s[i] == '-' ? -1 : 1);
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (eval = 0; isdigit(s[i]); i++)
			eval = 10 * eval + (s[i] - '0');
		while (eval-- > 0)
			power = (esign == 1) ? power / 10.0 : power * 10.0;
	}
	return sign * val / power;
}

/* test: compare the actual value of atof to the expected value */
void test (double actual, double expect) {
	if (actual == expect)
		printf("The test passed!\n");
	else
		printf("Actual value %f differs from %f, the expected value.\n", actual, expect);
}
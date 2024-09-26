#include <stdio.h>
#include <math.h>

int htoi(char str[]);
void check_expect(const int a, const int b);
int string_length(char str[]);
int decimal_value(char symbol, int place_power);
int numeric(char c);
int alphabetic_uppercase(char c);
int alphabetic_lowercase(char c);
int have_prefix(char str[]);
int valid_hex(char symbol);

main() {
	check_expect(htoi("@12"), 0);

	return 0;
}

/* String -> Int */
/* compute the value of string representation of hexadecimal. */
int htoi(char str[]) {
	int exponent, i, power, sum;

	sum = 0;

	if (have_prefix(str)) {
		i = 2;
		exponent = string_length(str) - 3;
	}
	else {
		i = 0;
		exponent = string_length(str) - 1;
	}
	printf("i: %d\n", i);

	printf("str[i] = %c\n", str[i]);
	printf("numeric('@') = %d\n", numeric('@'));

	while (str[i] != '\0' && valid(str[i])) {
		sum += decimal_value(str[i], exponent);
		printf("sum: %d\n", sum);
		++i;
		--exponent;
	}
	return sum;
}

/* Int Int -> String */
/* check for equality between a and b */
void check_expect(const int a, const int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}

/* String -> Int */
/* get the length of the given string */
int string_length(char str[]) {
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return i;
}

/* Character Int -> Int */
/* compute (n * 16^e) where n is the decimal value of hexadecimal symbol */
int decimal_value(char symbol, int e) {
	if (numeric(symbol)) {
		printf("inside numeric\n");
		return (symbol - '0') * pow(16, e);
	}
	else if (alphabetic_uppercase(symbol)) {
		printf("insice alpha upper\n");
		return (symbol - '7') * pow(16, e);
	}
	else if (alphabetic_lowercase(symbol)) {
		printf("inside alpha lower\n");
		return (symbol - 'W') * pow(16, e);
	}
	else
		return 0;
}

/* Character -> Int */
/* is c numeric? */
int numeric(char c) {
	printf("(c >= '0' && c <= '9'): %d\n", (c >= '0' && c <= '9'));
	return (c >= '0' && c <= '9');
}

/* Character -> Int */
/* is c uppercased alphabetic? */
int alphabetic_uppercase(char c) {
	return (c >= 'A' && c <= 'F');
}

/* Character -> Int */
/* is c lowecased alphabetic? */
int alphabetic_lowercase(char c) {
	return (c >= 'a' && c <= 'f');
}

/* String -> Int*/
/*is the given string representation of hexadecimal have prefix?*/
int have_prefix(char str[]) {
	return (str[0] == '0' && str[1] == 'x' || str[1] == 'X');
}

/* Character -> Int*/
/* is the given symbol a valid hexadecimal symbol?*/
int valid_hex(char symbol) {
	return (numeric(symbol) && alphabethic_uppercase(symbol) && alphabethic_lowercase(symbol));
}

#include <stdio.h>
#include <math.h>
#include <string.h>
#define ERROR -1

int htoi(char str[]);
void check_expect(const int a, const int b);
int decimal_value(char symbol, int place_power);
int have_prefix(char str[]);
int valid_hex(char symbol);
int numeric(char c);
int alphabetic_uppercase(char c);
int alphabetic_lowercase(char c);

main() {
	check_expect(htoi(""), ERROR);
	check_expect(htoi("xyz"), ERROR);
	check_expect(htoi("@12"), ERROR);

	check_expect(htoi("0"), 0);
	check_expect(htoi("9"), 9);
	check_expect(htoi("a"), 10);
	check_expect(htoi("f"), 15);
	check_expect(htoi("A"), 10);
	check_expect(htoi("F"), 15);
	check_expect(htoi("2f"), 47);
	check_expect(htoi("F00"), 3840);
	check_expect(htoi("123456"), 1193046);

	check_expect(htoi("0x0"), 0);
	check_expect(htoi("0x9"), 9);
	check_expect(htoi("0xa"), 10);
	check_expect(htoi("0xf"), 15);
	check_expect(htoi("0xA"), 10);
	check_expect(htoi("0xF"), 15);
	check_expect(htoi("0x2f"), 47);
	check_expect(htoi("0xF00"), 3840);
	check_expect(htoi("0x123456"), 1193046);

	check_expect(htoi("0X0"), 0);
	check_expect(htoi("0X9"), 9);
	check_expect(htoi("0Xa"), 10);
	check_expect(htoi("0Xf"), 15);
	check_expect(htoi("0XA"), 10);
	check_expect(htoi("0XF"), 15);
	check_expect(htoi("0X2f"), 47);
	check_expect(htoi("0XF00"), 3840);
	check_expect(htoi("0X123456"), 1193046);

	return 0;
}

/* compute the value of string representation of hexadecimal, 
   expect positive value.                                     */
int htoi(char str[]) {
	int exponent, i, power, sum;

	sum = 0;

	if (have_prefix(str)) {
		i = 2;
		exponent = strlen(str) - 3;
	}
	else {
		i = 0;
		exponent = strlen(str) - 1;
	}
	while (str[i] != '\0') {
		if (valid_hex(str[i])) {
			sum += decimal_value(str[i], exponent);
			++i;
			--exponent;
		}
		else
			return ERROR;
	}
	return sum;
}

/* check for equality between a and b */
void check_expect(const int a, const int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}

/* compute (n * 16^e) where n is the decimal value of hexadecimal symbol */
int decimal_value(char symbol, int e) {
	if (numeric(symbol))
		return (symbol - '0') * pow(16, e);
	else if (alphabetic_uppercase(symbol))
		return (symbol - '7') * pow(16, e);
	else if (alphabetic_lowercase(symbol))
		return (symbol - 'W') * pow(16, e);
	else
		return 0;
}

/* is the given string representation of hexadecimal have prefix? */
int have_prefix(char str[]) {
	return (str[0] == '0' && str[1] == 'x' || str[1] == 'X');
}

/* is the given symbol a valid hexadecimal symbol? */
int valid_hex(char symbol) {
	return (numeric(symbol) || alphabetic_uppercase(symbol) || alphabetic_lowercase(symbol));
}

/* is c numeric? */
int numeric(char c) {
	return (c >= '0' && c <= '9');
}

/* is c uppercased alphabetic? */
int alphabetic_uppercase(char c) {
	return (c >= 'A' && c <= 'F');
}

/* is c lowecased alphabetic? */
int alphabetic_lowercase(char c) {
	return (c >= 'a' && c <= 'f');
}
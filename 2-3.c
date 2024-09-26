#include <stdio.h>
#include <math.h>
#include <string.h>

int htoi(char str[]);
void check_expect(const int a, const int b);

main() {
	check_expect(htoi(""), 0);
	check_expect(htoi("xyz"), 0);
	check_expect(htoi("@12"), 0);

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

/* compute the value of string representation of hexadecimal. */
int htoi(char str[]) {
	int exponent, i, power, sum;

	sum = 0;

	if (str[0] == '0' && str[1] == 'x' || str[1] == 'X') {
		i = 2;
		exponent = strlen(str) - 3;
	}
	else {
		i = 0;
		exponent = strlen(str) - 1;
	}

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			sum = sum + (str[i] - '0') * pow(16, exponent);
			++i;
			--exponent;
		}
		else if (str[i] >= 'A' && str[i] <= 'F') {
			sum = sum + (str[i] - '7') * pow(16, exponent);
			++i;
			--exponent;
		}
		else if (str[i] >= 'a' && str[i] <= 'f') {
			sum = sum + (str[i] - 'W') * pow(16, exponent);
			++i;
			--exponent;
		}
		else
			return 0;
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
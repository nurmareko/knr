#include <stdio.h>

/* replace tab, backspace, and backslash with visible characters */
main() {
	int current_char;

	while ((current_char = getchar()) != EOF) {
		if (current_char == '\t')
			printf("\\t");
		if (current_char == '\b')
			printf("\\b");
		if (current_char == '\\')
			printf("\\\\");
		if (current_char != '\b')
			if (current_char != '\t')
				if (current_char != '\\')
					putchar(current_char);
	}
}

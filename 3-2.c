#include <stdio.h>

void escape(char s[], char t[]);
char esc_char(char c);
void test(char given[], char expected[]);
int  escape_sequence(char c);
void unescape(char s[], char t[]);
int unescape_char(char c);

main() {
	char e[1000];
	char u[1000];

	printf("given:\n\"%s\"\n", "");
	escape("", e);
	printf("escaped:\n\"%s\"\n", e);
	unescape(e, u);
	printf("unescaped:\n\"%s\"\n\n", u);

	printf("given:\n\"%s\"\n", "abc def");
	escape("abc def", e);
	printf("escaped:\n\"%s\"\n", e);
	unescape(e, u);
	printf("unescaped:\n\"%s\"\n\n", u);

	printf("given:\n\"%s\"\n", "abd	def");
	escape("abc	def", e);
	printf("escaped:\n\"%s\"\n", e);
	unescape(e, u);
	printf("unescaped:\n\"%s\"\n\n", u);

	return 0;
}

/* converts tab character into visible character
   s: input  string
   t: output string
*/
void escape(char s[], char t[]) {
	int i, j;
	char c, e;

	i = j = 0;
	while (c = s[i++])
		if (e = escape_sequence(c)) {
			t[j++] = '\\';
			t[j++] = e;
		} else
			t[j++] = c;
	t[j] = '\0';
}

/* ... */
int escape_sequence(char c) {
	switch (c) {
	case '\a':
		return 'a';
	case '\b':
		return 'b';
	case '\f':
		return 'f';
	case '\n':
		return 'n';
	case '\r':
		return 'r';
	case '\t':
		return 't';
	case '\v':
		return 'v';
	case '\\':
		return '\\';
	case '\'':
		return '\'';
	case '\"':
		return '\"';
	case '\?':
		return '?';
	default:
		return '\0';
	}
}

void unescape(char s[], char t[]) {
	int i = 0, j = 0;
	char c;
	
	while (c = s[i++])
		if (c == '\\') {
			t[j++] = unescape_char(s[i++]);
		} else
			t[j++] = c;
	t[j] = '\0';
}

/* ... */
int unescape_char(char c) {
	switch (c) {
	case 'a':
		return '\a';
	case 'b':
		return '\b';
	case 'f':
		return '\f';
	case 'n':
		return '\n';
	case 'r':
		return '\r';
	case 't':
		return '\t';
	case 'v':
		return '\v';
	case '\\':
		return '\\';
	case '\'':
		return '\'';
	case '\"':
		return '\"';
	case '?':
		return '\?';
	default:
		return '\0';
	}
}







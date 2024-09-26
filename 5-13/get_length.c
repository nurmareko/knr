#include <stdio.h>

int get_length(char* []);

main() {
	int len;
	char *ptr_a[3] = {"\n", "goodbye\n", NULL};
	char *ptr_b[2] = {"hello", NULL};
	char *ptr_c[1] = {NULL};

	len = get_length(ptr_a);
	printf("len a: %d\n", len);

	len = get_length(ptr_b);
	printf("len b: %d\n", len);

	len = get_length(ptr_c);
	printf("len c: %d\n", len);
}

/* find out the length of afile					*/
int get_length(char *afile[]) {
	int i;

	for (i = 0; afile[i] != NULL; ++i)
		;
	return i;
}
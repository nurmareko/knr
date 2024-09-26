#include <stdio.h>

char *month_name(int);

main() {
	char *x;

	x = month_name(3);

	printf("%s\n", x);
	printf("%s\n", x);
	printf("%s\n", x);

	return 0;
}

/* month_name: return name of n-th month			*/
char *month_name(int n) {
	  static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April",   "May",      "June",
		"July",    "August",   "September",
		"October", "November", "December"
	};
	
	return (n < 1 || n > 12) ? name[0] : name[n];
}
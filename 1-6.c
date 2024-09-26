#include <stdio.h>

/* show the value of getchar() */
main(){
	int x;

	printf("%d\n", (x = getchar()) != EOF);
}
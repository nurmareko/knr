#include <stdio.h>
#include <math.h>

main(int argc, char *argv[]) {
	int n = 10;
	char *file[...];

	if (argc > 1)
		n = atoi(*++argv);
	build_lines(file);
	tail(file, n);
	return 0;
}

/* build array of line from the given standard input		*/
char *build_lines() {

}

/* write the last n lines of afile				*/
void tail(char *afile[], int n) {
	int i;
	int length = get_length(afile);
	int start = get_start(length, n);

	for (i = 0; i < length; ++i)
		if (i < start)
			;
		else
			printf(afile[i]);
}

/* find out the starting index for tail				*/
int get_start(int length, int n){
	if (length <= n)
		return length;
	else
		return (length - n + 1);
}

/* find out the length of afile					*/
int get_length(char *afile[]) {
	int count;

	for (count = 0; *afile++ != NULL; ++count)
		;
	return count;
}

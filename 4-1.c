/* Exercise 4-1
 *
 * Write a function strrindex(s, t), which returns the position of the 
 * rightmost occurence of t in s or -1 if there is none.
 */

#include <stdio.h>

void check_expect(int a, int b);
int strrindex(char s[], char t[]);

int main(void){
	check_expect(strrindex("", ""), -1);
	check_expect(strrindex("the apple, the orange", ""), -1);
	check_expect(strrindex("", "the"), -1);

	check_expect(strrindex("the apple, the orange", "and"), -1);
	check_expect(strrindex("the apple, the orange", "the"), 11);

	return 0;
}

/* Int Int -> String
   check for equality between a and b */
void check_expect(int a, int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}

int strrindex(char s[], char t[]){
	int i, j, k, rslt = -1;

	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			rslt = i;
	}
	return rslt;
}
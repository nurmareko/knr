#include <stdio.h>

int binsearch(int x, int v[], int n);
void check_expect(int a, int b);

main(){
	int alist[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	check_expect(binsearch(0, alist, 9), -1);
	check_expect(binsearch(1, alist, 9), 0);
	check_expect(binsearch(5, alist, 9), 4);
	check_expect(binsearch(10, alist, 9), -1);

	return 0;
}

/* Int Array Int -> Int
   find x in v[0] <= v[1] <= ... <= v[n-1]
*/
int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* Int Int -> String
   check for equality between a and b
*/
void check_expect(int a, int b) {
	if (a == b)
		printf("The test passed!\n");
	else
		printf("Actual value %d differs from %d, the expected value.\n", a, b);
}
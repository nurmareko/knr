#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
void check_expect(int a, int b);

main(){
	clock_t start_t, end_t;
	double total_t;
	int alist[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	/* original binsearch */
	start_t = clock();
	check_expect (binsearch (  1, alist, 10), -1);
	check_expect (binsearch (  9, alist, 10), -1);
	check_expect (binsearch ( 10, alist, 10),  0);
	check_expect (binsearch ( 50, alist, 10),  4);
	check_expect (binsearch (101, alist, 10), -1);
	check_expect (binsearch (200, alist, 10), -1);
	end_t = clock();
	total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
	printf("k&r original binsearch\n");
	printf("Total time taken by CPU: %f\n\n", total_t);

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
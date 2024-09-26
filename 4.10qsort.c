#include <stdio.h>

void qsort(int[], int, int);
void swap(int[], int, int);

main() {
	int i;
	int tuples[5] = {4, 3, 1, 5, 2};

	printf("original: ");
	for(i = 0; i < 5; i++)
		printf("%d ", tuples[i]);
	putchar('\n');

	qsort(tuples, 0, 5);

	printf("sorted  : ");
	for(i = 0; i < 5; i++)
		printf("%d ", tuples[i]);
	putchar('\n');

    	return 0;
}

/* qsort: sort v[left] ...v[right] into increasing order    	*/
void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int[] ,int ,int);

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements	*/
	swap(v, left, (left+right)/2);	/* move partition elem	*/
	last = left;
	for (i = left+1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elements 	*/
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j]				*/
void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
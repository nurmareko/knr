#include <stdio.h>
#include <stdlib.h>

struct counter {char *word; int count;};

struct counter **build_data(void);
void sort_data(struct counter **data);
void print_data(struct counter **data);

main() {
	struct counter **data;

	data = build_alod();
	sort_data(data);
	print_data(data);
	return 0;
}

struct counter **build_data(void) {}

void sort_data(struct counter **data) {}

void print_data(struct counter **data) {}
#include <stdio.h>
#include <stdlib.h>

struct counter {char *word; int count;};

main() {
	int index;
	struct counter data[] = {
	"madame", 2,
	"monsieur", 1,
	"croque", 3,
	NULL
	};
	
	index = 3;
	printf("%d\t%s\n", data[index].count, data[index].word);
}


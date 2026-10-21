#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sizearray 10

void tree(int nlines);
void line(int nchar, int ntotalchar);
void usage();

int main(int argc, char *argv[]) {
	if (argc != 2) {
		usage();
		return EXIT_FAILURE;
	}

	char input[sizearray];
	size_t size_input = strlen(argv[1]);
	if (size_input <= sizearray) {
		memcpy(input, argv[1], size_input);
	} else {
		usage();
		return EXIT_FAILURE;
	}
	// check if input is a number
	for (int i = 0; i < size_input; i++) {
		if (isdigit(input[i]) == false) {
			usage();
			return EXIT_FAILURE;
		}
	}
	int size_tree = atoi(input);
	if (size_tree > 50) {
		usage();
		return EXIT_FAILURE;
	}
	tree(size_tree);
	return EXIT_SUCCESS;
}

void tree(int nlines) {
	for (int i = 1; i <= nlines; i++)
		line(nlines - i, i);
}

void line(int nspace, int nstar) {
	for (int space = 0; space < nspace; space++)
		printf(" ");
	for (int star = 1; star < 2 * nstar; star++)
		printf("*");
	printf("\n");
}

void usage() {
	printf(
	    "Usage : \ntree [n]\nDraws a tree of size n. n being the number of "
	    "lines\nn should be a positive integer, smaller or equals to 50\n");
}

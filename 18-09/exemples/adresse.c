#include <stdio.h>

int main(void) {
	int val = 42;
	printf("Value: %d\n", val);
	printf("Memory Address: %p\n", (void *)&val);
	printf("Size in Bytes: %zu\n", sizeof(val));
	return 0;
}

#include <stdio.h>

int main(void) {
	int sum = 0xff;
	printf("Value: %d\n", sum);
	printf("Memory Address: %p\n", &sum);
	printf("Size in Bytes: %zu\n", sizeof(sum));
	return 0;
}

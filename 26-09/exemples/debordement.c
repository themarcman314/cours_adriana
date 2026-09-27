#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t fonction(void) {
	static uint8_t a = 0;
	a = a + 1;
	return a;
}

int main(void) {
	while (1) {
		printf("valeur: %hu\n", (uint16_t)fonction());
	}
	return EXIT_SUCCESS;
}

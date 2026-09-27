#include <stdint.h>
#include <stdio.h>

uint8_t fibonacci(uint8_t iterations) {
	uint32_t a = 1;
	uint32_t b = 2;
	uint32_t r = 0;

	for (uint8_t i = 0; i < iterations; i++) {
		r = a + b; // calcule le nouveau nombre dans la suite
		a = b,
		b = r; // on décale les réactifs a et b pour le prochain
		       // calcul
		printf("%u\n", r);
	}
	// printf("%u\n", r);
	// printf("%u\n", r & 0xff);
	return r;
}

int main(void) {
	uint8_t var = fibonacci(11);
	// printf("%u\n", var);
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	uint32_t r = 0xffff;
	printf("valeur de r avant masque: %d\n", r);
	r = r & 255;
	printf("valeur de r après masque: %d\n", r);

	return EXIT_SUCCESS;
}

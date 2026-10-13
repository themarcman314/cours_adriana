#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void add_val(void) {
	static int ind_moy = 0;
	printf("valeur de var: %d\n", ind_moy++);
}

int main(void) {

	while (1) {
		add_val();
		sleep(1);
	}

	return EXIT_SUCCESS;
}

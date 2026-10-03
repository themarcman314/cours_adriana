#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = tab;

	char message[] = "Bonjour je m'appelle Marc!";
	char *p_message = message;

	// printf("Valeur pointée par p: %d\n", *(p + 0));
	printf("Valeur pointée: %c\n", *(p_message + 1));

	int mon_nombre_preferee = 0xff;
	printf("mon nombre preferee en notation binaire: %b\n",
	       mon_nombre_preferee);

	return EXIT_SUCCESS;
}

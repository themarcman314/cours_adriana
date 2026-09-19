#include <stddef.h>
#include <stdio.h>

int main(void) {
	int a = 2;
	// l'opérateur sizeof permet de mesurer la taille de variables
	size_t taille_variable = sizeof a;

	// mais aussi de types
	size_t taille_type = sizeof(short);

	printf("Taille de la variable a: %zu octets (ou bytes)\n",
	       taille_variable);
	printf("Taille du type 'short': %zu octets (ou bytes)\n", taille_type);
}

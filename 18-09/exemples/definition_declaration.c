#include <stdio.h>

// déclaration de fonction
int somme(int a, int b);

int main(void) {
	// déclaration et définition de variable
	int a;

	// initialisation de variable
	a = 2;

	// déclaration, définition et initialisation de variable
	int b = 5;
	printf("resultat: %d\n", somme(a, b));
	somme(a, b);
}

// définition de fonction
int somme(int a, int b) { return (a + b); }

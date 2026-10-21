#include <stdio.h>

struct maison {
	int prix;
	int age;
	float hauteur;
	char nom[20];
};

void imprimer_valeurs_maison(struct maison m) {
	printf("ma maison a %d ans\n", m.age);
	printf("ma maison coûte %d euros\n", m.prix);
	printf("ma maison a %f m d'hauteur\n", m.hauteur);
}

int main(void) {
	struct maison ma_maison = {.prix = 200000, .age = 10, .hauteur = 42.1};

	imprimer_valeurs_maison(ma_maison);
}

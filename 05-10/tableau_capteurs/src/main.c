#include "uart.h"
#include <stdio.h>

/*
 * Capteurs:
 * 	- Pression atmosphérique (I2C ou SPI)
 * 	- Température de l'air (I2C ou SPI)
 * 	- Hygrométrie (I2C ou SPI)GPS (UART)
 * 	- Luminosité (analogique)
 */

enum {
	PRESSION,
	TEMPERATURE,
	HYGROMETRIE,
	GPS,
	LUMINOSITE,
	Nb_Capteurs
};

#define Indice_max_Tableau 5

// On choisit de garder les tableaux en global pour permettre
// Un accès depuis la fonction Decalage

// les tableaux sont initilisés à 0 (segment Bss)
int Tab_Capteur_Pression[Indice_max_Tableau];
int Tab_Capteur_Temperature[Indice_max_Tableau];
int Tab_Capteur_Hygrometrie[Indice_max_Tableau];
int Tab_Capteur_Gps[Indice_max_Tableau];
int Tab_Capteur_Luminosite[Indice_max_Tableau];

/* 
 * Effectue la lecture de mesure pour chaque capteur et
 * note les erreures dans `tab_erreurs`
 */
void Lecture_Capteurs(int tab_mesures[], int tab_erreurs[]);

/* 
 * Vérifie l'état d'erreur pour les mesures de chaque capteur.
 * Si il n'y a pas d'erreur on m-a-j les mesures
 * en faisant un appel au décalage de mesure
 */
void Maj_Mesures(int tableau[], int erreur[]);

/* 
 * Décale les mesures de moyenne mobile d'un indice de tableau
 * dans le sens décroissant (FIFO), en intégrant la nouvelle mesure
 * Effectue le décalage sur `nouveau_tableau` pour ne pas écraser de données
 */
int Decalage(int tableau[], int nouvelle_mesure);

/* 
 * Calcule une moyenne instantané pour un tableau de mesures
 */
float Calcul_Moy_Instant(int tableau[]);


void imprimer_tableau(int *tab, size_t taille_tab) ;
void test_fonctions(int *Tab_Mesures, int *Tab_Erreur, int *Tab_Moy_Instant, size_t taille_mes, size_t taille_err);


int main(void){
	board_init();

	int Tab_Mesures[Nb_Capteurs] = {0};
	int Tab_Erreur[Nb_Capteurs] = {0};
	float Tab_Moy_Instant[Nb_Capteurs] = {0};

	// test des fonctions une à une dans le détail
	#ifdef TEST_DETAILLE
	test_fonctions(Tab_Mesures, Tab_Erreur, Tab_Moy_Instant, sizeof Tab_Mesures / sizeof Tab_Mesures[0], sizeof Tab_Erreur / sizeof Tab_Erreur[0]);
	#endif

	while(1) {
		Lecture_Capteurs(Tab_Mesures, Tab_Erreur);
		Maj_Mesures(Tab_Mesures, Tab_Erreur);
		Tab_Moy_Instant[PRESSION] = Calcul_Moy_Instant(Tab_Capteur_Pression);
		Tab_Moy_Instant[HYGROMETRIE] = Calcul_Moy_Instant(Tab_Capteur_Hygrometrie);
		Tab_Moy_Instant[GPS] = Calcul_Moy_Instant(Tab_Capteur_Gps);
		Tab_Moy_Instant[LUMINOSITE] = Calcul_Moy_Instant(Tab_Capteur_Luminosite);
		Tab_Moy_Instant[TEMPERATURE] = Calcul_Moy_Instant(Tab_Capteur_Temperature);

		printf("Moyenne instantanée temp: %f\n", Tab_Moy_Instant[TEMPERATURE]);
		HAL_Delay(1000);
	}

}

void Lecture_Capteurs(int tab_mesures[], int tab_erreurs[]) {
	int etat_mesure = HAL_OK; // la mesure c'est bien passé
	int Mesure_capteur = 2; // valeur utilisée pour simuler le capteur
	for(int i = 0; i < Nb_Capteurs; i++) {
		if(etat_mesure == HAL_OK) {
			tab_mesures[i] = Mesure_capteur;
		}
		else tab_erreurs[i] = 1;
	}
}

/* 
 * Vérifie l'état d'erreur pour les mesures de chaque capteur.
 * Si il n'y a pas d'erreur on m-a-j les mesures
 * en faisant un appel au décalage de mesure
 */
void Maj_Mesures(int Tableau[], int Erreur[]) {
	// puisqu'on attend "une instruction par tableau de capteur"...
	// ... une boucle avec un tableau 2D serait beacoup mieux adapté...

    if (Erreur[TEMPERATURE] != 1)
        Decalage(Tab_Capteur_Temperature, Tableau[TEMPERATURE]);

    if (Erreur[HYGROMETRIE] != 1)
        Decalage(Tab_Capteur_Hygrometrie, Tableau[HYGROMETRIE]);

    if (Erreur[PRESSION] != 1)
        Decalage(Tab_Capteur_Pression, Tableau[PRESSION]);

    if (Erreur[GPS] != 1)
        Decalage(Tab_Capteur_Gps, Tableau[GPS]);

    if (Erreur[LUMINOSITE] != 1)
        Decalage(Tab_Capteur_Luminosite, Tableau[LUMINOSITE]);
}


/* 
 * Décale les mesures de moyenne mobile d'un indice de tableau
 * dans le sens décroissant (FIFO), en intégrant la nouvelle mesure
 * Attention! la fonction est destructive et écrase les valeurs existantes sur `tableau`
 */
int Decalage(int tableau[], int nouvelle_mesure) {
	for (int i = 0; i < Indice_max_Tableau - 1; i++) {
		tableau[i] =  tableau[i+1];
	}
	tableau[Indice_max_Tableau - 1] = nouvelle_mesure;
}

/* 
 * Calcule une moyenne instantané pour un tableau de mesures
 */
float Calcul_Moy_Instant(int tableau[]) {
	float moyenne;
	for(int i = 0; i < Indice_max_Tableau; i++) {
		moyenne += tableau[i];
	}
	return moyenne / (float)Indice_max_Tableau;
}

void imprimer_tableau(int *tab, size_t taille_tab) {
	printf("{ ");
	for(size_t i = 0; i < taille_tab; i++) {
		printf("%d ", tab[i]);
	}
	printf("}\n");
}

void test_fonctions(int *Tab_Mesures, int *Tab_Erreur, int *Tab_Moy_Instant, size_t taille_mes, size_t taille_err) {

	printf("Tableau Mesures:\n");
	imprimer_tableau(Tab_Mesures, taille_mes);

	printf("Lecture capteurs...\n");
	Lecture_Capteurs(Tab_Mesures, Tab_Erreur);

	printf("Tableau Mesures:\n");
	imprimer_tableau(Tab_Mesures, taille_mes);

	printf("Tableau Erreur:\n");
	imprimer_tableau(Tab_Erreur, taille_err);

	printf("Tableau Température avant décalage:\n");
	imprimer_tableau(Tab_Capteur_Temperature, sizeof Tab_Capteur_Temperature / sizeof Tab_Capteur_Temperature[0]);

	Maj_Mesures(Tab_Mesures, Tab_Erreur);
	float moy_temp = Calcul_Moy_Instant(Tab_Capteur_Temperature);

	printf("Tableau Température après 1er décalage:\n");
	imprimer_tableau(Tab_Capteur_Temperature, sizeof Tab_Capteur_Temperature / sizeof Tab_Capteur_Temperature[0]);
	printf("moy temp: %f\n", moy_temp);

	Maj_Mesures(Tab_Mesures, Tab_Erreur);
	moy_temp = Calcul_Moy_Instant(Tab_Capteur_Temperature);

	printf("Tableau Température après 2eme décalage:\n");
	imprimer_tableau(Tab_Capteur_Temperature, sizeof Tab_Capteur_Temperature / sizeof Tab_Capteur_Temperature[0]);
	printf("moy temp: %f\n", moy_temp);

}
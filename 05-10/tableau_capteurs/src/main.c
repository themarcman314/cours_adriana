#include "uart.h"
#include <stdio.h>

/*
* - Pression atmosphérique (I2C ou SPI)
* - Température de l'air (I2C ou SPI)
* - Hygrométrie (I2C ou SPI)GPS (UART)
* - Luminosité (analogique)
*/
#define Nb_Capteurs 4

// #define capteur_pression 0 
// #define capteur_temperature 1
// #define capteur_hygrometrie 
// #define capteur_luminosite 3

enum {
	capteur_pression,
	capteur_temperature,
	capteur_hygrometrie,
	capteur_gps,
	capteur_luminosite,
};

#define add(x, y) x+y

#define Indice_max_Tableau 5

int Tab_Mesures[Nb_Capteurs - 1];
int Tab_Erreur[Nb_Capteurs - 1];
int Tab_Moy_Instant[Nb_Capteurs - 1];


int Tab_Capteur_0[Indice_max_Tableau];
int Tab_Capteur_1[Indice_max_Tableau];
int Tab_Capteur_2[Indice_max_Tableau];
int Tab_Capteur_3[Indice_max_Tableau];


// void Lecture_Capteurs();
// void Maj_Mesures(int Tableau[], int Erreur[]);
// int *decalage(int Tableau[], int Erreur[]);
// Moy_Tableau Calcul_Moy_Instant(Tableau[])


int main(void){
	board_init();

	printf("Hello! %d\r\n", capteur_luminosite);

	printf("somme de a et b: %d\r\n",add(1,34));

	// while(1) {
	// 	Lecture_Capteurs();
	// 	Maj_Mesures(2,4)
	// 	Calcul_Moy_Instant(Tab_Capteur_0);
	// 	Calcul_Moy_Instant(Tab_Capteur_1);
	// 	Calcul_Moy_Instant(Tab_Capteur_2);
	// 	Calcul_Moy_Instant(Tab_Capteur_3);

	// }

}


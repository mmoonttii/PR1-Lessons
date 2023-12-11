/// Include
#include <stdio.h>
/// Macro
#define NUM_SEMI 4
#define LEN_STR 20
#define NUM_CARTE 40
/// Tipi


//enum seme {CUORI, QUADRI, PICCHE, FIORI}; 1. Si potrebbe fare così
typedef enum {CUORI, QUADRI, PICCHE, FIORI} Seme; // facendo così creiamo un nuovo tipo

typedef struct { // Struttura, agglomerati di tipi differenti
	int num;
	Seme seme;
} Carta;

typedef struct {
	float peso;
	int altezzaCm;
	char cognome[LEN_STR + 1];
} Calciatore;

/// Subroutines

int tipi(){
//	enum seme carta; 1. e creare la var carta con tipo enum seme
	/// ===========================================================
	Seme carta = CUORI;
	char strCarte[NUM_SEMI][LEN_STR + 1] = {"Cuori",
											"Quadri",
											"Picche",
											"Fiori"};

	printf("La mia carta è del seme %d", carta);
	// Per effettivamente stampare il nome del seme devo fare uno switch [CHE POSSIAMO METTERE IN UNA SUBROUTINE]
	switch (carta) {
		case CUORI:
			printf("\nLa mia carta è cuori");
			break;
		case QUADRI:
			printf("\nLa mia carta è quadri");
			break;
		case PICCHE:
			printf("\nLa mia carta è picche");
			break;
		case FIORI:
			printf("\nLa mia carta è fiori");
			break;
	}
	// Oppure posso creare un array di stringhe e accedere ai vari semi utilizzando gli enum come inidici
	printf("\n%s", strCarte[carta]);

	Carta carta1 = {10, CUORI}; // possiamo inizializzarli in dichiarazione
	// o tipo per tipo
	carta1.num = 13;
	carta1.seme = CUORI;

	printf("\nLa carta1 è il %d di %s", carta1.num, strCarte[carta1.seme]);

	Carta mazzo[NUM_CARTE]; // un mazzo è un array di carte
	/// ===========================================================


	Calciatore c1 = {90, 195, "Pavoletti"},
			   c2;

	c2 = c1;
	printf("\nNome c2 è %s", c2.cognome); // POSSO COPIARE STRINGHE SE APPARTENGONO A UNA STRUCT

	Calciatore squadra[20];

	squadra[5].cognome;
    return 0;
}
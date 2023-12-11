/**  Definire una enumerazione che rappresenti il gruppo sanguigno GS (A, B, ZERO, AB).
	Definire poi una struttura che contenga i dati di una Persona (età, peso in kg, altezza in cm) e
	successivamente una struttura Donatore che contenga un campo Persona, un campo enumerazione GS,
	un intero, rappresentante il numero di giorni trascorsi dall'ultima donazione, e un intero rappresentante il
	codice identificativo del donatore di sangue. Realizzare un programma in cui viene dichiarato un array di
	donatori di lunghezza a piacere e, dopo aver inserito i dati di ogni donatore, il programma deve stabilire se
	ognuno di essi può donare il sangue. In particolare:
	• Se il peso è inferiore a 50 kg, non è possibile
	• Se l'ultima donazione è stata fatta prima di 90 giorni, non è possibile.
	• Se l'età è inferiore a 18 anni o maggiore di 65, non è possibile.
	• È possibile in tutti gli altri casi.
	• Stampare, come output, tutti i dati dei pazienti che possono donare il sangue, precisando il perché è possibile
 */


#include <stdio.h>
#include <stdbool.h>

#define DIM 5

typedef enum {A, B, ZERO, AB} GS;

typedef struct{
	int eta;
	float pesoKg;
	int altezzaCm;
} Persona;

typedef struct {
	Persona persona;
	GS gruppo;
	int giorni;
	int codice;
} Donatore;

void popolaArray(int dim, Donatore donatori[]);

bool donazioneCheck(Donatore donatore);

int main(){
	Donatore donatori[DIM];
	bool donazione[DIM];

	popolaArray(DIM, donatori);

	for (int i = 0; i < DIM; ++i) {
		donazione[i] = donazioneCheck(donatori[i]);
	}

    return 0;
}

void popolaArray(int dim, Donatore donatori[]) {
	printf("\n==Donatori==");

	for (int i = 0; i < dim; ++i) {
		printf("Id Donatore: %d", i);
		donatori[i].codice = i;

		printf("\nEtà donatore [int]:");
		scanf("%d", donatori[i].persona.eta);

		printf("\nPeso donatore [kg]: ");
		scanf("%f", donatori[i].persona.pesoKg);

		printf("\nAltezza donatore [cm]:");
		scanf("%f", donatori[i].persona.altezzaCm);

		printf("\nGruppo sanguigno"
			   "\n[0] A"
			   "\n[1] B"
			   "\n[2] ZERO"
			   "\n[3] AB: ");
		scanf("%d", donatori[i].gruppo);

		printf("\nGiorni dall'ultima donazione [int]: ");
		scanf("%d", donatori[i].giorni);

		printf("\n==Fine donatore %d==\n", i);
	}
}

bool donazioneCheck(Donatore donatore) {
/*	• Se il peso è inferiore a 50 kg, non è possibile
	• Se l'ultima donazione è stata fatta prima di 90 giorni, non è possibile.
	• Se l'età è inferiore a 18 anni o maggiore di 65, non è possibile.
	• È possibile in tutti gli altri casi.
 */
	bool check = true;

	if (donatore.persona.pesoKg < 50){
		check = false;
	}

	if (donatore.giorni < 90) {
		check = false;
	}

	if (donatore.persona.eta < 18 || donatore.persona.eta > 65) {
		check = false;
	}
	return check;
}

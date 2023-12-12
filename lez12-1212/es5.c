/*  Definire una struttura albergo, composta da numeroStanze, prezzo, localita
	Acquisire i dati attraverso procedura e stamparli attraverso una procedura, usando indirizzi di memoria
	La struttura va allocata dinamicamente
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 31

typedef struct {
	int numeroStanze;
	float prezzo;
	char localita[LEN + 1];
} Albergo;


void acquisisciAlbergo(Albergo *albergo);
void printAlbergo(Albergo *albergo);

int main(){

	Albergo *alberghi = NULL;
	int nAlberghi;

	// Chiedo n alberghi e mi assicuro sia positivo
	printf("Quanti alberghi? ");
	scanf("%d", &nAlberghi);
	nAlberghi = abs(nAlberghi);
	printf("Genero %d alberghi\n", nAlberghi);

	//Allocazione alberghi
	alberghi = (Albergo *) calloc(nAlberghi, sizeof(Albergo));
	if (alberghi == NULL) {
		exit(1);
	}

	// Acquisizione di ogni albergo
	for (int i = 0; i < nAlberghi; ++i) {
		acquisisciAlbergo(&alberghi[i]);
	}
	// Stampa di ogni albergo
	for (int i = 0; i < nAlberghi; ++i) {
		printAlbergo(&alberghi[i]);
	}


	if (alberghi != NULL){
		free(alberghi);
		alberghi = NULL;
	}
    return 0;
}

void acquisisciAlbergo(Albergo *albergo) {
	printf("Numero Stanze: ");
	scanf("%d", &albergo->numeroStanze);
	// Dovremmo fare dei controlli

	printf("Prezzo per notte");
	scanf("%f", &albergo->prezzo);

	printf("Località: ");
	scanf(" %[^\n]31s", albergo->localita);
}

void printAlbergo(Albergo *albergo) {

	printf("==Albergo=="
		   "\n\tNumero stanze: %d"
		   "\n\tPrezzo per notte: %.2f"
		   "\n\tLocalità: %s",
		   albergo->numeroStanze, albergo->prezzo, albergo->localita);
}


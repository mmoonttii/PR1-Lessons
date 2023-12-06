/** Scrivere la definizione di tipi appropriati per gruppi sanguigni (distinguendo gurppo e rh),
 * La sequenza dei nostri esami considerando che ogni esame ha un nome, un docente, un voto, una data di svolgimento
 * L'insieeme delle taflie di un negozio dalla s alla 3xl
*/

#include <stdio.h>

#define LEN_NOME 20

typedef enum {ZERO, A, B, AB} Gruppo;
typedef enum {POS, NEG} Rh;


typedef struct{
	Gruppo gruppo;
	Rh rh;
} Sangue;

typedef enum {GEN = 1, FEB, MAR, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC} Mese;

typedef struct {
	int anno;
	Mese mese;
	int giorno;
} Data;

typedef struct {
	char nome[LEN_NOME + 1];
	char docente[LEN_NOME + 1];
	int voto;
	Data data;
} Esame;

typedef enum {S, M, L, XL, XXL, XXXL} Taglia;

Esame acquisisciEsame();
void stampaEsame(Esame esame);

int es1(){
	Esame esame = acquisisciEsame();
	stampaEsame(esame);
    return 0;
}

Esame acquisisciEsame() {
	Esame esame;

	// Acquisizione
	printf("\nInserisci nome: ");
	scanf(" %[^\n]20s", esame.nome);

	printf("\nInserisci docente: ");
	scanf(" %[^\n]20s", esame.docente);

	do {
		printf("\nInserisci voto: ");
		scanf(" %d", &esame.voto);
	} while (esame.voto < 0 || esame.voto > 30);

	printf("\nInserisci anno: ");
	scanf(" %d", &esame.data.anno);

	printf("\nInserisci mese: ");
	scanf(" %d", &esame.data.mese);

	printf("\nInserisci giorno: ");
	scanf(" %d", &esame.data.giorno);

	return esame;
}

void stampaEsame (Esame esame){
	printf("\nNome: %s", esame.nome);
	printf("\nDocente: %s", esame.docente);
	printf("\nVoto: %d", esame.voto);
	printf("\nData: %d/%d/%d", esame.data.giorno, esame.data.mese, esame.data.anno);
}


/*  Risolvere il seguente esercizio, composto dai seguenti sotto esercizi:
	1. Scrivere un'enumerazione GiornoSettimana che rappresenti i 7 giorni della settimana (da LUN a DOM) e
    un'enumerazione Mese che rappresenti i 12 mesi dell'anno (da GEN a DIC)
	2. Scrivere un tipo di dato struttura Data composto dai seguenti quattro campi: giorno, giornoSettimana, mese e
    anno. Giorno è di tipo intero, giornoSettimana è di tipo enumerazione GiornoSettimana, mese è di tipo enumerazione
    Mese, mentre anno è un intero.
	3. Scrivere un tipo di dato struttura Persona, costituito dai campi nome, cognome, luogo di nascita, data di
    nascita. I primi tre campi sono stringhe, mentre l'ultimo è di tipo Data.
	4. Scrivere una funzione acquisisciPersona, che dichiari una struttura Persona e richieda in input all'utente i
    dati d’interesse. Effettuare i controlli ritenuti opportuni per acquisire date valide. Tale funzione deve restituire
    la struttura appena acquisita.
	5. Scrivere una procedura stampaDatiPersona che, ricevuta una Persona come parametro, stampi tutti i suoi dati
    d’interesse.
	6. Nel main, dichiarare una struttura Persona, a cui assegnare l'output di acquisisciPersona;
	dopodiché stampare i suoi dati di interesse mediante la procedura stampaDatiPersona
 */

#include <stdio.h>

#define LEN 20

typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} GiornoSettimana;

typedef enum {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} Mese;

typedef struct {
	int giorno;
	GiornoSettimana giornoSettimana;
	Mese mese;
	int anno;
} Data;

typedef struct {
	char nome[LEN + 1];
	char cognome[LEN + 1];
	char luogoNascita[LEN + 1];
	Data dataNascita;
} Persona;

Data acquisisciData();
Persona acquisisciPersona();
void stampaDatiPersona(Persona persona);

int main(){
	Persona persona;
	persona = acquisisciPersona();

	stampaDatiPersona(persona);
    return 0;
}

Persona acquisisciPersona() {
	Persona persona;
	Data data;

	printf("Inserisci\n"
		   "Nome: ");
	scanf(" %[^\n]20s", persona.nome);
	printf("Cognome: ");
	scanf(" %[^\n]20s", persona.cognome);
	printf("Luogo di Nascita: ");
	scanf(" %[^\n]20s", persona.luogoNascita);

	printf("Data di Nascita:");
	persona.dataNascita = acquisisciData();
	return persona;
}

Data acquisisciData() {
	Data data;

	do {
		printf("\nInserisci giorno: ");
		scanf("%d", &data.giorno);
	} while (data.giorno < 1 || data.giorno > 31);

	do {
		printf("\nInserisci giorno della settimana"
			   "\n[0 - 6] Lun - Dom: ");
		scanf("%d", &data.giornoSettimana);
	} while (data.giornoSettimana < 0 || data.giornoSettimana > 6);

	do {
		printf("\nInserisci mese: ");
		scanf("%d", &data.mese);
	} while (data.mese < 1 || data.mese > 12);

	printf("\nInserisci anno: ");
	scanf("%d", &data.anno);

	return data;
}

void stampaDatiPersona(Persona persona) {
	printf("\nNome: %s"
		   "\nCognome: %s"
		   "\nLuogo di Nascita: %s"
		   "\nData di Nascita: ", persona.nome, persona.cognome, persona.luogoNascita);

	switch (persona.dataNascita.giornoSettimana) {
		case MON:
			printf("Lunedì, ");
			break;
		case TUE:
			printf("Martedì, ");
			break;
		case WED:
			printf("Mercoledì, ");
			break;
		case THU:
			printf("Giovedì, ");
			break;
		case FRI:
			printf("Venerdì, ");
			break;
		case SAT:
			printf("Sabato, ");
			break;
		case SUN:
			printf("Domenica, ");
			break;
	}

	printf("%d/", persona.dataNascita.giorno);

	switch (persona.dataNascita.mese) {
		case JAN:
			printf("gen");
			break;
		case FEB:
			printf("feb");
			break;
		case MAR:
			printf("mar");
			break;
		case APR:
			printf("apr");
			break;
		case MAY:
			printf("mag");
			break;
		case JUN:
			printf("giu");
			break;
		case JUL:
			printf("lug");
			break;
		case AUG:
			printf("ago");
			break;
		case SEP:
			printf("set");
			break;
		case OCT:
			printf("ott");
			break;
		case NOV:
			printf("nov");
			break;
		case DEC:
			printf("dic");
			break;
	}

	printf("/%d", persona.dataNascita.anno);
}


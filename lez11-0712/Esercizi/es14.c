/**	Definire una struttura per la modellazione dei dati anagrafici di uno studente (nome, cognome, data di nascita etc),
 * 	quindi creare e popolare un array di studenti.
 * 	Aggiungere una seconda struttura per la modellazione dei risultati di una sessione d’esame che contiene la data,
 * 	il luogo, il nominativo del professore, e un elenco di voti abbinati agli studenti (suggerimento: utilizzare
 * 	gli indici degli studenti nel primo array per recuperare le informazioni).
 *
 * 	Realizzare:
 * 	• una funzione che permetta di acquisire i dati di interesse di uno studente;
 * 	• una procedura che, utilizzando la funzione precedente, popoli un array di studenti dichiarato nel main;
 * 	• una procedura che permetta di acquisire i dati di un esame sostenuto dagli studenti;
 * 	• una funzione che verifica che lo stesso studente non compaia due volte nell’elenco;
 * 	• una funzione che conta quanti studenti hanno sostenuto l’esame con esito positivo;
 * 	• una funzione che visualizza i nomi e i voti degli studenti che hanno ottenuto voto maggiore o uguale a 28.
 * 	Testare le varie funzioni e procedure dal main.
 */

#include <stdio.h>

#define LEN 30
#define DIM 5

typedef struct {
	int giorno;
	int mese;
	int anno;
} Data;

typedef struct {
	char nome[LEN + 1];
	char cognome[LEN + 1];
	Data dataNascita;
} Studente;

typedef struct {
	Data dataEsame;
	char luogoEsame[LEN + 1];
	char nomeProf[LEN + 1];
	int voti[DIM];
} Esame;

Data acquisisciData();
Studente acquisisciStudente();
void popolaArray(int dim, Studente studenti[]);
void acquisisciEsame(int dim, Esame *esame, Studente studenti[]);
void checkStudente(int dim, Studente studenti[]);
int contaPositivi(int dim, Esame *esame);
void topStudenti(int dim, Studente studenti[], Esame *esame);

int main(){
	Studente studenti[DIM];
	Esame esame;

	popolaArray(DIM, studenti);
	acquisisciEsame(DIM, &esame, studenti);
	checkStudente(DIM, studenti);
	printf("Studenti positivi: %d", contaPositivi(DIM, &esame));
	topStudenti(DIM, studenti, &esame);
    return 0;
}

Data acquisisciData() {
	Data data;

	printf("\nGiorno: ");
	scanf("%d", &data.giorno);
	printf("\nMese: ");
	scanf("%d", &data.mese);
	printf("\nAnno: ");
	scanf("%d", &data.anno);
	return data;
}

Studente acquisisciStudente() {
	Studente studente;

	printf("\n\nNome: ");
	scanf(" %[^\n]30s", studente.nome);
	printf("\nCognome: ");
	scanf(" %[^\n]30s", studente.cognome);
	printf("\nData di Nascita: ");

	studente.dataNascita = acquisisciData();

}

void popolaArray(int dim, Studente studenti[]) {
	for (int i = 0; i < dim; ++i) {
		printf("==Studente %d==", i);
		studenti[i] = acquisisciStudente();
	}
}

void acquisisciEsame(int dim, Esame *esame, Studente studenti[]) {
	printf("==Esame=="
		   "\nData esame:");
	esame->dataEsame = acquisisciData();

	printf("\nLuogo esame: ");
	scanf(" %[^\n]30s", esame->luogoEsame);

	printf("\nNome prof: ");
	scanf(" %[^\n]30s", esame->nomeProf);

	for (int i = 0; i < dim; ++i) {
		printf("Voto studente %d (%s, %s)", i, studenti[i].cognome, studenti[i].nome);
		scanf("%d", &esame->voti[i]);
	}

}

void checkStudente(int dim, Studente studenti[]) {
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			if (studenti[i].nome == studenti[j].nome && studenti[i].cognome == studenti[j].cognome) {
				printf("Studente %d è già presente, reinserire");
				studenti[j] = acquisisciStudente();
			}
		}
	}
}

int contaPositivi(int dim, Esame *esame) {
	int count = 0;

	for (int i = 0; i < dim; ++i) {
		if (esame->voti[i] >= 15) {
			count++;
		}
	}
}

void topStudenti(int dim, Studente studenti[], Esame *esame) {
	for (int i = 0; i < dim; ++i) {
		if (esame->voti[i] >= 28) {
			printf("%s, %s: %d", studenti[i].cognome, studenti[i].nome, esame->voti[i]);
		}
	}
}
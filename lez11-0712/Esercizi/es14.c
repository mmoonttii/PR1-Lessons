/**	Definire una struttura per la modellazione dei dati anagrafici di uno studente (nome, cognome, data di nascita etc),
 * 	quindi creare e popolare un array di studenti. Aggiungere una seconda struttura per la modellazione dei risultati di
 * 	una sessione d’esame che contiene la data, il luogo, il nominativo del professore, e un elenco di voti abbinati agli
 * 	studenti (suggerimento: utilizzare gli indici degli studenti nel primo array per recuperare le informazioni).
 * 	Realizzare:
 * 	• una funzione che permetta di acquisire i dati di interesse di uno studente;
 * 	• una procedura che, utilizzando la funzione precedente, popoli un array di studenti dichiarato nel main;
 * 	• una procedura che permetta di acquisire i dati di un esame sostenuto dagli studenti;
 * 	• una funzione che verifica che lo stesso studente non compaia due volte nell’elenco;ù
 * 	• una funzione che conta quanti studenti hanno sostenuto l’esame con esito positivo;
 * 	• una funzione che visualizza i nomi e i voti degli studenti che hanno ottenuto voto maggiore o uguale a 28.
 * 	Testare le varie funzioni e procedure dal main.
 */

#include <stdio.h>

#define LEN 20

typedef struct {
	char nome[LEN + 1];
	char cognome[LEN + 1];
	int giornoNascita;
	int meseNascita;
	int annoNascita;
} Studente;

int main(){

    return 0;
}
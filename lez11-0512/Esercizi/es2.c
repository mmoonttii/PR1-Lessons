/** Scrivere un programma che definisca una struttira studente comprensiva di
 * nome, cognome, matricola, corso di laurea, anno di immatricolazione, tipo di corso (laurea o l. magistrale)
 * Il programma deve svolgere le seguenti informazioni:
 * - acquisisre informazioni relative a 5 studenti e memorizzarle in un arrya
 * - richiedere il numero di matricola di uno studente di cui cercare le informazioni nell'array
 * - cercare lo studente e stampare in optput i suoi dati se la ricerca ha prododtto risulktati, oppure indicare che non
 * 		è statp trovato nessuno studente con tale matricola
 * */

#include <stdio.h>
#include <string.h>

#define LEN_STR 20
#define LEN_MTR 5
#define NUM_STU 5

typedef enum {LAUREA, MAGISTRALE} TipoLaurea;

typedef struct {
	char nome[LEN_STR + 1];
	char cognome[LEN_STR + 1];
	char matricola[LEN_MTR + 1];
	char corso[LEN_STR + 1];
	int anno;
	TipoLaurea tipoLaurea;
} Studente;

Studente acquisisciStudente();
int cercaStudente(char matricola[], Studente studenti[], int numStudenti);
void printStudente(Studente studenti[], int index);

int main(){
	Studente studenti[NUM_STU];
	char matricola[LEN_MTR];
	int indice;

	for (int i = 0; i < NUM_STU; ++i) {
		studenti[i] = acquisisciStudente();
	}

	printf("\nDi quale studente vuoi cercare informazioni"
		   "\nInserisci matricola: ");
	scanf("%[^\n]5s", matricola);

	indice = cercaStudente(matricola, studenti, NUM_STU);
	printStudente(studenti, indice);

    return 0;
}

Studente acquisisciStudente() {
	Studente studente;

	printf("\nNome: ");
	scanf(" %[^\n]20s", studente.nome);

	printf("\nCognome: ");
	scanf(" %[^\n]20s", studente.cognome);

	printf("\nMatricola (ultime 5 cifre): ");
	scanf(" %[^\n]5s", studente.matricola);

	printf("\nCorso: ");
	scanf(" %[^\n]20s", studente.corso);

	printf("\nAnno immatricolazione: ");
	scanf(" %d", &studente.anno);

	printf("\nTipo di corso di Laurea"
		   "\n[0] Laurea Triennale,"
		   "\n[1] Laurea Magistrale:");
	scanf(" %d", &studente.tipoLaurea);

	return studente;
}

int cercaStudente(char matricola[], Studente studenti[], int numStudenti) {
	int index = -1;

	for (int i = 0; i < numStudenti; ++i) {
		if (strcmp(matricola, studenti[i].matricola) == 0){
			index = i;
		} else {
			index = -1;
		}
	}

	return index;
}

void printStudente(Studente studenti[], int index) {
	Studente studente;

	if (index == -1) {
		printf("\n\nStudente non trovato");
	} else {
		studente = studenti[index];
		printf("\nNome: %s", studente.nome);
		printf("\nCognome: %s", studente.cognome);
		printf("\nMatricola: %s", studente.matricola);
		printf("\nCorso: %s", studente.corso);
		printf("\nAnno: %d", studente.anno);

		if (studente.tipoLaurea == 0) {
			printf("Laurea: Triennale");
		} else if (studente.tipoLaurea == 1) {
			printf("Laurea: Magistrale");
		}
	}
}

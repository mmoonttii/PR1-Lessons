#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/** ESERCIZIO 1 [4pt]
 * Definire un'enumerazione Genere, rappresentante i possibili generi di una serie tv, avente i seguenti valori:
 * - AZIONE, COMMEDIA, DOCUMENTARIO, DRAMMATICO, HORROR, ROMANTICO, THRILLER.
 * Definire, poi, una struttura SerieTv avente come campi titolo, anno, numero di stagioni,numero di episodi totali, genere e la valutazione.
 */
#define LEN_STR 31

#define VAL_MIN 0
#define VAL_MAX 10

#define ANNO_MIN 1900
#define ANNO_MAX 2020

#define STAG_MIN 1
#define STAG_MAX 20

#define EP_MIN 1
#define EP_MAX 100

#define EMMY "EMMY"

typedef enum{ AZIONE,
              COMMEDIA,
              DOCUMENTARIO,
              DRAMMATICO,
              HORROR,
              ROMANTICO,
              THRILLER} Genere;

typedef struct {
	char titolo[LEN_STR + 1];
	int anno;
	int nStagioni;
	int nEpisodi;
	Genere genere;
	int valutazione;
} SerieTV;

//  Es 2
SerieTV acquisisciSerieTv();
int randRange(int min, int max);

//  Es 3
SerieTV *acquisisciCatalogoSerieTv(int nSerie);

//  Es 4
void stampaCatalogoSerieTv(SerieTV *catalogo, int nSerie);
void stampaSerie(SerieTV *serieTv);
void stampaGenere(Genere genere);

//  Es 5
void selezioneEmmy(SerieTV *serieTv);

//  Es 6
void premiazioneEmmy(SerieTV *catalogo, int nSerie);

int main()
{
    // dichiarazione variabili

	srand(time(NULL)); 	// Inserito studente: init seed random

	SerieTV *catalogo = NULL;
    int nSerie = 0;

    do {
        printf("Inserisci il numero di serie tv: ");
        scanf("%d", &nSerie);

        if (nSerie <= 0)
            printf("Il numero di serie tv deve essere maggiore di 0");
    } while (nSerie <= 0);

    catalogo = acquisisciCatalogoSerieTv(nSerie);
    stampaCatalogoSerieTv(catalogo, nSerie);

    //selezione all star
    premiazioneEmmy(catalogo, nSerie);
    stampaCatalogoSerieTv(catalogo, nSerie);

	// Inserito studente: Deallocazione memoria
	if (catalogo != NULL){
		free(catalogo);
		catalogo = NULL;
	}

    return 0;
}

/** === ESERCIZIO 2 [5pt] ==========================================================================================
 * Creazione di una subroutine acquisisciSerieTv che chieda all'utente di inserire
 * tutti i dati relativi a una serie tv e la restituisca, assicurandosi che i campi siano validi:
 * - il campo titolo deve essere una stringa di al massimo 32 caratteri non vuota
 * - il campo anno deve essere un numero compreso tra 1900 e 2020
 * - il campo nStagioni deve essere un numero compreso tra 1 e 20
 * - il campo nEpisodi deve essere un numero compreso tra 1 e 100
 * - il campo genere deve essere un valore valido dell'enumerazione Genere
 * - il campo valutazione deve essere un numero compreso tra 0 e 10 generato casualmente
 **/
SerieTV acquisisciSerieTv(){
	SerieTV serieTv;
	bool flag = true;

	//  Acquisisco campo titolo
	do {
		printf("Titolo serie Tv: ");
		scanf(" %[^\n]31s", serieTv.titolo);

		flag = strlen(serieTv.titolo) == 0;
		if (flag) {
			printf("Il titolo della serie non può essere vuoto, riprovare\n");
		}
	} while (flag); //  Il campo titolo non può essere vuoto

	//  Acquisisco campo anno
	do {
		printf("Anno serie Tv: ");
		scanf("%d", &serieTv.anno);

		flag = serieTv.anno < ANNO_MIN || serieTv.anno > ANNO_MAX;
		if (flag) {
			printf("L'anno deve essere compreso tra 1900 e 2020, riprovare\n");
		}
	} while (flag); //  Il campo anno deve essere compreso tra 1900 e 2020

	//  Acquisisco campo nStagioni
	do {
		printf("Numero stagioni serie Tv: ");
		scanf("%d", &serieTv.nStagioni);

		flag = serieTv.nStagioni < STAG_MIN || serieTv.nStagioni > STAG_MAX;
		if (flag) {
			printf("Il numero di stagioni deve essere compreso tra 1 e 20, riprovare\n");
		}
	} while (flag); //  Il campo nStagioni deve essere compreso tra 1 e 20

	//  Acquisisco campo nEpisodi
	do {
		printf("Numero episodi serie Tv: ");
		scanf("%d", &serieTv.nEpisodi);

	flag = serieTv.nEpisodi < EP_MIN || serieTv.nEpisodi > EP_MAX;
		if (flag) {
			printf("Il numero di episodi deve essere compreso tra 1 e 100, riprovare\n");
		}
	} while (flag); //  Il campo nEpisodi deve essere compreso tra 1 e 100

	//  Acquisisco campo genere
	do {
		printf("Genere serie Tv\n"
			   "\t[0] Azione\n"
			   "\t[1] Commedia\n"
		       "\t[2] Documentario\n"
		       "\t[3] Drammatico\n"
		       "\t[4] Horror\n"
		       "\t[5] Romantico\n"
		       "\t[6] Thriller\n"
			   "Inserisci: ");
		scanf("%d", &serieTv.genere);

		flag = serieTv.genere < AZIONE || serieTv.genere > THRILLER;
		if (flag) {
			printf("Il genere deve essere compreso tra 0 e 6, riprovare\n");
		}
	} while (flag); // Il campo genere deve essere compreso tra 0 e 6

	//  Acquisisco campo valutazione
	serieTv.valutazione = randRange(VAL_MIN, VAL_MAX);

	return serieTv;
}

int randRange(int min, int max){
	int result;

	result = min + rand() % (max - min + 1);

	return result;
}

/** FINE ESERCIZIO 2 */

/** === ESERCIZIO 3 [7pt] ==========================================================================================
 * Scrivere una subroutine 'acquisisciCatalogoSerieTv' che si occupa di allocare dinamicamente un array di N serie tv, con
 * N passato come parametro, e di popolarlo avvalendosi della subroutine 'acquisisciSerieTv'.
 **/
SerieTV *acquisisciCatalogoSerieTv(int nSerie){
	SerieTV *catalogo = NULL;

	// calloc() alloca la memoria per nSerie spazi di dimensione adatta a contenere SerieTV
	catalogo = (SerieTV *)calloc(nSerie, sizeof(SerieTV));
	if (catalogo == NULL) exit(-1); //  Se non viene allocata la memoria crasho il programma

	for (int i = 0; i < nSerie; ++i) {
		catalogo[i] = acquisisciSerieTv();
	}

	return catalogo;
}

/** FINE ESERCIZIO 3 */

/** === ESERCIZIO 4 [5pt] ==========================================================================================
 * Scrivere una subroutine 'stampaCatalogoSerieTv' che stampi tutti i campi di tutte le serie tv presenti in un array
 * di serie tv passato come parametro.
 * BONUS: è possibile utilizzare subroutine ausiliarie per suddividere meglio le stampe.
 **/
void stampaCatalogoSerieTv(SerieTV *catalogo, int nSerie){
	printf("\n\n===CATALOGO SERIE===\n");
	for (int i = 0; i < nSerie; ++i) {
		printf("\n===SERIE %d===\n", i);
		stampaSerie(&catalogo[i]);
	}
}

void stampaSerie(SerieTV *serieTv){
	printf("Titolo serie: %s\n", serieTv->titolo);
	printf("\tAnno: %d\n", serieTv->anno);
	printf("\tNumero stagioni: %d\n", serieTv->nStagioni);
	printf("\tNumero episodi: %d\n", serieTv->nEpisodi);

	stampaGenere(serieTv->genere); //   La stampa del genere viene effettuata in una subroutine ausiliaria

	printf("\tValutazione [%d - %d]: %d\n", VAL_MIN, VAL_MAX, serieTv->valutazione);
}

void stampaGenere(Genere genere){
	//  stampaGenere(genere) preso il valore dell'enumerazione Genere stampa il genere corrispondente
	switch (genere) {
		case AZIONE:
			printf("\tGenere: azione\n");
			break;
		case COMMEDIA:
			printf("\tGenere: commedia\n");
			break;
		case DOCUMENTARIO:
			printf("\tGenere: documentario\n");
			break;
		case DRAMMATICO:
			printf("\tGenere: drammatico\n");
			break;
		case HORROR:
			printf("\tGenere: horror\n");
			break;
		case ROMANTICO:
			printf("\tGenere: romantico\n");
			break;
		case THRILLER:
			printf("\tGenere: thriller\n");
			break;
		default:
			printf("Errore nella stampa del genere\n");
			break;
	}
}

/** FINE ESERCIZIO 4 */

/** === ESERCIZIO 5 [3pt] ==========================================================================================
 * Scrivere una subroutine 'selezioneEmmy' che modifichi la il titolo della serie tv passata come parametro aggiungendo
 * la stringa "EMMY" all'inizio del titolo.
 * Assicurarvi che la stringa finale non superi i 32 caratteri. Nel caso in cui superi i 32 caratteri non modificarev la stringa
 **/
void selezioneEmmy(SerieTV *serieTv) {
	char emmy[LEN_STR + 1] = EMMY;

	if ((strlen(serieTv->titolo) + strlen(EMMY)) < LEN_STR) {
		strcat(emmy, serieTv->titolo);
		strcpy(serieTv->titolo, emmy);
	}
}

/** FINE ESERCIZIO 5 */

/** === ESERCIZIO 6 [6pt] ==========================================================================================
 * Scrivere una subroutine 'premiazioneEmmy' che, dopo aver individuato le migliori serie tv di ogni genere, le premi con
 * il titolo "EMMY" sfruttando la subroutine selezioneEmmy
 **/
void premiazioneEmmy(SerieTV *catalogo, int nSerie) {
	int premiata[THRILLER + 1] = {}; // L'array premiata contiene, per ogni genere, l'indice della serie con valutazione più alta

	for (int i = 0; i <= THRILLER; ++i) {
		premiata[i] = -1; // Inizializzo l'array a un valore non valido
	}

	for (int g = 0; g <= THRILLER; ++g) {  // Per ogni genere

		for (int i = 0; i < nSerie; ++i) { // Ciclo il catalogo

			if (catalogo[i].genere == g) { // Se il genere di questa serie è il genere che stiamo controllando

				if (catalogo[i].valutazione > catalogo[premiata[g]].valutazione) {
				// e se la valutazione di questa serie è maggiore della valutazione della serie in maxVal
					premiata[g] = i; // Allora questa serie prende il posto come serie migliore di tale genere
				}
			}
		}
	}

	for (int g = 0; g < THRILLER + 1; ++g) { // Ciclo l'array che contiene le serie con la miglior valutazione
		if (premiata[g] != -1) // Controllo che l'indice sia valido
			selezioneEmmy(&catalogo[premiata[g]]);
	}
}

/** FINE ESERCIZIO 6 */
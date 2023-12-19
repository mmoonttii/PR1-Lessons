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
#define LEN 31
#define VAL_MIN 0
#define VAL_MAX 10

typedef enum{AZIONE,
			 COMMEDIA,
			 DOCUMENTARIO,
			 DRAMMATICO,
			 HORROR,
			 ROMANTICO,
			 THRILLER} Genere;

typedef struct {
	char titolo[LEN + 1];
	int anno;
	int nStagioni;
	int nEpisodi;
	Genere genere;
	int valutazione;
} SerieTV;

SerieTV acquisisciSerieTv();

int randRange(int min, int max);

int main()
{
    // dichiarazione variabili

	// Inserito studente
	srand(time(NULL));

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
		printf("Titolo serie Tv");
		scanf(" %[^\n]31s", serieTv.titolo);

		flag = strlen(serieTv.titolo) == 0;
		if (flag) {
			printf("Il titolo della serie non può essere vuoto, riprovare\n");
		}
	} while (flag); //  Il campo titolo non può essere vuoto

	//  Acquisisco campo anno
	do {
		printf("Anno serie Tv");
		scanf("%d", &serieTv.anno);

		flag = serieTv.anno < 1900 || serieTv.anno > 2020;
		if (flag) {
			printf("L'anno deve essere compreso tra 1900 e 2020, riprovare\n");
		}
	} while (flag); //  Il campo anno deve essere compreso tra 1900 e 2020

	//  Acquisisco campo nStagioni
	do {
		printf("Numero stagioni serie Tv");
		scanf("%d", &serieTv.nStagioni);

		flag = serieTv.nStagioni < 1 || serieTv.nStagioni > 20;
		if (flag) {
			printf("Il numero di stagioni deve essere compreso tra 1 e 20, riprovare\n");
		}
	} while (flag); //  Il campo nStagioni deve essere compreso tra 1 e 20

	//  Acquisisco campo nEpisodi
	do {
		printf("Numero episodi serie Tv");
		scanf("%d", &serieTv.nEpisodi);

	flag = serieTv.nEpisodi < 1 || serieTv.nEpisodi > 100;
		if (flag) {
			printf("Il numero di episodi deve essere compreso tra 1 e 100, riprovare\n");
		}
	} while (flag); //  Il campo nEpisodi deve essere compreso tra 1 e 100

	//  Acquisisco campo genere
	do {
		printf("Genere serie Tv\n"
			   "[0] Azione\n"
			   "[1] Commedia\n"
		       "[2] Documentario\n"
		       "[3] Drammatico\n"
		       "[4] Horror\n"
		       "[5] Romantico\n"
		       "[6] Thriller\n");
		scanf("%d", &serieTv.genere);

		flag = serieTv.genere < 0 || serieTv.genere > 6;
		if (flag) {
			printf("Il genere deve essere compreso tra 0 e 6, riprovare\n");
		}
	} while (flag); // Il campo genere deve essere compreso tra 0 e 6

	//  Acquisisco campo valutazione
	serieTv.valutazione = randRange(VAL_MIN, VAL_MAX);
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
// Inserire codice studente...
/** FINE ESERCIZIO 3 */

/** === ESERCIZIO 4 [5pt] ==========================================================================================
 * Scrivere una subroutine 'stampaCatalogoSerieTv' che stampi tutti i campi di tutte le serie tv presenti in un array
 * di serie tv passato come parametro.
 * BONUS: è possibile utilizzare subroutine ausiliarie per suddividere meglio le stampe.
 **/
// Inserire codice studente...
/** FINE ESERCIZIO 4 */

/** === ESERCIZIO 5 [3pt] ==========================================================================================
 * Scrivere una subroutine 'selezioneEmmy' che modifichi la il titolo della serie tv passata come parametro aggiungendo
 * la stringa "EMMY" all'inizio del titolo.
 * Assicurarvi che la stringa finale non superi i 32 caratteri. Nel caso in cui superi i 32 caratteri non modificarev la stringa
 *
 **/
// Inserire codice studente...
/** FINE ESERCIZIO 5 */

/** === ESERCIZIO 6 [6pt] ==========================================================================================
 * Scrivere una subroutine 'premiazioneEmmy' che, dopo aver individuato le migliori serie tv di ogni genere, le premi con
 * il titolo "EMMY" sfruttando la subroutine selezioneEmmy
 **/
// Inserire codice studente...
/** FINE ESERCIZIO 6 */




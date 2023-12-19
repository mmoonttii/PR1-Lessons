#include <stdio.h>

/** ESERCIZIO 1 [4pt]
 * Definire un'enumerazione Genere, rappresentante i possibili generi di una serie tv, avente i seguenti valori:
 * - AZIONE, COMMEDIA, DOCUMENTARIO, DRAMMATICO, HORROR, ROMANTICO, THRILLER.
 * Definire, poi, una struttura SerieTv avente come campi titolo, anno, numero di stagioni,numero di episodi totali, genere e la valutazione.
 */

typedef enum{AZIONE,
			 COMMEDIA,
			 DOCUMENTARIO,
			 DRAMMATICO,
			 HORROR,
			 ROMANTICO,
			 THRILLER} Genere
			 ;


int main()
{
    // dichiarazione variabili
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
// Inserire codice studente...
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




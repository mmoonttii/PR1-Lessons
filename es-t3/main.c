#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/** Il codice già fornito nel main NON DEVE ESSERE MODIFICATO IN ALCUN MODO.
 * È possibile integrare il main con tutto quello che è ritenuto opportuno senza modificare il codice già fornito.
 * Sono valutati anche:
 *  - commenti al codice;
 *  - eventuali buone norme di programmazione viste;
 *  - stile e leggibilità del codice.
 **/

/// Inclusione librerie studente
//codice studente...
/// Fine inclusione librerie studente

/// Definizione macro studente
#define LEN 31

/// Fine definizione macro studente

/** === ESERCIZIO 1 [4pt] ==========================================================================================
 * Definire un'enumerazione Ruolo, rappresentante i possibili ruoli di un giocatore di calcio:
 * PORTIERE, DIFENSORE, CENTROCAMPISTA, ATTACCANTE.
 * Definire, poi, una struttura Calciatore avente come campi cognome, squadra, numero di maglia, ruolo, goal realizzati.
 **/
typedef enum {
	PORTIERE, DIFENSORE, CENTROCAMPISTA, ATTACCANTE
} Ruolo;

typedef struct {
	char cognome[LEN + 1];
	char squadra[LEN + 1];
	int numero;
	Ruolo ruolo;
	int goal;
} Calciatore;

/** FINE ESERCIZIO 1 */

/// Dichiarazione subroutine studente


/// Fine altre dichiarazioni studente

int main()
{

    Calciatore *squadra = NULL;
    int nCalciatori = 0;

    do {
        printf("Inserisci il numero di calciatori: ");
        scanf("%d", &nCalciatori);

        if (nCalciatori <= 0)
            printf("Il numero di calciatori deve essere maggiore di 0");
    } while (nCalciatori <= 0);

    squadra = acquisisciCalciatori(nCalciatori);
    stampaCalciatori(squadra, nCalciatori);

    //selezione all star
    capocannonieriAllStar(squadra, nCalciatori);
    stampaGiocatori(squadra, nCalciatori);

    return 0;

}


/** === ESERCIZIO 2 [5pt] ==========================================================================================
 * Definire una subroutine 'acquisisciCalciatore' che chieda all'utente di inserire tutti i dati relativi a un calciatore
 * e lo restituisca, assicurandosi che i campi siano validi:
 * - il campo cognome non deve essere vuoto;
 * - il campo squadra non deve essere vuoto;
 * - il campo numero di maglia deve essere compreso tra 1 e 99 (estremi inclusi);
 * - il ruolo deve essere uno dei valori presenti nell'enumerazione Ruolo;
 * - i gol realizzati devono essere generati casualmente e compresi tra 0 e 35 (estremi inclusi);
 **/

Calciatore acquisisciCalciatore(int min) {
	Calciatore calciatore;
	bool flag = true;

	do {
		printf("\nInserisci cognome: ");
		scanf(" %[^\n]31s", calciatore.cognome);

		flag = strlen(calciatore.cognome) == 0; // Controllo input cognome non vuoto

		if (flag) {
			printf("\nIl campo cognome non può essere vuoto"
				   "\nRiprovare");
		}

	} while (flag); // Se il cognome non è stato inserito, ripetere

	do {
		printf("\nInserisci squadra: ");
		scanf(" %[^\n]31s", calciatore.squadra);

		flag = strlen(calciatore.squadra) == 0; // Controllo input squadra non vuoto

		if (flag) {
			printf("\nIl campo squadra non può essere vuoto"
			       "\nRiprovare");
		}

	} while (flag); // Se il squadra non è stato inserito, ripetere

	do {
		printf("\nInserisci numero di maglia: ");
		scanf(" %d", &calciatore.numero);

		flag = (calciatore.numero < 1 || calciatore.numero > 99); // Controllo input numero 1 <= n <= 99

		if (flag) {
			printf("\nIl campo numero di maglia deve essere compreso tra 1 e 99 compresi"
			       "\nRiprovare");
		}

	} while (flag); // Se il numero inserito non è valido, ripetere

	do {
		printf("\nInserisci ruolo:"
			   "\n[0] Portiere"
			   "\n[1] Difensore"
			   "\n[2] Centrocampista"
			   "\n[3] Attaccante"
			   "\nInserire [0-3]: ");
		scanf("%d", &calciatore.ruolo);

		flag = (calciatore.ruolo < 0 || calciatore.ruolo > 3); // Controllo input appartenga all'enumerazione

		if (flag) {
			printf("\nIl campo ruolo deve essere compreso tra 0 e 3 compresi"
			       "\nRiprovare");
		}
	} while (flag);

	calciatore.goal = randRange(min, max);
	printf("Goals: %d", calciatore.goal);
}



/** FINE ESERCIZIO 2 */

/** === ESERCIZIO 3 [7pt] ==========================================================================================
 * Scrivere una subroutine 'acquisisciCalciatori' che si occupa di allocare dinamicamente un array di N calciatori, con
 * N passato come parametro, e di popolarlo avvalendosi della subroutine 'acquisisciCalciatore'.
 **/
//codice studente...
/** FINE ESERCIZIO 3 */

/** === ESERCIZIO 4 [5pt] ==========================================================================================
 * Scrivere una subroutine 'stampaGiocatori' che stampi tutti i campi di tutti i giocatori presenti in un array
 * di giocatori passato come parametro.
 * BONUS: è possibile utilizzare subroutine ausiliarie per suddividere meglio le stampe.
 **/
//codice studente...
/** FINE ESERCIZIO 4 */

/** === ESERCIZIO 5 [3pt] ==========================================================================================
 * Scrivere una subroutine 'selezioneAllStar' che modifichi la squadra di un calciatore e la imposti a "ALL STAR"
 **/
//codice studente...
/** FINE ESERCIZIO 5 */

/** === ESERCIZIO 6 [6pt] ==========================================================================================
 * Scrivere una subroutine 'capocannonieriAllStar' che, dopo aver individuato i calciatori con il maggior numero di gol
 * realizzati per ogni ruolo, imposti la loro squadra a "ALL STAR" sfruttando la subroutine 'selezioneAllStar'.
 **/
//codice studente...
/** FINE ESERCIZIO 6 */
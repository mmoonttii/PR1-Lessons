/** === DESCRIZIONE ====================================================================================================
 * CONTESTO: Ci troviamo nella birreria del Palazzo delle Scienze. In questa particolare birreria, il prezzo di ogni
 * birra varia a seconda del giorno della settimana. Abbiamo a disposizione un array di stringhe "listaBirre"
 * che rappresenta la birre presenti in dispensa. L'obiettivo del compito è quello di riempire la dispensa e
 * stabilire i prezzi giornalieri delle birre contenuti all'interno di "prezziBirre".
 *
 * SVOLGIMENTO: Il compito consiste nell'implementazione di alcune subroutine che poi dovranno essere opportunamente
 * richiamate nel main, come indicato nel CONTESTO e dettagliato nel testo dei vari esercizi.
 *
 * CONSIGLIO: Risolvere gli esercizi in ordine di numerazione.
 *
 * VALUTAZIONE: Gli esercizi hanno un punteggio. Se svolti tutti correttamente si raggiunge il 30.
 * Si raccomanda di commentare adeguatamente il codice (un codice non commentato porterà MALUS sul voto finale).
 * È possibile modificare il codice che vi è stato fornito per ragioni di stile (eventuale BONUS sul voto finale).
 *
 */
#include <stdio.h>

/// Inclusione librerie studente
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/// Fine inclusione librerie studente

/// Definizione macro studente
#define N_BIRRE 10
#define D_WEEK 7
#define LEN_BIRRA 30
#define MULT 2
#define MIN 3
#define MAX 10

/// Fine definizione macro studente

/// Altre dichiarazioni studente
void acquisisciBirra(int dim, int k, char listaBirre[dim][LEN_BIRRA + 1]);
float randRangeFloat(int min, int max);
void generaPrezzi(int dim, int dWeek, float prezziBirre[dim][dWeek], int min, int max);
void stampaBirre(int dim, char listaBirre[dim][LEN_BIRRA + 1], float prezziBirre[dim][D_WEEK]);
/// Fine altre dichiarazioni studente

int main() {
	srand(time(NULL)); // Init seed random

    /** === VARIABILI ==================================================================================================
     * - listaBirre è un array di stringhe che contiene i nomi delle birre presenti in dispensa. Le dispensa può
     *   contenere al massimo 10 birre e le prime 5 birre sono già inserite in fase di inizializzazione.
     * - prezziBirre è una matrice numerica che contiene i prezzi delle birre disponibili. Ogni riga della matrice
     *   rappresenta la corrispettiva birra della lista di birre (10 in tutto), mentre ogni colonna rappresenta un
     *   giorno della settimana (7 in tutto).
     * - min rappresenta il prezzo minimo a cui si può vendere una birra.
     * - max rappresenta il prezzo massimo a cui si può vendere una birra.
     **/
    char listaBirre[N_BIRRE][LEN_BIRRA + 1] = {"Ichnusa", "Heineken", "Peroni", "Becks", "Tuborg"};
    float prezziBirre[N_BIRRE][D_WEEK];

    /** === ESERCIZIO 5 [3pt] ==========================================================================================
     * Richiamare la subroutine acquisisciBirra e assicurarsi di riempire la listaBirre con tutte e 10 le birre
     * possibili.
     **/
	// Ciclo la lista delle birre fino a trovare un posto vuoto, nel posto vuoto richiamo l'acquisizione della birra
	for (int k = 0; k < N_BIRRE; ++k) {
		if (strcmp(listaBirre[k], "") <= 0){
			// Se elemento k è vuoto possiamo inserire una nuova birra
			acquisisciBirra(N_BIRRE, k, listaBirre);
		}
	}
    /** FINE ESERCIZIO 5 */

    /** === ESERCIZIO 6 [2pt] ==========================================================================================
     * Dati il minimo e il massimo per l'estrazione casuale del prezzo (min e max), generare i prezzi giornalieri
     * delle birre utilizzando la funzione dell'esercizio 3.
     **/
	generaPrezzi(N_BIRRE, D_WEEK, prezziBirre, MIN, MAX);
	/** FINE ESERCIZIO 6 */

    /** === ESERCIZIO 7 [1pt] ==========================================================================================
     * Richiamare la subroutine stampaBirre.
     **/
    stampaBirre(N_BIRRE, listaBirre, prezziBirre);
    /** FINE ESERCIZIO 7 */

    return 0;
}

/** === ESERCIZIO 1 (Acquisizione stringa) [9pt] =======================================================================
 * Scrivere una subroutine acquisisciBirra che si occupi di far inserire all'utente una nuova birra e la inserisca
 * nella posizione k-esima dell'array di stringhe listaBirre, con listaBirre e k passati come parametri.
 * NB: non devono essere presenti birre con lo stesso nome. Se l'utente inserisce una birra già presente, deve essere
 * chiesto nuovamente l'inserimento.
 * HINT: è possibile utilizzare le funzioni della libreria string viste a lezione (SOLO quelle viste a lezione).
 **/
void acquisisciBirra(int dim, int k, char listaBirre[dim][LEN_BIRRA + 1]){
	char aux[LEN_BIRRA + 1] = {}; // Variabile di appoggio
	 // Condizione presenza birra
	bool flag = true;

	do {
		flag = true;

		printf("\nInserisci birra per posizione %d: ", k);
		scanf(" %[^\n]30s", aux);   // Acquisisco nome della birra assicurandomi che non possa prendere più dei
									// caratteri massimi e prenda fino al \n

		// Ciclo attraverso la lista e controllo che la birra inserita non ne faccia già parte
		for (int i = 0; (i < dim && flag); ++i) {
			// Esco dal ciclo se finisco l'elenco delle birre o trovo che la birra ne fa già parte
			if (strcmp(aux, listaBirre[i]) == 0){
				flag = false;
			}
		}

		if (!flag) { // Se la birra fa già parte della lista richiedo l'input
			printf("Birra %s già in elenco, riprovare\n", aux);
		} else { // Se la birra non fa parte dell'elenco la posso aggiungere
			printf("Sto aggiungendo la birra %s alla pos. %d\n", aux, k);
			strcpy(listaBirre[k], aux);
		}
	} while (flag == false);

}

/** FINE ESERCIZIO 1 */

/** === ESERCIZIO 2 (Generazione casuale) [3pt] ========================================================================
 * Scrivere una subroutine randRangeFloat che si occupi di generare e restituire un numero float generato casualmente
 * e compreso tra min e max; min e max sono due parametri di tipo intero passati alla subroutine.
 * Il numero deve essere generato con due cifre decimali utili (per esempio: 7.15).
 **/
float randRangeFloat(int min, int max){
	// Genera un float compreso tra min e max di MULT cifre decimali
	float random;
	int mult = pow(10, MULT);
	// Moltiplico il massimo e il minimo di 10^MULT per generare float
	min *= mult;
	max *= mult;

	random = (float)(min + rand() % (max - min + 1));
	// rand() genera solo interi, per avere un float di MULT cifre, dobbiamo dividere per mult
	random /= (float)mult;
	return random;
}
/** FINE ESERCIZIO 2 */

/** === ESERCIZIO 3 (Inserimento dati in una una matrice numerica) [5pt]================================================
 * Scrivere una subroutine generaPrezzi che si occupi di generare, con valori casuali, la matrice con i prezzi delle
 * birre. La subroutine deve ricevere, almeno, i seguenti parametri: la matrice dei prezzi, min (intero), max (intero).
 * HINT: sfruttare opportunamente la subroutine randRangeFloat.
 **/
void generaPrezzi(int dim, int dWeek, float prezziBirre[dim][D_WEEK], int min, int max){
	// genera un prezzo di MULT cifre decimali compreso tra min e max, ciclando tra tutte le celle di prezziBirre,
	// usando randRangeFloat
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dWeek; ++j) {
			prezziBirre[i][j] = randRangeFloat(min, max);
		}
	}

}

/** FINE ESERCIZIO 3 */

/** === ESERCIZIO 4 (Stampa matrici) [7pt] =============================================================================
 * Scrivere una subroutine stampaBirre che si occupi di stampare in output le birre presenti nella lista di birre,
 * e il loro prezzo giornaliero, con listaBirre e prezziBirre forniti come parametri.
 **/
void stampaBirre(int dim, char listaBirre[dim][LEN_BIRRA + 1], float prezziBirre[dim][D_WEEK]){
	// Ciclando tra tutte le celle di listaBirre e prezziBirre, stampa il listino di tutta la settimana
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < D_WEEK; ++j) {
			printf("%s [g %d]: %.2f €\t\t", listaBirre[i], j, prezziBirre[i][j]);
		}
		putchar('\n');
	}

}

/** FINE ESERCIZIO 4 */
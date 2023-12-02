/** === DESCRIZIONE ====================================================================================================
 * CONTESTO: Ci troviamo al campionato di bocce del Palazzo delle Scienze.
 * In questo particolare campionato, si gioca in 8 (tutti contro tutti) ed a ogni turno ognuno tira una boccia.
 * Ad ogni turno, il giocatore che ha tirato la boccia più vicina al pallino guadagna un punto.
 * Il vincitore del campionato è il giocatore che ha totalizzato più punti.
 * L'obiettivo è quello di generare i lanci dei giocatori (codificati come distanza dal pallino)
 * e calcolare il punteggio finale al fine di determinare un vincitore.
 *
 * ESEMPIO con 3 giocatori e 4 turni
 * Lanci:       T1   T2   T3   T4          Punteggi: G1   G2   G3
 *        G1 | 10.5  7.1  8.2  9.3                   1    3    0
 *        G2 | 8.1   7.2  6.3  5.4
 *        G3 | 9.1   8.2  7.3  6.4
 *
 *
 * SVOLGIMENTO: Il compito consiste nell'implementazione di alcune subroutine che sono già opportunamente richiamate nel main.
 * Si consiglia di leggere attentamente il main per capire in che ordine dichiarare i parametri delle subroutine.
 *
 * CONSIGLI: Risolvere gli esercizi in ordine di numerazione, ma non rimanere bloccati su un esercizio troppo a lungo,
 * dal momento in cui l'ordine degli esercizi non rappresenta una difficoltà crescente.
 * Commentare le parti del main non ancora implementate ed andare in maniera incrementale.
 *
 * VALUTAZIONE: Gli esercizi hanno un punteggio. Se svolti tutti correttamente si raggiunge il 30.
 * Si raccomanda di commentare adeguatamente il codice (un codice non commentato porterà MALUS sul voto finale).
 *
 * NOTA BENE: È severamente vietato modificare il main.
 */

#include <stdio.h>

#define N_GIOCATORI 8
#define N_LANCI 10
#define DIM_STR 31
#define MIN 5
#define MAX 250
#define DEC 3

/// inclusione librerie studente
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
/// fine inclusione librerie studente

/** macro studente **/
// inserire macro studente
/** fine macro studente **/

/** prototipi studente **/
void acquisisciGiocatore(int indexPlayer, int nPlayers, int lenStr, char giocatori[][lenStr + 1]);
double randRangeDouble(int min, int max, int dec);
void generaLanci(int nPlayers, int nRounds, double turni[nPlayers][nRounds], int min, int max, int dec);
void stampaLanci(int nPlayers, int nRounds, int lenStr, char giocatori[nPlayers][lenStr + 1], double turni[nPlayers][nRounds]);
void calcolaPunteggi(int nPlayers, int nRounds, double turni[nPlayers][nRounds], int points[]);
int vincitoreTurno(int nPlayers, int nRounds, double turni[nPlayers][nRounds], int round);
int trovaVincitore(int nPlayers, const int points[nPlayers]);
void stampaClassifica(int nPlayers, int lenStr, char giocatori[nPlayers][lenStr], int punteggi[nPlayers]);

/** fine prototipi studente **/

int main() {

    /** === VARIABILI ==================================================================================================
     * - giocatori è un array di stringhe che contiene i nomi dei giocatori partecipanti al torneo. Ci possono possono essere al massimo 8 giocatori.
     * - lanci è una matrice dove ogni riga rappresenta i lanci di un giocatore, mentre ogni colonna rappresenta un turno.
     * - punteggi è un array che contiene i punteggi dei giocatori.
     **/
    char giocatori[N_GIOCATORI][DIM_STR+1] = {"Federico", "Andrea", "Luca", "Riccardo"};
    double lanci[N_GIOCATORI][N_LANCI];
    int punteggi[N_GIOCATORI];

    /// init seed generazione casuale
    srand(time(NULL));

    ///stampa titolo
    printf("\n=== CAMPIONATO DI BOCCE ===\n\n");

    ///acquisizione giocatori rimanenti
    printf("Ci sono ancora 4 posti disponibili.\n");
    for(int i = 4; i < N_GIOCATORI; i++) {
        acquisisciGiocatore(i, N_GIOCATORI, DIM_STR+1, giocatori);
    }
    printf("\n\n");

    ///generazione lanci
    generaLanci(N_GIOCATORI, N_LANCI, lanci, MIN, MAX, DEC);

    ///stampa lanci
    stampaLanci(N_GIOCATORI, N_LANCI, DIM_STR+1, giocatori, lanci);

    ///calcolo punteggi
    calcolaPunteggi(N_GIOCATORI, N_LANCI, lanci, punteggi);

    ///stampa classifica (punteggi e vincitore)
    stampaClassifica(N_GIOCATORI, DIM_STR+1, giocatori, punteggi);

    /**/

    return 0;
}

/** === ESERCIZIO 1 (Acquisizione giocatori) [7pt] =======================================================================
 * Scrivere una subroutine acquisisciGiocatore che si occupi di far inserire all'utente un nuovo giocatore nella posizione k-esima
 * del vettore di stringhe passato come parametro.
 * NB: non devono essere presenti giocatori con lo stesso nome, altrimenti la subroutine deve chiedere di inserire un nuovo nome.
 * HINT: è possibile utilizzare le funzioni della libreria string viste a lezione.
 **/
void acquisisciGiocatore(int indexPlayer, int nPlayers, int lenStr, char giocatori[nPlayers][lenStr]) {
	char aux[lenStr + 1];
	bool found;

	do {
		found = false;

		// Acquisisco in una variabile ausiliaria il nome di un giocatore
		printf("\nInserisci giocatore in pos. %d", indexPlayer);
		scanf(" %[^\n]31s", aux);

		for (int i = 0; i < nPlayers && !found; ++i) {
			// Ciclo la lista di giocatori, o fin quando non termina, o se trovo un duplicato
			if (strcmp(aux, giocatori[i]) == 0){
				// Modifico il flag a true se trovo già nella lista il nome che desidero aggiungere
				found = true;
			}
		}

		if (found){
			printf("\n%s è gia presente, riprovare\n", aux);
		} else {
			// Accedo in questo branch dell'if se non viene modificata la varibaile found dal for
			printf("\nInserisco %s in pos %d\n", aux, indexPlayer);
			// Posso quindi assegnare il nome alla lista giocatori
			strcpy(giocatori[indexPlayer], aux);
		}

	} while (found);
}

/** === ESERCIZIO 2 (Generazione di un lancio) [2pt] ========================================================================
 * Scrivere una subroutine randRangeDouble che si occupi di generare e restituire un numero float generato casualmente
 * e compreso tra due interi min e max passati come parametro.
 * Il numero deve essere generato con n cifre decimali utili con n passato come parametro.
 **/

double randRangeDouble(int min, int max, int dec){
	double random;
	int mult;
	// mult è un moltiplicatore, utilizzato per la gen di numeri decimali
	mult = pow(10, dec);

	min *= mult;
	max *= mult;

	random = min + rand() % (max - min + 1);
	random /= mult;

	return random;
}

/** === ESERCIZIO 3 (Generazione di tutti i lanci) [4pt]================================================
 * Scrivere una subroutine generaLanci che si occupi di generare, con valori casuali, la matrice con le distanze del pallino.
 * I valori di estremi della generazione casuale devono essere passati come parametro alla subroutine.
 * Il numero deve essere generato con n cifre decimali utili (per esempio con n=3 generiamo 7.125)
 * HINT: sfruttare opportunamente la subroutine randRangeDouble.
 **/
void generaLanci(int nPlayers, int nRounds, double turni[nPlayers][nRounds], int min, int max, int dec){

	for (int i = 0; i < nPlayers; ++i) {
		for (int j = 0; j < nRounds; ++j) {
			// Ciclo la matrice dei tiri e ad ogni cella associo un numero double generato con randRangeDouble
			turni[i][j] = randRangeDouble(min, max, dec);
		}
	}

}

/** === ESERCIZIO 4 (Stampa lanci) [3pt] =============================================================================
 * Scrivere una subroutine stampaLanci che si occupi di stampare in output i lanci effettuati dai giocatori.
 * All'inizio di ogni riga deve essere stampato il nome del giocatore corrispondente.
 * HINT: per allineare correttamente i nomi dei giocatori, è possibile utilizzare il segnaposto %31s.
 **/

void stampaLanci(int nPlayers, int nRounds, int lenStr, char giocatori[nPlayers][lenStr], double turni[nPlayers][nRounds]){

	printf("%31s", ""); // L'angolo in alto a sx della tabella è occupato da uno spazio vuoto grande quanto il massimo nome di un giocatore
	for (int i = 0; i < nRounds; ++i) {
		// Per stampare l'intestazione dei turno ciclo attracerso il numero di rounds
		printf("T%d\t\t", i);
	}
	for (int i = 0; i < nPlayers; ++i) {
		putchar('\n');
		// Accanto ad ogni giocatore stampo le sue distanze
		printf("%31s\t", giocatori[i]);
		for (int j = 0; j < nRounds; ++j) {
			printf("%.3lf\t", turni[i][j]);
		}
		putchar('\n');
	}
}

/** === ESERCIZIO 5 (Calcolo punteggi) [7pt] ===========================================================================
 * Scrivere una subroutine calcolaPunteggi che si occupi di calcolare i punteggi dei giocatori.
 * I punteggi devono essere salvati nell'array punteggi passato come parametro.
 * HINT: per calcolare chi ha vinto il turno, è necessario trovare il minimo valore nella colonna corrispondente.
 * OPZIONALE: scrivere una subroutine vincitoreTurno che restituisce l'indice del giocatore che ha vinto il turno
 * e sfruttarlo nella subroutine calcolaPunteggi.
 **/
void calcolaPunteggi(int nPlayers, int nRounds, double turni[nPlayers][nRounds], int points[]){
	int winner;
	for (int i = 0; i < nRounds; ++i) {
		// Il vincitore di un round è dato dalla funz. vincitoreTurno
		winner = vincitoreTurno(nPlayers, nRounds, turni, i);
		// Incremento il punteggio del giocatore vincitore
		points[winner]++;
	}

}

int vincitoreTurno(int nPlayers, int nRounds, double turni[nPlayers][nRounds], int round){
	// Il vincitore di un turno sarà il giocatore di inidice i con la minor distanza fissato il turno da controllare

	int lower = 0;
	for (int i = 1; i < nPlayers; ++i){
		/* Ciclo le distanze e assegno alla var lower l'indice della distanza più bassa,
		 * trovato controllando se la distanza i sia minore di una già data
		 */
		if (turni[i][round] < turni[lower][round]){
			lower = i;
		}
	}

	return lower;
}

/** === ESERCIZIO 6 (Trova il vincitore) [4pt] =============================================================================
 * Scrivere una subroutine trovaVincitore che si occupi di restituire l'indice del giocatore con il punteggio più alto.
 * La subroutine restituisce l'indice del giocatore con il punteggio più alto.
 **/

int trovaVincitore(int nPlayers, const int points[nPlayers]){
	int index = 0;

	for (int i = 1; i < nPlayers; ++i) {
		/* Ciclo i punteggi e assegno alla var index l'indice del punteggio più basso,
		 * trovato controllando se un punteggio in particoalre è maggiore di un punteggio già dato
		 */
		if (points[i] > points[index]){
			index = i;
		}
	}

	return index;
}

/** === ESERCIZIO 7 (Stampa classifica) [3pt] =============================================================================
 * Scrivere una subroutine stampaClassifica che si occupi di stampare in output i punteggi dei giocatori.
 * All'inizio di ogni riga deve essere stampato il nome del giocatore corrispondente.
 * La subroutine deve stampare anche il nome del vincitore.
 * HINT: per allineare correttamente i nomi dei giocatori, è possibile utilizzare il segnaposto %31s.
 **/

void stampaClassifica(int nPlayers, int lenStr, char giocatori[nPlayers][lenStr], int punteggi[nPlayers]){
	int indexWinner;

	putchar('\n');
	// Stampo ogni giocatore e il punteggio associato
	for (int i = 0; i < nPlayers; ++i) {
		printf("%31s:\t%d\n", giocatori[i], punteggi[i]);
	}

	// Il vincitore è il giocatore trovato grazie alla proc. trovaVincitore
	indexWinner = trovaVincitore(nPlayers, punteggi);
	printf("\nAND THE WINNER IS %s, con %d punti", giocatori[indexWinner], punteggi[indexWinner]);
}

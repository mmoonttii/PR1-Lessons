/** === DESCRIZIONE ====================================================================================================
 * CONTESTO: Ci troviamo nella pizzeria del Palazzo delle Scienze. In questa particolare pizzeria, il prezzo di ogni
 * pizza varia a seconda del giorno della settimana. Abbiamo a disposizione un array di stringhe "listaPizze"
 * che rappresenta la pizze disponibili in dispensa. L'obiettivo del compito è quello di riempire la dispensa e
 * stabilire i prezzi giornalieri delle pizze contenuti all'interno di "prezziPizze".
 *
 * SVOLGIMENTO: Il compito consiste nell'implementazione di alcune subroutine che poi dovranno essere opportunamente
 * richiamate nel main, come indicato nel CONTESTO e dettagliato nel testo dei vari esercizi.
 *
 * CONSIGLIO: Risolvere gli esercizi in ordine di numerazione.
 *
 * VALUTAZIONE: Gli esercizi hanno un punteggio. Se svolti tutti correttamente si raggiunge il 30.
 * Si raccomanda di commentare adeguatamente il codice (un codice non commentato porterà MALUS sul voto finale).
 * È possibile modificare il codice che vi è stato fornito per ragioni di stile (eventuale BONUS sul voto finale).
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
#define MAX_PIZZE 10
#define LEN_PIZZE 30
#define DAYS_WEEK 7
#define DEC_CIFRE 2
/// Fine definizione macro studente

/// Altre dichiarazioni studente
void acquisisciPizza(int r, int c, char listaPizze[][c], int k);
float randRangeFloat(int min, int max);
void generaPrezzi(int r, int c, int max, int min, float prezziPizze[][c]);
void stampaPizze(int r, int c, int days, char listaPizze[][c], float prezziPizze[][days]);
/// Fine altre dichiarazioni studente

int main()
{
    /** === VARIABILI ==================================================================================================
     * - listaPizze è un array di stringhe che contiene i nomi delle pizze presenti in dispensa. Le dispensa può
     *   contenere al massimo 10 pizze e le prime 5 pizze sono già inserite in fase di inizializzazione.
     * - prezziPizze è una matrice numerica che contiene i prezzi delle pizze disponibili. Ogni riga della matrice
     *   rappresenta la corrispettiva pizza della lista di pizze (10 in tutto), mentre ogni colonna rappresenta un
     *   giorno della settimana (7 in tutto).
     * - min rappresenta il prezzo minimo a cui si può vendere una pizza.
     * - max rappresenta il prezzo massimo a cui si può vendere una pizza.
     **/
    char listaPizze[MAX_PIZZE][LEN_PIZZE + 1] = {"Margherita", "Marinara", "Ortolana", "Quattro formaggi", "Napoli"};
    float prezziPizze[MAX_PIZZE][DAYS_WEEK];
    const int min = 3;
    const int max = 11;

    /// Dichiarazioni variabili studnte
    // Init seed pseudo-random
    srand(time(NULL));
    char emptystr[LEN_PIZZE + 1] = {};
    /// Fine dichiarazioni variabili studente

    /** === ESERCIZIO 5 [3pt] ==========================================================================================
     * Richiamare la subroutine acquisisciPizza e assicurarsi di riempire la listaPizze con tutte e 10 le pizze
     * possibili.
     **/
    for (int i = 0; i < MAX_PIZZE; ++i) {
        if (strcmp(listaPizze[i], emptystr) == 0){
            acquisisciPizza(MAX_PIZZE, LEN_PIZZE + 1, listaPizze, i);
        }
    }

    /** === ESERCIZIO 6 [2pt] ==========================================================================================
     * Dati il minimo e il massimo per l'estrazione casuale del prezzo (min e max), generare i prezzi giornalieri
     * delle pizze utilizzando la funzione dell'esercizio 3.
     **/
    generaPrezzi(MAX_PIZZE, DAYS_WEEK, max, min, prezziPizze);

    /** === ESERCIZIO 7 [1pt] ==========================================================================================
     * Richiamare la subroutine stampaPizze.
     **/
    stampaPizze(MAX_PIZZE, LEN_PIZZE + 1, DAYS_WEEK, listaPizze, prezziPizze);

    return 0;
}

void acquisisciPizza(int r, int c, char listaPizze[][c], int k){
    /** === ESERCIZIO 1 (Acquisizione stringa) [9pt] =======================================================================
    * Scrivere una subroutine acquisisciPizza che si occupi di far inserire all'utente una nuova pizza e la inserisca
    * nella posizione k-esima dell'array di stringhe listaPizze, con listaPizze e k passati come parametri.
    * NB: non devono essere presenti pizze con lo stesso nome. Se l'utente inserisce una pizza già presente, deve essere
    * chiesto nuovamente l'inserimento.
    * HINT: è possibile utilizzare le funzioni della libreria string viste a lezione (SOLO quelle viste a lezione).
    **/
    bool found;

    do {

        found = false;

        printf("Inserisci pizza in pos %d: ", k);
        scanf(" %[^\n]30s", listaPizze[k]);

        for (int i = 0; i < r; ++i) {
            if (i != k) {
                found = strcmp(listaPizze[i], listaPizze[k]) == 0;
            }
        }
        if (found){
            printf("\nPizza %s già in elenco, riprovare", listaPizze[k]);
        } else {
            printf("\nPizza %s inserita in pos. %d", listaPizze[k], k);
        }
    } while (found);
}

float randRangeFloat(int min, int max){
    /** === ESERCIZIO 2 (Generazione casuale) [3pt] ========================================================================
    * S4crivere una subroutine randRangeFloat che si occupi di generare e restituire un numero float generato casualmente
    * e compreso tra min e max; min e max sono due parametri di tipo intero passati alla subroutine.
    * Il numero deve essere generato con due cifre decimali utili (per esempio: 7.15).
    **/
    float random;
    int mult = pow(10, DEC_CIFRE);

    random = min*mult + rand() % (max*mult - min*mult + 1);
    random = random/mult;

    return random;
}

void generaPrezzi(int r, int c, int max, int min, float prezziPizze[][c]){
    /** === ESERCIZIO 3 (Inserimento dati in una una matrice numerica) [5pt]================================================
     * Scrivere una subroutine generaPrezzi che si occupi di generare, con valori casuali, la matrice con i prezzi delle
     * pizze. La subroutine deve ricevere, almeno, i seguenti parametri: la matrice dei prezzi, min (intero), max (intero).
     * HINT: sfruttare opportunamente la subroutine randRangeFloat.
     **/
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            prezziPizze[i][j] = randRangeFloat(min, max);
        }
    }
}

void stampaPizze(int r, int c, int days, char listaPizze[][c], float prezziPizze[][days]){
    /** === ESERCIZIO 4 (Stampa matrici) [7pt] =============================================================================
     * Scrivere una subroutine stampaPizze che si occupi di stampare in output le pizze presenti nella lista di pizze,
     * e il loro prezzo giornaliero, con listaPizze e prezziPizze forniti come parametri.
     **/
    printf("\t\t\tLun\tMar\tMer\tGio\tVen\tSab\tDom\n");
    for (int i = 0; i < r; ++i) {
        printf("%s", listaPizze[i]);
        for (int j = 0; j < days; ++j) {
            printf("%.2f\t", prezziPizze[i][j]);
        }
        putchar('\n');
    }
}
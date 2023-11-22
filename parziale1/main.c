#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define ROULETTE_MIN 1
#define ROULETTE_MAX 36
#define MONEY_START 100.0

#define TURNI_MAX 10
#define TURNI_SEGUITO 4

#define QUARTO 'Q'
#define META 'M'
#define ALL 'A'

int main() {
    // init variabili
    int puntataNum, roulette;                     // puntataNum: numero sul quale puntare
                                                  // roulette: Numero generato dalla roulette
    float puntataSoldi, portafogli = MONEY_START; // puntataSoldi: Quantità di denaro puntato
                                                  // portafogli: denaro dell'utente. Inizializzato a MONEY_START, denaro di partenza
    char puntataChoice;                           // Scelta denaro da puntare
    bool exitChoice;                              // exitChoice: Condizione di uscita alla scelta di denaro da puntare

    bool win;         // Vincita turno per turno
    float plusMinus;  // Differenza tra denaro iniziale e denaro al termine del turno

    int turno = 0, turniDiSeguito; 			// turno: Numero del turno
                                   			// turniDiSeguito: Turni persi di Seguito
    bool end = false;                       // Condizione di termine del ciclo di turni

    float cashback; // Eventuale cash-back ricevuto in caso di perdita

    // Genero seed per generazione casuale
    srand(time(NULL));

    do {
        // Acquisizione numero su cui puntare
        do {
            printf("Su quale numero vuoi puntare [%d - %d]: ", ROULETTE_MIN, ROULETTE_MAX);
            scanf("%d", &puntataNum);

        } while (puntataNum < ROULETTE_MIN ||
                 puntataNum > ROULETTE_MAX); // Il codice prosegue se la puntata è compresa tra i valori ammessi

        // Acquisizione denaro da puntare
        do {
            printf("Quanto puntare?\n"
                   "[%c] 1/4 dell'importo in tuo possesso\n"
                   "[%c] 1/2 dell'importo in tuo possesso\n"
                   "[%c] All-in (tutto l'importo in tuo possesso): ", QUARTO, META, ALL);

            scanf(" %c", &puntataChoice);

            exitChoice = false;

            switch (puntataChoice) {
                // Gestisco la scelta della puntata con uno switch che riceve la scelta dell'utente
                // e restituisce la puntata basandosi sul denaro rimanente
                case QUARTO:
                    puntataSoldi = portafogli * 0.25;
                    portafogli -= puntataSoldi;
                    break;

                case META:
                    puntataSoldi = portafogli * 0.5;
                    portafogli -= puntataSoldi;
                    break;

                case ALL:
                    puntataSoldi = portafogli;
                    portafogli -= puntataSoldi;
                    break;

                // In caso il carattere inserito non sia uno di quelli richiesti non permetto l'uscita dal loop
                default:
                    printf("\nInserisci un valore valido");
                    exitChoice = true;
                    break;
            }
        } while (exitChoice);

        printf("\nDenaro puntato: %.2f", puntataSoldi);

        // Estrazione numero della roulette
        roulette = ROULETTE_MIN + rand() % (ROULETTE_MAX - ROULETTE_MIN + 1);

        // Acquisizione variabile per gestione vincita
        win = (roulette == puntataNum) ? true : false;

        // Comunicazioni post-turno

        // Numero giocato e numero estratto.
        printf("\nNumero giocato: %d\tNumero estratto: %d", puntataNum, roulette);

        // Stampse il giocatore ha vinto o perso in quel turno e eventuale vincita
        if (win) {
            portafogli += puntataSoldi * 2;
            printf("\nHai vinto %.2f EUR", puntataSoldi * 2);
            turniDiSeguito = 0; // Quando si vince il contatore dei turni di seguito persi viene re-inizializzato
        } else {
            printf("\nHai perso");
            turniDiSeguito++; // Quando si perde viene incrementato il contatore dei turni persi di fila
        }

        // Stamapa saldo rimanente
        printf("\nSaldo rimanente: %.2f", portafogli);

        // Stampa plus/minus vincite
		plusMinus = portafogli - MONEY_START;
        printf("\nRispetto alla situazione iniziale hai %.2f EUR", plusMinus);

        turno++; // Al termine di ogni turno incremento il counter relativo

        // Condizioni di termine
        if (turniDiSeguito == TURNI_SEGUITO || turno >= TURNI_MAX || portafogli <= 0){
            end = true;
        }

    } while(end != true);

    /* Se il giocatore a fine partita è andato in perdita rispetto alla somma iniziale, riceve
     * indietro (come cash-back) la radice quadrata della perdita.
     * Stampare saldo a fine partita ed eventuale cash-back se ricevuto.
     */

    if (portafogli < MONEY_START){
        cashback = sqrtf(MONEY_START - portafogli);
        portafogli += cashback;

        printf("\nTi e' stato dato e': %.2f\n", cashback);
    }

    printf("Hai terminato il gioco con %.2f EUR", portafogli);

    return 0;
}
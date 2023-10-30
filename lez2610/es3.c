/* 1) Memorizzare in una variabile un intero casuale generato nell'intervallo [1, 90] estremi inclusi
 * che rappresenti il minuto di una partita di calcio in cui è stata segnata una rete.
 * 2) Chiedere quindi all’utente il numero del giocatore che ha segnato tale rete (si ipotizzi che i
 * valori possibili siano da 1 a 11).
 * 3) Tramite un costrutto IF verificare se la rete è stata segnata al primo o al secondo tempo e a
 * seconda dei due casi stampare un messaggio relativo (ogni tempo ha durata 45 minuti).
 * 4) Mediante uno SWITCH-CASE stampare in output il messaggio:
 * "Portiere" se il numero del giocatore è uguale a 1
 * "Difensore" se il numero del giocatore è >= 2 e <=4
 * "Centrocampista" se numero del giocatore è >= 5 e <=8
 * ”Attaccante" se numero del giocatore è >= 9 e <=11
 * 5) Modificare il programma per gestire il caso in cui l’utente inserisca un input non valido,
 * permettendo di ripetere la scelta.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MINUTO_MIN 1
#define MINUTO_MAX 90

int es3(){
    int minuto, giocatore, exitCondition;

    srand(time(NULL));

    minuto = MINUTO_MIN + rand() % (MINUTO_MAX - MINUTO_MIN + 1);

    do {
        printf("Quale giocatore ha segnato al minuto %d? [1 - 11] ", minuto);
        scanf("%d", &giocatore);

        exitCondition = (giocatore >= 1 && giocatore <= 11) ? 0 : 1;
    } while (exitCondition);

    if (minuto <= 45){
        printf("Primo Tempo\n");
    } else {
        printf("Secondo Tempo\n");
    }

    switch (giocatore) {
        case 1:
            printf("Portiere");
            break;
        case 2:
        case 3:
        case 4:
            printf("Difensore");
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            printf("Centrocampista");
            break;
        case 9:
        case 10:
        case 11:
            printf("Attaccante");
            break;
    }
    return 0;
}
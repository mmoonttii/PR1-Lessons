/* Scrivere un programma in cui si devono calcolare le misure di una sfera dato raggio r
 * Il programma deve acquisire un valore booleano e, nel caso sia TRUE, chiedere all'utente di inserire il valore
 * del raggio della sfera da tastiera. In caso in cui sia False generarlo in modo casuale con 2 cifre decimali
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Definisco i valori massimo e minimo del raggio della sfera, il moltiplicatore indica il numero di cifre decimali
#define RADIUS_MAX 500
#define RADIUS_MIN 1
#define MULTIPLIER 100

// Definisco le operazioni
#define CIRCONFERENZA 'c'
#define DIAMETRO 'd'
#define VOLUME 'v'
#define SUPERFICIE 's'
#define CIRC_APPROX 'a'

int es1() {

    // Init variabili
    int aux, approx; // aux: per definire il booleano
                     // approx: per gestire l'approssimazione della circonferenza
    bool flag, exit; // flag: Variabile booleana per indicare input: [T] Tastiera [F] Random
                     // exit: Exit condition per do-while
    float radius, ans; // radius: Raggio della sfera
                       // ans: Risposta
    char op; // Operazione da eseguire

    // Init seed pseudo-random
    srand(time(NULL));

    // Acquisisco scelta per input
    printf("Digitare [1] per inserire manualmente il valore del raggio\n"
           "Digitare [0] per generare randomicamente il valore del raggio\n"
           "Inserisci valore: ");
    scanf("%d", &aux);
    flag = aux != 0 ? true : false; // Asseggno alla variabile booleana l'input dell'user

    if (flag){
        // Se Vero il valore del raggio è acquisito da tastiera

        printf("Inserire il valore del raggio: ");
        scanf("%f", &radius);
        radius = fabsf(radius);

    } else {

        /* Se Falso generiamo randomicamente il raggio secondo la formula
         * min + rand() % (max - min + 1). Per ottenere un decimale a due cifre, faccio la generazione
         * dei numeri 100 volte più grandi e succesivamente divido per 100
         */

        radius = (float)(RADIUS_MIN * MULTIPLIER + rand() % (RADIUS_MAX * MULTIPLIER - RADIUS_MIN * MULTIPLIER + 1));
        radius /= MULTIPLIER;
        printf("Il raggio della sfera è %f", radius);
    }

    /* Ottenuto il raggio chiedere all'utente quale misura calcolare
     * c circonferenza, d diametro, v volume, s superficie, a circonferenza approssimata per difetto.
     * Gestire approssimazione per eccesso. Effettuare queste operazione in uno switch-case.
     * Gestire l'eventuale input non valido, permettendo di ripetere la scelta
     */

    do {
        printf("\nQuale misura desideri calcolare? ");
        printf("\n- [%c] circonferenza c = 2 * pi * r", CIRCONFERENZA);
        printf("\n- [%c] diametro d = 2 * r", DIAMETRO);
        printf("\n- [%c] volume v = (4 * pi * (r ^ 3)) / 3", VOLUME);
        printf("\n- [%c] superficie s = 4 * pi * r ^ 2", SUPERFICIE);
        printf("\n- [%c] circonferenza approssimata", CIRC_APPROX);
        printf("\nInserire valore corrispondente:");
        scanf(" %c", &op);

        exit = false;

        switch (op) {
            case CIRCONFERENZA:
                ans = 2 * M_PI * radius;
                break;

            case DIAMETRO:
                ans = 2 * radius;
                break;

            case VOLUME:
                ans = (float)(4 * M_PI * powf(radius, 3) / 3);
                break;

            case SUPERFICIE:
                ans = 4 * M_PI * powf(radius, 2);
                break;

            case CIRC_APPROX:
                ans = 2 * M_PI * radius;

                // Sposto le cifre un posto verso sinistra
                approx = (int)(ans * 10);
                // Isolo i decimi, ora al posto dell'unità
                approx %= 10;

                // Se i decimi sono < 5 approssimo per difetto, altrimenti per eccesso
                if (approx < 5){
                    ans = (int)ans;
                } else {
                    ans = (int)ans + 1;
                }
                break;

            default:
                printf("Il carattere inserito non è una delle opzioni disponibili");
                exit = true;
                break;

        }
    } while (exit);

    printf("Il risultato è: %f", ans);

    return 0;
}

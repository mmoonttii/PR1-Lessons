/* Si vogliono dividere gli allievi di un corso in tre squadre denominate
 * ROSSA, VERDE e BLU secondo il loro numero di matricola.
 * L’assegnazione avviene con il seguente criterio: l’allievo con matricola
 * 1 va nella squadra ROSSA, quello con matricola 2 nella VERDE, quello
 * con matricola 3 nella BLU, quello con matricola 4 nella ROSSA, quello
 * con 5 nella VERDE ecc. Il programma deve chiedere il numero di
 * matricola dell’allievo e indicare a quale squadra è assegnato. Usare il
 * costrutto if
 */

#include <stdio.h>

int es4(){
    // Inizializzazione variabili e acquisizione valori
    int matricola;

    printf("Inserire matricola: ");
    scanf("%d", &matricola);

    /*
     * if (matricola % 3 == 1){
     *   printf("Squadra Rossa");
     * } else if (matricola % 3 == 2){
     *    printf("Squadra Verde");
     * } else if (matricola % 3 == 0){
     *    printf("Squadra Blu");
     * }
     */

    // Il modulo restituisce la classe della matricola e a ogni classe associo una squadra
    switch (matricola % 3) {
        case 1:
            printf("Squadra Rossa");
            break;
        case 2:
            printf("Squadra Verde");
            break;
        case 0:
            printf("Squadra Blu");
            break;
    }

    return 0;
}
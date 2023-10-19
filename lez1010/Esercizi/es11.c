// Dato un intero di 4 cifre stampi il numero di unità, decine, centinaia, migliaia

#include <stdio.h>

int main(){
    // Inizializzazione variabili
    int num, units, tens, hunds, thous;

    // Acquisizione valori
    printf("Insrire numero di 4 cifre: ");
    scanf("%d", &num);

    // Calcolo
    /* Ogni posizione nell''intero rappresenta una potenza del 10
     * Divido il risultato della divisione intera tra il numero e la potenza di 10
     * restituisce la singola cifra. È necessario rimuovere la parte già già calcolata,
     * per procedere allo stesso modo con ogni cifra */
    thous = num / 1000;
    num -= thous * 1000;
    hunds = num / 100;
    num -= hunds * 100;
    tens = num / 10;
    num -= tens * 10;

    // Stampa valori
    printf("Migliaia: %d", thous);
    printf("\nCentinaia: %d", hunds);
    printf("\nDecine: %d", tens);
    printf("\nUnità: %d", num);

    return 0;
}
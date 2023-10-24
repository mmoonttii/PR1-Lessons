/* Scrivere un programma che esegua la divisione tra due numeri, chiedendo
 * di inserire nuovamente il divisore finchè questo non è diverso da 0
 */

#include <stdio.h>
#include <stdbool.h>

int es1(){
    int divisore, dividendo;
    float quoziente;
    bool check;

    printf("Inserisci dividendo: ");
    scanf("%d", &dividendo);

    do {
        printf("\nInserisci divisore: ");
        scanf("%d", &divisore);

        check = (dividendo == 0);

        if (check) {
            printf("\nNon puoi effettuare divisione per 0");
        }
    } while (check);

    quoziente = (float)dividendo / divisore;
    printf("\nIl risultato è %f", quoziente);

    return 0;
}
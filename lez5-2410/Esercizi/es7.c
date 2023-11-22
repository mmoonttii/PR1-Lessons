// Scrivere un programma che richieda N numeri da tastiera e ne calcoli il valore massimo.
#define N_NUMERI 10

#include <stdio.h>

int es7(){
    int max, num, counter = 0;

    do{
        printf("Inserisci numero: ");
        scanf("%d", &num);

        if (counter == 0){
            max = num;
        } else if (counter < N_NUMERI){
            if (num > max){
                max = num;
            }
        }

        counter ++;
    } while (counter < N_NUMERI);

    printf("Num massimo: %d", max);

    return 0;
}
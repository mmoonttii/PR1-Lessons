// Calcolare il numero di cifre che compongono un numero intero inserito dall'utente

#include <stdio.h>

int es2(){
    int input, cifre = 0;

    printf("Inserisci num: ");
    scanf("%d", &input);

    while(input > 0){
        input /= 10;
        cifre++;
    }

    printf("Num cifre: %d", cifre);

    return 0;
}
#include <stdio.h>

int es1(){
    int num;

    printf("Inserisci num: ");
    scanf(" %d", &num);

    if (num % 2 == 0)
        printf("Pari");
    else
        printf("Dispari");

    return 0;
}
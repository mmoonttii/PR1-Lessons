#include <stdio.h>
#define FATTORE_CONVERSIONE 1.8

int es5(){
    float celsius, fahrenheit;

    printf("Inserisci C°: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius*FATTORE_CONVERSIONE) + 32;

    celsius = (fahrenheit - 32)/FATTORE_CONVERSIONE;

    printf("\nF°: %.2f", fahrenheit);
    printf("\nProva C°: %.2f", celsius);

    return 0;
}
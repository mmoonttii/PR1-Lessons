#include <stdio.h>

int es5(){
    float celsius, fahrenheit;

    printf("Inserisci C°: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius*1.8) + 32;

    celsius = (fahrenheit - 32)/1.8;

    printf("\nF°: %.2f", fahrenheit);
    printf("\nProva C°: %.2f", celsius);

    return 0;
}
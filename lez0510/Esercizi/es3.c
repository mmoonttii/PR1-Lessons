#include <stdio.h>
#define NUM_VALORI 3

int es3(){
    int a, b, c; // Dichiarazione varibili

    //Acquisizione valori
    printf("a: ");
    scanf("%d", &a);
    printf("\nb: ");
    scanf("%d", &b);
    printf("\nc: ");
    scanf("%d", &c);

    // Calcolo della media
    float avg;
    avg = (a + b + c)/NUM_VALORI;
    // Indicando %.2f arrotondo il valore a due cifre decimali
    printf("La media è %.2f", avg);

    return 0;
}
#include <stdio.h>
#define NUM_VALORI 3

int main(){
    int a, b, c; // Dichiarazione varibili

    //Acquisizione valori
    printf("a: ");
    scanf(" %d", &a);
    printf("b: ");
    scanf(" %d", &b);
    printf("c: ");
    scanf(" %d", &c);

    // Calcolo della media
    float avg = (float)(a + b + c)/NUM_VALORI;

    // Indicando %.2f arrotondo il valore a due cifre decimali
    printf("La media è %.2f", avg);

    return 0;
}
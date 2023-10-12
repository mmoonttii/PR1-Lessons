#include <stdio.h>
#include <math.h>

// Inseriti i cateti, calcolare l'ipotenusa

int es1(){
    // Due cateti e ipotenusa
    float c1, c2, ip;

    // Acquisizione valori
    printf("Inserire cateto1: ");
    scanf("%f", &c1);

    printf("Inserire cateto2: ");
    scanf("%f", &c2);

    // Calcolo ipotenusa
    ip = sqrt(pow(c1, 2) + pow(c2, 2));

    printf("Ipotenusa: %lf", ip);

    return 0;
}
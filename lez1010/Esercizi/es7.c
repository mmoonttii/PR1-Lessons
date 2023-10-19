/* Scrivere un programma che si occupa di gestire la conversione mph - kph,
 * Dato il tasso di conversione 1 mi = 1.61 km */

#include <stdio.h>
#define T_CONV_MPH_TO_KPH 1.61

int es7() {
    // Inizializzazione variabili
    float velocitaMph, velocitaKph;

    // Acquisizione valori
    printf("Inserire la velocità in mph da convertire: ");
    scanf("%f", &velocitaMph);

    // Conversione
    velocitaKph = velocitaMph * T_CONV_MPH_TO_KPH;

    // Stampa valori
    printf("Velocità in mph: %.1f mph\nVelocità in kph: %.1f kph", velocitaMph, velocitaKph);

    return 0;
}
#include <stdio.h>

/* Scrivere un programma che acquisisca l'età per ottenere la patente nel proprio paese
 * e l'età dell'utente. Comunichi se può prendere la patente */

int es42(){
    // Variabili divisione
    int etaAuto, eta, etaScooter;

    // Input dividendo divisore
    printf("Inserisci età per ottenere la patente della macchina: ");
    scanf("%d", &etaAuto);
    printf("Inserisci età per ottenere la patente del Motorino: ");
    scanf("%d", &etaScooter);
    printf("Inserisci età: ");
    scanf("%d", &eta);

    if (eta >= etaScooter){
        printf("Puoi prendere le patenti per: motorino");
        if (eta >=etaAuto)
        printf(", auto");
    } else {
        printf("Non puoi prendere la patente, devi avere %d anni", etaScooter);
    }

    return 0;
}
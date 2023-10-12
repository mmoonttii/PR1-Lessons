#include <stdio.h>

/* Scrivere un programma che acquisisca due valori interi e esegua la divisione tra essi
 * Nel caso il secondo valore sia 0, si fermi */

int es41(){
    // Variabili divisione
    int a, b, ris;

    // Input dividendo divisore
    printf("Inserisci a:");
    scanf("%d", &a);
    printf("Inserisci b:");
    scanf("%d", &b);

    if (b != 0) {
        ris = a / b;
        printf("ris: %d", ris);
    } else
        printf("Non posso dividere per 0");

    return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int calcSwitch() {

    float a, b;
    float ris;
    char select;
    bool check = true;

    // inizializzazione seed random
    srand(time(NULL));

    printf("Inserisci valore 1: ");
    scanf("%f", &a);
    printf("Inserisci valore 2: ");
    scanf("%f", &b);

    printf("Che operazione vuoi fare?");
    printf("\n[+ somma, - sottrazione, * moltiplicazione, / divisione]");
    printf("\n[^ potenza, s radice quadrata, r numero random a-b]: ");
    scanf(" %c", &select);

    switch (select) {
        case '+':               // somma
            ris = a + b;
            break;

        case '-':               // sottrazione
            ris = a - b;
            break;

        case '*':               // moltiplicazione
            ris = a * b;
            break;

        case '/':
            if (b != 0) {                // divisione
                ris = a / b;
            } else {
                printf("\n Non si può dividere per 0");
                check = false;
            }
            break;

        case '^':               // potenza
            ris = powf(a, b);
            break;

        case 's':               // radice
            ris = sqrtf(a);
            break;

        case 'r':               // random
            ris = a + rand() % (int)(b-a+1);
            break;
        default:                // errore
            printf("\nOperazione non valida"); // Operatore non corretto
            check = false;
            break;
    }

    if (check)                  // stampa
        printf("\nRisultato: %.3f", ris);

    return 0;
}

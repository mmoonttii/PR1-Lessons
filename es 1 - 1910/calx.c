#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int calcx() {

    float a, b, aux;
    float ris;
    char select;
    int numCifre;
    float multiplier;
    bool check = true;


    // inizializzazione seed random
    srand(time(NULL));

    printf("Inserisci valore 1: ");
    scanf("%f", &a);
    printf("Inserisci valore 2: ");
    scanf("%f", &b);

    printf("Che operazione vuoi fare?");
    printf("\n[+ somma, - sottrazione, * moltiplicazione, / divisione]");
    printf("\n[^ potenza, s radice quadrata, r numero random a-b, g numero random decimale]: ");
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
            if (b < a){
                aux = b;
                b = a;
                a = aux;
            }

            ris = a + rand() % (int)(b-a+1);
            break;

        case 'g':               // random due cifre decimali
            printf("\nNumero cifre decimali: ");
            scanf("%d", &numCifre);
            numCifre = abs(numCifre);

            multiplier = powf(10, numCifre);

            if (b < a){
                aux = b;
                b = a;
                a = aux;
            }

            a *= multiplier;
            b *= multiplier;

            ris = a + rand() % (int)(b-a+1);
            ris /= multiplier;
            break;

        default:                // errore
            printf("\nOperazione non valida"); // Operatore non corretto
            check = false;
            break;
    }

    if (check)                  // stampa
        printf("\nRisultato: %f", ris);

    return 0;
}

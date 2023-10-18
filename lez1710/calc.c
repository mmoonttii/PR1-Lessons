#include <stdio.h>
# include <math.h>

int calc() {

    float a, b;
    float ris;
    char select;

    printf("Inserisci valore 1: ");
    scanf("%f", &a);
    printf("Inserisci valore 2: ");
    scanf("%f", &b);

    printf("Che operazione vuoi fare?");
    printf("\n[+ somma, - sottrazione, * moltiplicazione, / divisione]");
    printf("\n[^ potenza, s radice quadrata]");
    scanf(" %c", &select);

    if (select == '+'){         // Somma
        ris = a + b;
    } else if (select == '-'){  // Sottrazione
        ris = a - b;
    } else if (select == '*'){  // Moltiplicazione
        ris = a * b;
    } else if (select == '/') {  // Divisione
        if (b != 0) {
            ris = a / b;
        } else {
            printf("\nNon è possibile dividere per 0"); // Divisione per 0
            return 2;
        }
    } else if (select == '^') {     // Potenza a^b
        ris = powf(a, b);
    } else if (select == 's') {     // Radice quadrata di a
        ris = sqrtf(a);
    } else {
        printf("\nOperazione non valida"); // Operatore non corretto
        return 1;
    }

    printf("\nRisultato: %.3f", ris);

    return 0;
}

#include <stdio.h>

int scantest(){
    int num;
    char x;

    // Caso 0
    printf("Inserisci valore per num: ");
    scanf("%d", &num); // & indica l'indirizzo di memoria della variabilie dove vogliamo inserire il valore

    printf("Inserisci valore per char: ");
    scanf("%c", &x);

    printf("\nnum: %d", num);
    printf("\nchar: %c", x);
    /* Facnedo così, il secondo scanf() prende dal buffer in nostro INVIO
     * e lo inserisce come carattere nella variabile*/

    // Caso 1
    printf("\nInserisci valore per num: ");
    scanf("%d", &num);

    getchar(); /* Inserendo getchar() la funzione elabora il carattere INVIO,
                * evitando che questo venga assegnato da scanf */

    printf("Inserisci valore per char: ");
    scanf("%c", &x);

    printf("\nnum: %d", num);
    printf("\nchar: %c", x);

    // Caso 2
    printf("\nInserisci valore per num: ");
    scanf("%d", &num);

    printf("Inserisci valore per char: ");
    scanf(" %c", &x); // Aggiungendo uno spazio prima di %c, il buffer viene svuotato

    printf("\nnum: %d", num);
    printf("\nchar: %c", x);

    return 0;
}
/* Scrivere un programma in cui viene generato casualmente un numero intero compreso
 * tra 0 e 99 e chiedere all’utente di indovinare quel numero. Ad ogni input dell’utente il
 * programma risponde con “troppo alto” o “troppo basso”, finché non viene trovato il
 * valore corretto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RANDOM_MAX 99

int es8(){
    int daIndovinare, tentativo;
    bool flag = true;

    srand(time(NULL));

    daIndovinare = rand()%(RANDOM_MAX + 1);

    do {
        printf("\nInserisci tentativo: ");
        scanf("%d", &tentativo);

        if (tentativo > daIndovinare){
            printf("Troppo alto");
        } else if (tentativo < daIndovinare) {
            printf("Troppo basso");
        } else if (tentativo == daIndovinare){
            printf("Complimenti hai indovinato");
            flag = false;
        }
    } while (flag);

    return 0;
}
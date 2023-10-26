/* Scrivere un programma che calcoli la media di tutti i valori introdotti dalla tastiera
 * finché non ne viene introdotto uno non compreso tra 18 e 30. La visualizzazione della
 * media deve avvenire solo alla fine, e non ogni volta che un valore viene introdotto.
 */

#include <stdio.h>
#include <stdbool.h>

#define VOTO_MIN 18
#define VOTO_MAX 30
int es6(){
    int voto, somma = 0, counter = 0;
    float media;
    bool flag = true;

    do {
        printf("Inserisci voto: ");
        scanf("%d", &voto);

        if (voto >= VOTO_MIN && voto <= VOTO_MAX){
            somma += voto;
            counter++;
        } else {
            flag = false;
            printf("Voto non compreso tra 18 e 30. Terminando...");
        }

    } while (flag);

    media = (float)somma/counter;
    printf("\nMedia: %.2f", media);
    return 0;
}
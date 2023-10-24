/*Scrivere un programma che chieda all'utente un numero num e generi continuamente numeri casuali compresi tra 0 e MAX
 * finchè il numero generato non è maggiore di num. Stampare il numero di valori generati casualmente e il valore maggiore di num
 * Opzionalmente verificare che l'utente inserisca un valore consono
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
int es3(){
    int num, random, counter = 0;

    srand(time(NULL));

    do {
        printf("Inserisci num < %d: ", MAX);
        scanf("%d", &num);
    } while (num > MAX);

    do {
        random = rand() % (MAX + 1);
        counter++;
        printf("\n%d", random);
    } while (random < num);

    printf("\n%d tentativi", counter);

    return 0;
}
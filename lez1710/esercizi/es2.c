/* Scrivere un programma che generi un numero casuale tra 0 e
 * 10 e chieda poi all’utente di inserire un valore tra 0 e 10
 * Se il numero inserito è maggiore di 10 o minore di 0 il
 * programma deve stampare un messaggio di errore.
 * Altrimenti, deve stampare "Numero uguale" se il valore
 * inserito dall’utente è lo stesso generato casualmente o, in
 * caso contrario, deve stampare la differenza in valore assoluto
 * tra i due numeri.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int es2(){
    // Inizializzazione seed random
    srand(time(NULL));

    int random;
    int inputUser;

    random = rand() % 10 + 1; // random in range(min, max) = min + rand % (max - min + 1)
    printf("Inserire numero compreso tra 0 e 10: ");
    scanf("%d", &inputUser);

    if (inputUser > 10 || inputUser < 0){
        printf("Numero inserito non rispetta le condizioni");
    } else if (inputUser == random){
        printf("Numero uguale");
    } else {
        printf("%d", abs(random - inputUser));
    }
    return 0;
}
/* Scrivere un programma che converta un numero binario in un numero decimale.
 * Il numero binario è rappresentato su N bit, e il valore di N è inserito da tastiera.
 * Inoltre, l’utente inserisce le cifre del numero binario un bit alla volta, partendo dal bit
 * meno significativo (ossia dal bit di peso 2^0).
 * Il programma deve visualizzare il numero decimale corrispondente.
 */

#include <stdio.h>
#include <math.h>

#define BASE 2

int es6(){
    int bin, dec = 0, bits, counter = 0;

    printf("Inserire numero di bit: ");
    scanf("%d", &bits);

    while (counter < bits){
        printf("Inserire bit di posizione %d^%d: ", BASE, counter);
        scanf("%d", &bin);

        dec += (int)pow(BASE, counter) * bin;

        counter++;
    }

    printf("Il numero in base 10 è %d", dec);
    return 0;
}
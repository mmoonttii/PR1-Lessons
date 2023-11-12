/* Scrivere un programma che acquisisca due numeri float in successione.
 * Per ogni numero inserito dovrà essere calcolara la media e
 * stampato il minore ed il maggiore inseriti fino a quel momento.
 * Il programma deve terminare nel momento in cui si inserisce 0 o qualsiasi negativo
 */

#include <stdio.h>

int es5(){
    float input, sum = 0, max = 0, min = 0, avg;
    int counter = 0;

    do {
        printf("\ninput (0 termina): ");
        scanf("%f", &input);

        // check validità
        if (input >= 0){
            counter++;
            // media
            sum += input;
            avg = sum / (float)counter;
            printf("\navg: %f", avg);
        }

        // init min e max
        if (counter == 1) {
            min = input;
            max = input;
        }

        // calcolo max e min
        if (input > max){
            max = input;
        } else if (input < min){
            min = input;
        }

        printf("\nmax: %f", max);
        printf("\nmin: %f", min);

    } while (input != 0);

    return 0;
}
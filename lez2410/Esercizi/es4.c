/* Scrivere un programma che, dati due numeri a e b generati casualmente,
 * calcoli a^b senza usare funzioni di libreria
 * Verificare la corretteza del risultato utilizzando pow() da math.h
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX 10

int es4(){
    srand(time(NULL));

    int a, b, potenza = 1, powMath;
    a = rand() % (MAX + 1);
    b = rand() % (MAX + 1);

    powMath = pow(a, b);

    while (b > 0){
        potenza *= a;
        b--;
    }

    printf("While: %d", potenza);

    printf("\nMath.h: %d", powMath);

}
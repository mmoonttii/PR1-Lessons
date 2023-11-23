/* Scrivere due procedure che andranno richiamate nel main:
 * • popolaMatrice che riceva come parametro una matrice di float e generi casualmente i suoi elementi in un
 * range definito dall’utente, sfruttando randRangeFloat dell’esercizio 1; anche righe e colonne vanno generate
 * casualmente.
 * • stampaMatrice che prenda come parametro una matrice di float e ne stampi il suo contenuto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define R 30
#define C 30

void popolaMatrice(int min, int max, int r, int c, float mx[][c]);
float floatRandRange(int min, int max, int dec);
void stampaMatrice(int c, int r, float mx[][c]);

int main(){
    srand(time(NULL));
    float matrix[R][C];

    int min,
        max,
        r,
        c;

    printf("In min:");
    scanf("%d", &min);
    printf("In max:");
    scanf("%d", &max);

    r = floatRandRange(min, max, 0);
    c = floatRandRange(min, max, 0);

    popolaMatrice(min, max, r, c, matrix);

    stampaMatrice(c, r, matrix);

    return 0;
}

void popolaMatrice(int min, int max, int r, int c, float mx[][c]){
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          mx[i][j] = floatRandRange(min, max, 2);
        }
    }
}

float floatRandRange(int min, int max, int dec){ // floatRandRange restituisce un numero random compreso tra min e max
    int aux;
    float random;
    int mult;

    // Se min e max sono scambiati mi assicuro che la gen avvenga tranquillamente
    if (min > max){
      aux = min;
      min = max;
      max = aux;
    }
    // mi assicuro che il num di cifre decimali sia non negativo
    dec = abs(dec);
    mult = pow(10, dec);
    min *= mult;
    max *= mult;

    random = min + rand() % (max - min + 1);
    random /= (float)mult;
    return random;
}

void stampaMatrice(int c, int r, float mx[][c]){
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%.2f\t", mx[i][j]);
        }
        putchar('\n');
    }
}

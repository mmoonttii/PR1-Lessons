/* Scrivere un programma che calcoli la media di una matrice NxM; inizializzata casualmente
 * int inputVal() acquisisce un valore da tastiera assicurandosi che sia positivo
 * int randRange(int min, int max) estrazione casuale all'interno di un range
 * void initMatrix(...) inizializza la matrice usando randRange
 * float avgMatrix(...) calcola e restituisce la media della matrice
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 50
#define ROWS 15
#define COLS 15

int inputVal();
int randRange(int min, int max);
void initMatrix(int r, int c, int matrix[][c]);
float avgMatrix(int r, int c, int matrix[][c]);

int es2(){
    srand(time(NULL));

    int mtx[ROWS][COLS],
        r,
        c;

    r = randRange(MIN, MAX);
    c = randRange(MIN, MAX);
    initMatrix(r, c, mtx);

}

int inputVal(){
    int user;

    do {
        printf("\nInserisici n > 0");
        scanf("%d", &user);
    } while (user < 0);

    return user;

}

int randRange(int min, int max){
    int random;

    random = min + rand()%(max - min + 1);

    return random;
}

void initMatrix(int r, int c, int matrix[][c]){


}
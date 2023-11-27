/* Scrivere un programma che calcoli la media di una matrice NxM; inizializzata casualmente
 * int inputVal() acquisisce un valore da tastiera assicurandosi che sia positivo
 * int randRange(int min, int max) estrazione casuale all'interno di un range
 * void initMatrix(...) inizializza la matrice usando randRange
 * float avgMatrix(...) calcola e restituisce la media della matrice
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define MIN 0
//#define MAX 50
#define ROWS 15
#define COLS 15

int inputVal1();
int randRange1(int min, int max);
void initMatrix1(int r, int c, int matrix[][c]);
float avgMatrix1(int r, int c, int matrix[][c]);

int es2(){
    srand(time(NULL));

    int mtx[ROWS][COLS];
	float avg;



    initMatrix1(ROWS, COLS, mtx);
	avg = avgMatrix1(ROWS, COLS, mtx);

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			printf("%d\t", mtx[i][j]);
		}
		putchar('\n');
	}

	printf("\n%.3f", avg);
}

int inputVal1(){
    int user;

    do {
        printf("\nInserisici n > 0");
        scanf("%d", &user);
    } while (user < 0);

    return user;

}

int randRange1(int min, int max){
    int random;

    random = min + rand()%(max - min + 1);

    return random;
}

void initMatrix1(int r, int c, int matrix[][c]){
	int min = inputVal1();
	int max = inputVal1();

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] = randRange1(min, max);
		}
	}

}

float avgMatrix1(int r, int c, int matrix[][c]){
	int sum = 0;
	float avg;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			sum += matrix[i][j];
		}
	}

	avg = (float)sum/(r*c);
	return avg;
}
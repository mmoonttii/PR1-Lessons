/* Scrivere due procedure che andranno richiamate nel main:
 * • stampaArray che prenda come parametro un array di interi e ne stampi il suo contenuto.
 * • generaArray che prenda come parametro un array di interi e ne popoli il suo contenuto mediante
 * RandRange dell’esercizio 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10
#define MIN 1
#define MAX 100

void stampaArray(int array[]);
void generaArray(int array[], int min, int max);
int randRange(int min, int max);

int es7(){
	srand(time(NULL));
	int arr[DIM];

	generaArray(arr, MIN, MAX);
	stampaArray(arr);
    return 0;
}

int randRange(int min, int max){ // floatRandRange restituisce un numero random compreso tra min e max
	int aux;
	int random;

	// Se min e max sono scambiati mi assicuro che la gen avvenga tranquillamente
	if (min > max){
		aux = min;
		min = max;
		max = aux;
	}

	random = min + rand() % (max - min + 1);

	return random;
}

void stampaArray(int array[]){
	for (int i = 0; i < DIM; ++i) {
		printf("%d\t", array[i]);
	}
}

void generaArray(int array[], int min, int max){
	for (int i = 0; i < DIM; ++i) {
		array[i] = randRange(min, max);
	}
}
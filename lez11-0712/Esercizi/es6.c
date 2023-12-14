/**	Scrivere un programma che, con l'ausilio di una procedura, trovi il massimo e minimo di un array di N
	elementi. In particolare, l'array, il massimo e il minimo sono dichiarati nel main e l'array deve essere
	inizializzato casualmente mediante una procedura. Stampare vettore, massimo e minimo nel main.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MIN 1
#define MAX 20
#define DIM 20

void initArray(int dim, int arr[]);
void minMax(int *min, int *max, int dim, int arr[]);

int main(){
	srand(time(NULL));
	int arr[DIM];
	int max = INT_MIN, min = INT_MAX;

	initArray(DIM, arr);
	minMax(&min, &max, DIM, arr);

	for (int i = 0; i < DIM; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\nMin: %d"
		   "\nMax: %d", min, max);
    return 0;
}

void initArray(int dim, int arr[]){

	for (int i = 0; i < dim; ++i, arr++) {
		*arr = MIN + rand()%(MAX - MIN + 1);
	}
}

void minMax(int *min, int *max, int dim, int arr[]){

	for (int i = 0; i < dim; ++i, arr++) {
		if (*arr < *min) {
			*min = *arr;
		}
		if (*arr > *max) {
			*max = *arr;
		}
	}
}

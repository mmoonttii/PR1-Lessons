/*  Scrivere un programma in cui è dichiarato un vettore v, di dimensione N. Il vettore deve essere popolato con numeri
 *  interi, positivi e negativi, generati casualmente.
 *  Scrivere poi una funzione che riceve come parametro il vettore e inverte l' ordine degli elementi. Visualizzare dal
 *  main sia il vettore originale che quello ottenuto dopo la chiamata della funzione.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MIN -20
#define MAX 30

void popolaArr(int dim, int arr[], int min, int max);

void invertiArr(int dim, int arr[], int inverted[]);

int main(){

	srand(time(NULL));

	int v[N];
	int i[N];

	popolaArr(N , v, MIN, MAX);
	invertiArr(N, v, i);

	printf("Vect\tInv\n");

	for (int j = 0; j < N; ++j) {
		printf("%d\t%d\n", v[j], i[j]);
	}

    return 0;
}

void popolaArr(int dim, int *arr, int min, int max) {
	for (int i = 0; i < dim; ++i) {
		arr[i] = min + rand() % (max - min + 1);
	}
}

void invertiArr(int dim, int *arr, int *inverted) {

	for (int i = 0; i < dim; ++i) {
		inverted[dim - i - 1] = arr[i];
	}

}


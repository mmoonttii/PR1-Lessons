/*  Scrivere un programma in cui è dichiarato un vettore v allocato dinamicamente, di dimensione scelta in input
 *  dall'utente. Il vettore deve essere popolato con numeri interi, positivi e negativi, generati casualmente.
 *  Scrivere poi una funzione che riceve come parametro il vettore e inverte l' ordine degli elementi. Visualizzare dal
 *  main sia il vettore originale che quello ottenuto dopo la chiamata della funzione.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 5
#define MIN -20
#define MAX 30

int acquisisciDim();
void popolaArr(int dim, int arr[], int min, int max);
void invertiArr(int dim, int arr[], int inverted[]);
bool palindromo(int dim, int *arr);
int *allocaArr(int dim);

int main(){

	srand(time(NULL));

	int dim = acquisisciDim();

	int *v = NULL,
		*i = NULL;

	v = allocaArr(dim);
	i = allocaArr(dim);

	popolaArr(N , v, MIN, MAX);
	invertiArr(N, v, i);

	printf("Vect\tInv\n");

	for (int j = 0; j < N; ++j) {
		printf("%d\t%d\n", v[j], i[j]);
	}

	for (int j = 0; j < N; ++j) {
		printf("\n==Palindromo check==\n"
		       "Inserisici a[%d]", j);
		scanf("%d", &v[j]);
	}

	bool pal = palindromo(N, v);
	printf("\nPalindromo: %d", pal);

	if (v != NULL || i != NULL) {
		free(v), free(i);
		v = NULL, i = NULL;
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

bool palindromo(int dim, int *arr) {
	bool check = true;

	int i = 0;

	do {
		check = arr[dim - i - 1] == arr[i];
		i++;
	} while (check && i < dim);

	return check;
}

int acquisisciDim() {
	int in;

	printf("\nQuanto grande deve essere il vettore? ");
	scanf("%d", &in);

	return in;
}

int *allocaArr(int dim) {
	int *arr = NULL;

	arr = (int *)calloc(dim, sizeof(int));
	if (arr == NULL) exit(-1);

	return arr;
}

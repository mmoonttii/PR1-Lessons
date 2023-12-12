/*  Scrivere una funzione di ricerca di un elemento di un array. Se l'elemento passato come parametro si
	trova nell'array la funzione ne restituisce l'indice di posizione, altrimenti restituisce -1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20
#define MIN 1
#define MAX 25

int randRange(int min, int max);
void arrInit(int dim, int arr[]);
int ricerca(int ricercato, int dim, int array[]);
void printArr(int dim, int arr[]);

int main(){
	srand(time(NULL));
	int array[DIM];
	int lookFor,
		index;

	arrInit(DIM, array);

	printf("Numero da cercare: ");
	scanf("%d", &lookFor);

	index = ricerca(lookFor, DIM, array);

	printf("%d è alla pos. %d\n{", lookFor, index);

	printArr(DIM, array);
    return 0;
}

int ricerca(int ricercato, int dim, int array[]){

	int index = -1;

	for (int i = 0; i < dim; ++i) {
		if (array[i] == ricercato) {
			index = i;
		}
	}

	return index;
}

int randRange(int min, int max) {
	int res;
	res = min + rand() % (max - min + 1);
	return res;
}

void arrInit(int dim, int arr[]){
	for (int i = 0; i < dim; ++i) {
		arr[i] = randRange(MIN, MAX);
	}
}

void printArr(int dim, int arr[]) {
	printf("\n{");
	for (int i = 0; i < dim; ++i, arr++) {
		printf("%d\t", *arr);
	}
	printf("}");
}

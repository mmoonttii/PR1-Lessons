#include <stdio.h>
#include <stdlib.h>

int *createArr(int n, int initialValue);


int main() {
	int *arrDinamico = NULL;
	int dim;

	printf("Inserisci dimensione array: ");
	scanf("%d", &dim);

	arrDinamico = createArr(dim, 5);

	for (int i = 0; i < dim; ++i) {
		printf("\n%d",arrDinamico[i]);
	}

	if (arrDinamico != NULL) {
		free(arrDinamico);
		arrDinamico = NULL; // In particolare se faccio free non alla fine del programma
	}
	return 0;
}

int *createArr(int n, int initialValue) {

	int *array = NULL;

	array = calloc(n, sizeof(int));

	if (array == NULL)
		exit(-1);

	for (int i = 0; i < n; ++i) {
		array[i] = initialValue;
	}
	return array;
}

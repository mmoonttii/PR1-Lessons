#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int es1(){

	int pippo = 10,
		paperino = 30;

	int *ptrPippo = NULL,
		*ptrPaperino = NULL;

	ptrPippo = &pippo;
	ptrPaperino = &paperino;

	printf("Valori prima:"
		   "\n\tPippo: %d"
		   "\n\tPaperino: %d", pippo, paperino);

	swap(ptrPippo, ptrPaperino);

	printf("\n\nValori dopo:"
		   "\n\tPippo: %d"
		   "\n\tPaperino: %d", pippo, paperino);

    return 0;
}

void swap(int *a, int *b) {

	// ALternative per gestire la correttezza dei puntatori
/*	if (a == NULL || b == NULL) {
 *		exit(1);
 *	}
 */

	int aux;

	if (a == NULL || b == NULL) {
		return;
	}

	aux = *a;
	*a = *b;
	*b = aux;
}


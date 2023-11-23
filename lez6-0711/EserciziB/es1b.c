/* Scrivere un programma che stampi i primi n quadrati (elevamento del numero stesso alla
 * potenza di 2). Chiedere in input il valore di n.
 * Es.: inserendo 10, il programma deve stampare 1, 4, 9, 16, 25, 36, 49, 64, 81, 100.
 */

#include <stdio.h>

int es1b(){
	int n = 0, square;
	printf("Inserisci n: ");
	scanf("%d", &n);

	printf("\n");
	for (int i = 1; i <= n; ++i) {
		square = i*i;
		printf("\t%d", square);
	}
	return 0;
}

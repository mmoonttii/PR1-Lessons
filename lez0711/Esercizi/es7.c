/* Scrivere un programma che inizializzi un vettore, di dimensione N a piacere,
 * casualmente. Il programma deve chiedere un valore all'utente e deve stampare in
 * output quante volte quel valore è contenuto nel vettore.
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define LEN 10
#define MAX 10
#define MIN 1

int es7() {

	int array[LEN], userIn, counter = 0;

	srand(time(NULL));

	// Generazione casuale array
	for (int i = 0; i < LEN; i++) {
		array[i] = MIN + rand() % (MAX + MIN - 1);
	}

	// Acquisizione input
	printf("Inserire numero: ");
	scanf("%d", &userIn);

	for (int i = 0; i < LEN; i++) {
		if (array[i] == userIn) {
			counter++;
		}
	}

	printf("%d è nell'array %d volte", userIn, counter);


	for (int i = 0; i < LEN; i++) {
		printf("\n[%d]: %d\n", i, array[i]);
	}

	return 0;
}


/* Scrivere un programma che inizializzi un vettore, di dimensione N a piacere,
 * casualmente. Il programma deve chiedere un valore all'utente e deve stampare in
 * output se quel valore è contenuto nel vettore oppure no.
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define LEN 5
#define MAX 50
#define MIN 1

int es6(){

	int array[LEN], userIn;
	bool check = false;

	srand(time(NULL));

	// Generazione casuale array
	for (int i = 0; i < LEN; i++){
		array[i] = MIN + rand() % (MAX + MIN - 1);
	}

	// Acquisizione input
	printf("Inserire numero: ");
	scanf("%d", &userIn);

	for (int i = 0; i < LEN; i++) {
		if (array[i] == userIn){
			check = true;
		}
	}

	if (check){
		printf("%d appartiene all'array", userIn);
	} else {
		printf("%d non appartiene all'array", userIn);
	}

	for (int i = 0; i < LEN; i++){
		printf("\n[%d]: %d\n", i, array[i]);
	}

	return 0;
}
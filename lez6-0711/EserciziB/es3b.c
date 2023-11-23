/* Generare un numero casuale compreso tra 0 e 100 e chiedere all'utente un numero nello stesso
 * intervallo. Se sono uguali stampare un messaggio «Numeri uguali»; in caso contrario comunicare
 * se il numero inserito è maggiore o minore di quello generato. Il programma deve terminare quando
 * l'utente indovina il numero generato (for, while o do while?).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100

int randRange(int min, int max);

int es3b(){

	int userIn,
	    randIn,
	    lose = 0;

	srand(time(NULL));

	printf("Inserisci");
	scanf("%d", &userIn);

	randIn = randRange(MIN, MAX);

	while (randIn != userIn){
		if (userIn > randIn){
			printf("\nToo much");
		} else {
			printf("\nNotte naf");
		}
		printf("\nInserisci gnu: ");
		scanf("%d", &userIn);

		lose++;
	}

	printf("BRV %d == %d", userIn, randIn);
	printf("\nn tents %d", ++lose);

    return 0;
}

int randRange(int min, int max){
	int num;
	num = min + rand() % (max- min + 1);
	return num;
}
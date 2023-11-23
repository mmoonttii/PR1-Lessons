/* La funz randRange riceve due interi min e max, acquisiti nel main, e restituisca un rand nel range min:max.
 * Invocare la funzione e stampare il restituito
 * Se quel disgraziato dell'utente scambia min e max gestire l'eccezione
 * Modificare floatRandRange in modo tale che generi float prendendo come terzo parametro il numero di cifre decimali
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float floatRandRange(int min, int max, int dec);
int randRange(int min, int max);

int es1(){
	// Init variabili e random seed
	srand(time(NULL));
	int
		min, max, dec;

	float
	    random;

	// Acquisizione max min
	printf("Inserisci estremo: ");
	scanf("%d", &min);
	printf("\nInserisci altro estremo: ");
	scanf("%d", &max);
	printf("\nInserisci decimali: ");
	scanf("%d", &dec);

	// rand gen
	random = floatRandRange(min, max, dec);

	// print
	printf("\nRandom: %f", random);

    return 0;
}

int oorandRange(int min, int max){ // randRange restituisce un numero random compreso tra min e max
	int aux;
	int random;

	// Se min e max sono scambiati mi assicuro che la gen avvenga tranquillamente
	if (min > max){
		aux = min;
		min = max;
		max = aux;
	}

	random = min + rand() % (max - min + 1);

	return random;
}
float aafloatRandRange(int min, int max, int dec){ // floatRandRange restituisce un numero random compreso tra min e max
	int aux;
	float random;
	int mult;

	// Se min e max sono scambiati mi assicuro che la gen avvenga tranquillamente
	if (min > max){
		aux = min;
		min = max;
		max = aux;
	}
	// mi assicuro che il num di cifre decimali sia non negativo
	dec = abs(dec);
	mult = pow(10, dec);
	min *= mult;
	max *= mult;

	random = min + rand() % (max - min + 1);
	random /= (float)mult;
	return random;
}

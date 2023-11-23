/* Una subroutine chiede 3 valori all'utente che stampi in output il maggiore dei tre
 * Una subroutine chidcd 3 valori all'utente e lo restituisce
 * */

#include <stdio.h>

void printMax (int a, int b, int c); // Calcola il maggiore dei tre numeri e lo stampa
int calcMax (int a, int b, int c); // Calcola il maggiore dei tre numeri e lo restituisce
int calcMaxBis (int a, int b); // Calcola il maggiore dei due numeri e lo restituisce

int main() {

	// Dichiarazione e acquisizione variabili input
	int a,
	    b,
	    c,
	    max;

	printf("Inserisci val a: ");
	scanf("%d", &a);
	printf("\nInserisci val b: ");
	scanf("%d", &b);
	printf("\nInserisci val c: ");
	scanf("%d", &c);

	printMax(a, b, c);

	printf("\ncalcMax: %d", calcMax(a, b, c));

	max = calcMaxBis(a, calcMaxBis(b, c));

	printf("\ncalcMaxBis: %d", max);

	return 0;
}

void printMax(int a, int b, int c){

	int max;

	if (a > b) {
		if (a > c){
			max = a;
		} else {
			max = c;
		}
	} else if (b > c) {
		max = b;
	} else {
		max = c;
	}

	printf("\nprintMax: %d", max);
}

int calcMax(int a, int b, int c){

	int max;

	if (a > b) {
		if (a > c){
			max = a;
		} else {
			max = c;
		}
	} else if (b > c) {
		max = b;
	} else {
		max = c;
	}

	return max;
}

int calcMaxBis (int a, int b){

	int max = 0;

	if (a > b){
		max = a;
	} else {
		max = b;
	}

	return max;
}
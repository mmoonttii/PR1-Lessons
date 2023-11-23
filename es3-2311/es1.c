/* Una subroutine chiede 3 valori all'utente che stampi in output il maggiore dei tre
 * Una subroutine chidcd 3 valori all'utente e lo restituisce
 * Una subroutine chiede 2 valori all'utente e lo restituisce
 * Implementare la subroutine ai punti 1 e 2 in modo che ricevano un array come parametro
 * Definire una subroutine che restituisca un array con i tre valori più alti di un altro array
 * */

#include <stdio.h>
#include <limits.h>

#define DIM 25
#define DIM_MAX 3

void printMax(int a, int b, int c); // Calcola il maggiore dei tre numeri e lo stampa
int calcMax(int a, int b, int c); // Calcola il maggiore dei tre numeri e lo restituisce
int calcMaxBis(int a, int b); // Calcola il maggiore dei due numeri e lo restituisce
int arrMax(int dim, int arr[dim]); // Calcola il maggiore di un array di interi e lo restituisce
void arrTripleMax(int dim, int arr[dim], int arrMax[DIM_MAX]); // Restituisco un array composto dai tre valori più alti di un altro array

int main() {

	// Dichiarazione e acquisizione variabili input
	int a,
	    b,
	    c,
	    max,
		arr[DIM],
		arrRis[DIM_MAX];


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

	for (int i = 0; i < DIM; ++i) {
		printf("\npos %d", i);
		scanf("%d", &arr[i]);
	}

	max = arrMax(DIM, arr);
	printf("\narrMax: %d", max);

	arrTripleMax(DIM, arr, arrRis);

	putchar('\n');

	for (int i = 0; i < DIM_MAX; ++i) {
		printf("%d\t",arrRis[i]);
	}

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

int calcMaxBis(int a, int b){

	int max = 0;

	if (a > b){
		max = a;
	} else {
		max = b;
	}

	return max;
}

int arrMax(int dim, int arr[dim]){

	int max = INT_MIN;

	for (int i = 0; i < dim; ++i) {
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

void arrTripleMax(int dim, int arr[dim], int arrMax[DIM_MAX]){

	for (int i = 0; i < DIM_MAX; ++i) {
		arrMax[i] = INT_MIN;
	}

	for (int i = 0; i < DIM; ++i) {
		if (arr[i] > arrMax[0]) {
			arrMax[0] = arr[i];
		} else if (arr[i] > arrMax[1]) {
			arrMax[1] = arr[i];
		} else if (arr[i] > arrMax[2]) {
			arrMax[2] = arr[i];
		}
	}

}
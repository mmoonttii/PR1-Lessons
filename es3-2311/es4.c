/* Scrivere un programma che per 3 volte chieda all’utente un valore intero, ne conti il numero di cifre e
 * visualizzi il risultato.
 * Dopo ogni inserimento deve essere visualizzato il risultato.
 * Per il calcolo del numero di cifre scrivere una funzione con prototipo:
 * int contacifre(int n);
 */

#include <stdio.h>

int contacifre(int n);

int es4(){
	int digits, num;

	for (int i = 0; i < 3; ++i) {
		printf("Input: ");
		scanf("%d", &num);
		digits = contacifre(num);
		printf("\n%d\n", digits);
	}

    return 0;
}

int contacifre(int n){
	int cifre = 0;
	do {
		++cifre;
		n /= 10;

	} while (n > 0);
	return cifre;
}
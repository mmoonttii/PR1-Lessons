/* Scrivere un programma che chieda all'utente un numero n e stampi tutti i quadrati dispari
 * compresi tra 1 e n, al contrario.
 * Es.: inserendo 10, il programma deve stampare la successione 81, 49, 25, 9, 1.
 */

#include <stdio.h>

int es2b(){
	int n = 0, square;
	printf("Inserisci n: ");
	scanf("%d", &n);

	printf("\n");
	for (int i = n; i > 0; --i) {
		if (i % 2 == 1){
			square = i*i;
			printf("%d\t", square);
		}
	}
    return 0;
}
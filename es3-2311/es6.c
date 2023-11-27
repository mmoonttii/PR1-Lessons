/* Il programma legge una frase introdotta da tastiera, mediante subroutine (al più 30 caratteri)
 * Con una nuova subroutine, costruiree una nuova frase, in una nuova variabile, dove il primo carattere di ogni parola
 * è reso maiuscolo, tutti gli altri resi minuscoli
 */

#include <stdio.h>
#define LEN 30
void acquireStr(int dim, char input[dim]);
void editStr(int dim, char input[dim]);

int es6(){
	char input[LEN + 1];

	acquireStr(LEN + 1, input);

	editStr(LEN + 1, input);

	printf("%s", input);
    return 0;
}

void acquireStr(int dim, char input[dim]) {
	printf("Inserisci stringa: ");
	scanf("%30[^\n]s", input);
}

void editStr(int dim, char input[dim]) {

	if (input[0] >= 'a' && input[0] <= 'z') {
		input[0] -= 32;
	}

	for (int i = 1; i < dim; ++i) {
		if (input[i - 1] == ' ') {
			if (input[i] >= 'a' && input[i] <= 'z') {
				input[i] -= 32;
			}
		} else {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				input[i] += 32;
			}
		}
	}
}

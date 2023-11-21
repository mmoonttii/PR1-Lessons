/* Scrivere una funzione che prenda come parametro un carattere e:
 * • se è una lettera minuscola, restituisce una lettera maiuscola;
 * • se è una lettera maiuscola, restituisce una lettera minuscola;
 * • lascia invariati tutti gli altri caratteri.
 * • Modificare successivamente una stringa dichiarata nel main modificando ogni carattere utilizzando la
 * funzione appena descritta.
 */

#include <stdio.h>
#define DIM 30

char editChar(char input);
int es6(){
	char input[DIM + 1],
	     output[DIM + 1];

	printf("Inserisci stringa: ");
	scanf("%[^\n]30s", input);

	for (int i = 0; i < DIM; ++i) {
		output[i] = editChar(input[i]);
	}

	printf("\n Output: %s", output);
	return 0;
}

char editChar(char input){
	if (input >= 65 && input <= 90){
		input += 32;
	} else if (input >= 97 && input <= 122){
		input -= 32;
	}
	return input;
}
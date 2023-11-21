/* Scrivere una funzione che faccia il clamp tra 50 e 100 di un numero passato come parametro.
 * ES: x: 7 -> f: 50; x: 75 -> f: 75; x: 135 -> f: 100
 */

#include <stdio.h>
#define MIN 50
#define MAX 100

int clamp(int min, int max, int input);

int es5(){
	int input, output;

	printf("Inserire numero da clampare: ");
	scanf("%d", &input);

	output = clamp(MIN, MAX, input);

	printf("\nIl numero clampato è %d", output);
    return 0;
}

int clamp(int min, int max, int input){
	int output;

	if (input < min){
		output = min;
	} else if (input > max){
		output = max;
	} else {
		output = input;
	}

	return output;
}
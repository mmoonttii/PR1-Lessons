/*  Scrivere una funzione che, ricevuto come parametro un numero di gradi Celsius, lo trasformi in
	Fahrenheit secondo la formula F=(C*1.8) + 32. Utilizzare solamente variabili allocate dinamicamente
 */

#include <stdio.h>
#include <stdlib.h>

float *cToF(float *c);

int main(){
	float *f = NULL,
		  *c = NULL;

	c = (float *)calloc(1, sizeof(float));

	printf("Inserisci gradi Celsius: ");
	scanf("%f", c);

	f = cToF(c);

	printf("Sono %.2f F", *f);

	free(f), free(c);
	f = NULL, c = NULL;
    return 0;
}

float *cToF(float *c){
	float *f = NULL;

	f = (float *) calloc(1, sizeof(float));
	if (f == NULL) exit(-1);

	*f = (*c * 1.8f) + 32;

	return f;

}
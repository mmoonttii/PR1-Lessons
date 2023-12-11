/** Scrivere un programma in cui viene definita una struttura NumeroComplesso, atta a contenere due variabili reali:
	• parte reale;
	• parte immaginaria.
	• Il programma deve dichiarare una variabile di tipo NumeroComplesso, acquisire in input dall'utente le due parti
	del numero, effettuare il calcolo del modulo del numero e stampare le due parti del numero e il modulo
	calcolato.
	NB: dato un numero complesso z, la sua parte reale x e immaginaria y, il modulo si calcola come: z = sqrt(x2 + y2)
*/

#include <stdio.h>
#include <math.h>

typedef struct {
	float reale;
	float immaginaria;
} NumeroComplesso;

float calcolaModulo(NumeroComplesso complesso);

int main(){
	NumeroComplesso num;
	float modulo;

	printf("Numero Complesso\n"
		   "Parte reale: ");
	scanf("%f", &num.reale);
	printf("Parte immaginaria: ");
	scanf("%f", &num.immaginaria);

	modulo = calcolaModulo(num);

	printf("Numero Complesso\n"
		   "%.3f + %.3f i\n"
		   "Modulo: %.3f", num.reale, num.immaginaria, modulo);

    return 0;
}

float calcolaModulo(NumeroComplesso complesso){
	float modulo;

	modulo = sqrtf(powf(complesso.reale, 2) + powf(complesso.immaginaria, 2));

	return modulo;
}
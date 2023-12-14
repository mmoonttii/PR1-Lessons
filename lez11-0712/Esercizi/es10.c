/*  Definire una struttura ‘Casa’ composta dai campi 'numeroPiani', 'mq', 'prezzo' che permetta di
	acquisire i relativi dati attraverso una procedura passando come parametro l’indirizzo di memoria della
    stessa. Scrivere poi una seconda procedura che ne permetta la stampa
 */

#include <stdio.h>

typedef struct {
	int numeroPiani;
	int mq;
	float prezzo;
} Casa;

void acquisisciCasa(Casa *casa);
void stampaCasa(Casa *casa);

int main(){
	Casa casa;

	acquisisciCasa(&casa);
	stampaCasa(&casa);

    return 0;
}

void acquisisciCasa(Casa *casa) {
	printf("==Casa==\n"
		   "Numero Piani: ");
	scanf("%d", &casa->numeroPiani);

	printf("Metri quadri: ");
	scanf("%d", &casa->mq);

	printf("Prezzo: ");
	scanf("%f", &casa->prezzo);
}

void stampaCasa(Casa *casa) {
	printf("\n==Casa=="
		   "\nNumero piani: %d"
		   "\nMetri quadri: %d"
		   "\nPrezzo casa: %.2f",
		   casa->numeroPiani, casa->mq, casa->prezzo);
}
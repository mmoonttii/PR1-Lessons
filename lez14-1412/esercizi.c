/*  Scrivere una funz che inserisca un nodo in testa alla lista e
	utilizzarla per inserire una lista di numeri interi positivi inseriti dall'utente
	L'acquisizione termoina quando il valore inserito è negativo
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int info;
	struct nodo *next;
};

typedef struct nodo Nodo;

Nodo *aggiungiNodoInTesta(Nodo *lista);
Nodo *eliminaLista(Nodo *lista);
Nodo *cercaInLista(Nodo *lista, int num);

int main(){

	Nodo *lista = NULL;
	Nodo *found = NULL;

	int in;

	do {
		printf("\nInserisci numero: ");
		scanf("%d",&in);

		if (in > 0) {
			lista = aggiungiNodoInTesta(lista); // Oppure aggiungiamo un parametro e lo usiamo per inizializzare il campo
			lista->info = in;
		}
	} while (in > 0);

	printf("==RICERCA==\n"
		   "Quale numero vuoi cercare?");
	scanf("%d",&in);

	found = cercaInLista(lista, in);

	if (found == NULL) {
		printf("il numero %d non è stato trovato", in);
	} else {
		printf("Il numero %d è stato trovato", found->info);
	}

	eliminaLista(lista);
	// non c'è bisogno di free(found), perchè tanto sarà liberato dall'elimina lista prima o poi

    return 0;
}

// === ESERCIZIO 1 ===
Nodo *aggiungiNodoInTesta(Nodo *lista) {

	Nodo *newHead = NULL;

	newHead  = (Nodo *) malloc(sizeof(Nodo));
	if (newHead == NULL) exit(-1);

	newHead->info = 0;
	newHead->next = lista;

	return newHead;
}

// === ESERCIZIO 4 ===

Nodo *cercaInLista(Nodo *lista, int num) {
	Nodo *looking = NULL,
	     *testa = lista;

	while (testa != NULL && looking == NULL){ // Ricorda il controllo looking == NULL
		if (num == testa->info) {
			looking = testa;

		} else {
			testa = testa->next;
		}
	}

	return looking;
}

Nodo *eliminaLista(Nodo *lista) {
	Nodo *next = NULL;

	while (lista != NULL) {
		next = lista->next;
		free(lista);
		lista = next;
	}

	return lista;
}


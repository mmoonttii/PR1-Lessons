#include <stdio.h>
#include <stdlib.h>

#define DIM 5

struct nodo {
	int info;
	struct nodo *next;
};

typedef struct nodo Nodo;
// ATTENZIONE si gira a caso e non possiamo fare il typedef e la struct in una volta sola

Nodo *aggiungiNodo(Nodo *lista);
Nodo *eliminaNodo(Nodo *lista);
Nodo *eliminaLista(Nodo *lista);

int main(){

	Nodo *lista = NULL;

	for (int i = 0; i < DIM; ++i) {
		lista = aggiungiNodo(lista);
	}

	lista = eliminaLista(lista);

	free(lista);
	lista = NULL;

    return 0;
}

Nodo *aggiungiNodo(Nodo *lista){

	Nodo *testa = lista;

	// Se la lista vuota
	if (lista == NULL) {
		lista = (Nodo*)malloc(sizeof(Nodo));
		if (lista == NULL) {
			exit(-1);
		}
		// Valori di default
		lista->info = 0;
		lista->next = NULL;
		testa = lista;

	} else { // Caso lista con elementi
		// Scorro fino all'ultimo elemento
		while (lista->next != NULL) {
			// Ciclo la lista fino a quando non trovaimo l'ultimo elemento della lista che avrà lista->next == NULL
			lista = lista->next;
		}
		// Aggiungo nodo in coda
		lista->next = (Nodo *)malloc(sizeof(Nodo));
		if (lista->next == NULL) {
			exit(-1);
		}
		lista->next->next = NULL;
	}

	// return del primo elemento della lista
	return testa;
}

Nodo *eliminaNodo(Nodo *lista) {

	Nodo *testa = lista;

	if (lista != NULL && lista->next != NULL) { // Accediamo al penultimo elemento
		while (lista->next->next != NULL){
			lista = lista->next;
		}

		free(lista->next);
		lista->next = NULL;
	} else if (lista != NULL){ // Quando ne abbiamo solo uno

		free(lista);
		lista = NULL;
		testa = NULL;

	}

	return testa;
}

Nodo *eliminaLista(Nodo *lista) {
	Nodo *next = NULL;

	while (lista != NULL) {
		printf("A\n");
		next = lista->next;
		free(lista);
		lista = next;
	}

	printf("%p", lista);
	return lista;
}

// LISTE LINEARI CIRCOLARI come quando a carte dopo lultimo giocatore rigioca il primo

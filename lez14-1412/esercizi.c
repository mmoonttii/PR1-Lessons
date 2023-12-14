#include "esercizi.h"

// === ESERCIZIO 1 ===
/*  Scrivere una funzione che inserisca un nodo in testa alla lista. Utilizzare la funzione per popolare una lista
	di numeri interi positivi inseriti dall'utente. L'acquisizione termina quando il valore inserito è negativo.
 */
Nodo *aggiungiNodoInTesta(Nodo *lista) {

	Nodo *newHead = NULL;

	newHead  = (Nodo *) malloc(sizeof(Nodo));
	if (newHead == NULL) exit(-1);

	newHead->info = 0;
	newHead->next = lista;

	return newHead;
}

// === ESERCIZIO 2 ===
/*  Scrivere una funzione che permetta di stampare gli elementi di una lista
 */
void stampaLista(Nodo *lista) {
	Nodo *head = lista;
	int i = 0;
	printf("=== CONTENUTO LISTA ===",);
	while (head != NULL){
		printf("[%d]: %d",i, head->info);
		head = head->next;

		i++;
	}
}


void stampaListaRicorsiva(Nodo *lista) {
	if (lista != NULL) {
		printf("%d\t",lista->info);
		stampaListaRicorsiva(lista->next);
	}
}

// === ESERCIZIO 4 ===
/*  Scrivere una funzione che effettui la ricerca di un elemento all'interno di una lista.
 */
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

// === ESERCIZIO 6 ===
/*  Scrivere una funzione che permetta l'inserimento di un nodo all'interno di una lista. Il nodo deve essere
	inserito nella posizione successiva ad un nodo già presente nella lista e passato come parametro
 */
Nodo *aggiungiInMezzo(Nodo *nodo) {

	Nodo *aux = NULL,
		 *new = NULL;

	aux = nodo->next;

	new = (Nodo *)malloc(sizeof(Nodo));
	if (new == NULL) exit(-1);

	nodo->next = new;

	new->info = 0;
	new->next = aux;

	return new;
}

// === ELIMINA LISTA ===
/*  La memoria occupata dagli elementi della lista (compresi i puntatori che puntano a elementi della lista) viene
 * deallocata
 */
Nodo *eliminaLista(Nodo *lista) {
	Nodo *next = NULL;

	while (lista != NULL) {
		next = lista->next;
		free(lista);
		lista = next;
	}

	return lista;
}




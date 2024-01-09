#include <stdio.h>
#include <stdlib.h>

#define LEN_STR 31

typedef struct smartphone{
	char nome[LEN_STR + 1];
	char cpu[LEN_STR + 1];
	int mp;
	struct smartphone *next;
} Smartphone;

Smartphone *aggiungiInCoda(Smartphone *lista, Smartphone new);
Smartphone *deallocaLista(Smartphone *lista);
void stampaLista(Smartphone *lista);
Smartphone *rimuoviElementoN(Smartphone *lista, int n);

int main() {
	Smartphone sp;
	int read = 0;
	Smartphone *lista = NULL;

	// Apertura file
	FILE *f = NULL;
	f = fopen("../smartphone.txt", "r");
	if (f == NULL) exit(EXIT_FAILURE);

	do {
		read = 0;
		// Lettura file
		read += fscanf(f, " %[^\n]31s", sp.nome);
		read += fscanf(f, " %[^\n]31s", sp.cpu);
		read += fscanf(f, " %d", &sp.mp);
		sp.next = NULL;


		if (read == 3) {
			printf("\nNome: %s"
			       "\nCpu: %s"
			       "\nMp: %d\n",
			       sp.nome, sp.cpu, sp.mp);

			lista = aggiungiInCoda(lista, sp);
		}
	} while (read == 3);

	printf("\n\nStampa della lista\n");
	stampaLista(lista);
	fclose(f);

	lista = deallocaLista(lista);

	return 0;
}

Smartphone *aggiungiInCoda(Smartphone *lista, Smartphone new) {

	Smartphone *last = lista;

	if (lista == NULL) { // se lista vuota
		// Creo un nuovo nodo
		lista = (Smartphone *)malloc(sizeof(Smartphone));
		if (lista == NULL) exit(-1);

		// Inizializzo il nuovo nodo
		*lista = new;
		lista->next = NULL;

	} else { // se lista già popolata

		while (last->next != NULL) // Arrivo fino all'ultimo elemento
			last = last->next;
		// Creo un nuovo nodo
		last->next = (Smartphone *)malloc(sizeof(Smartphone));
		if (lista == NULL) exit(-1);

		// Inizializzo il nuovo nodo
		*last->next = new;
		last->next->next = NULL;
	}

	return lista;

}

Smartphone *deallocaLista(Smartphone *lista) {

	Smartphone *next = NULL;

	while (lista != NULL){
		next = lista->next;
		free(lista);
		lista = next;
	}

	return NULL;
}

void stampaLista(Smartphone *lista){
	Smartphone *head = lista;

	while (head != NULL){
		printf("\nNome: %s"
			   "\nCpu: %s"
			   "\nMp: %d\n",
			   head->nome, head->cpu, head->mp);

		head = head->next;
	}
}

Smartphone *rimuoviElementoN(Smartphone *lista, int n){
	Smartphone *head = lista;
	Smartphone *deleted = NULL;
	Smartphone *aux = NULL;

	for (int i = 0; i < n - 1; ++i) {
		head = head->next;
	}
	deleted = head->next;
	aux = deleted->next;
	head->next = aux;
	free(deleted);
	return lista;
}

Smartphone *spostaInTesta(Smartphone *lista, int n){
	Smartphone *head = lista;
	Smartphone *moving = NULL;
	Smartphone *aux = NULL;

	for (int i = 0; i < n - 1; ++i) {
		head = head->next;
	}

	moving = head->next;
	aux = moving->next;
	head->next = aux;
	moving->next = lista;

	return moving;
}
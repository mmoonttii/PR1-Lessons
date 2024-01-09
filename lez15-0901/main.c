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
Smartphone *estraiDaLista(Smartphone *lista, int pos);
Smartphone *inserisciInTesta(Smartphone *lista, Smartphone *newTesta);

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

	while (lista != NULL){
		printf("\nNome: %s"
			   "\nCpu: %s"
			   "\nMp: %d\n",
			   lista->nome, lista->cpu, lista->mp);

		lista = lista->next;
	}
}

Smartphone *estraiDaLista(Smartphone *lista, int pos){
	Smartphone *prev = lista;
	Smartphone *extracted = NULL;

	for (int i = 0; i < pos - 1; ++i) {
		prev = prev->next;
	}
	extracted = prev->next;
	prev->next = extracted->next;
	extracted->next = NULL;
	return extracted;
}

Smartphone *inserisciInTesta(Smartphone *lista, Smartphone *newTesta){

	newTesta->next = lista;
	return newTesta;
}
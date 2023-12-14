#include "esercizi.h"

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

	stampaLista(lista);

	eliminaLista(lista);
	// non c'è bisogno di free(found), perchè tanto sarà liberato dall'elimina lista prima o poi

	return 0;
}
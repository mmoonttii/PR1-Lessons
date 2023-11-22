/* Aggiungere all’esercizio precedente un’interfaccia utente che permetta all’utente di
 * effettuare una giocata del tipo: estratto, ambo, terno, quaterna, cinquina. In caso di
 * vittoria dovrà essere comunicata all’utente la vincita, altrimenti dovrà essere concesso
 * un nuovo tentativo senza una nuova estrazione.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5
#define MAX 90
#define MIN 1

#define ESTRATTO E
#define AMBO A
#define TERNA T
#define QUATERNA Q
#define CINQUINA C


int es10(){

	int array[LEN];

	srand(time(NULL));

	for (int i = 0; i < LEN; i++){
		array[i] = MIN + rand() % (MAX + MIN - 1);

		for (int j = 0; j < i; j++){
			if (array[i] == array[j]){
				do {
					array[i] = MIN + rand() % (MAX + MIN - 1);
				} while	(array[i] == array[j]);
			}
		}
	}

	char user;

	for (int i = 0; i < LEN; ++i) {
		printf("\n%d", array[i]);
	}

	return 0;
}
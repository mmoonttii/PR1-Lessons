// fwrite(void *ptr, size_t size, size_t count, void *stram);

/*  ptr: indirizzo della variabile
 *  size, dimensione in byte del singolo elemento
 *  count: quanti elementi devono essere scritti sul file
 *  stream: è il puntatore al file
 *
 * Il file è scritto byte per byte utilizzando i dati della variabile
 *
 * L'equivalente è il fread()
 */
#include <stdio.h>
#include <stdlib.h>

#define N 2
#define LEN 31

typedef struct {
	char nome[LEN + 1];
	char cognome[LEN + 1];
	int matricola;
} Utente;

int main(){
	FILE *file = NULL;
	int read, i = 0;

	Utente arr[N] = {
			"Riccardo", "Scateni", 12345,
			"Andrea", "Loddo", 67890
	};

	Utente arrRead[N];

	file = fopen("utenti.dat", "wb");
	if (file == NULL) exit(-1);

	fwrite(arr, sizeof(Utente), N, file);

	fclose(file);

	file = fopen("utenti.dat", "rb");
	if (file == NULL) exit(-2);

	do {
		read = fread(arrRead, sizeof(Utente), N, file);

		if (read == N) {
			while (i < N) {
				printf("Utente %d\n"
				       "\tNome: %s\n"
				       "\tCognome: %s\n"
				       "\tMatricola: %d\n",
				       i, arrRead[i].nome, arrRead[i].cognome, arrRead[i].matricola);
				i++;
			}
		}
	} while (read == N);

	fclose(file);
    return 0;
}
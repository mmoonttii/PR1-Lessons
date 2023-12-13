#include <stdio.h>
#include <stdlib.h>

int main() {

	/*  I file sono gestiti dal sistema ioerativo
	 *
	 *  Sono organizzati in due categorie principali:
	 *   -   File di testo: Assimilabili a collezioni di stringhe
	 *   -   File binari:   Strutturati in blocchi di dati organizzati in una struttura precisa
	 */

	/*  APERTURA FILE
	 *  I file hanno bisogno di un puntatore di tipo FILE
	 *  FILE *fp = NULL;
	 *  fp = fopen("NomeFile", "mode"); Apertura dei file
	 *
	 *  Mode:
	 *   -  Lettura: r (rb per binari) --> richiede l'esistenza del file
	 *   -  Scrittura: w (wb per binari) --> il file viene creato o svuotato se già esistente
	 *   -  Accodamento: a (ab per binari) --> scrivo in coda ai dati già presenti
	 *   -  Ibride: r+ (lettura e scrittura), w+ (scrittura e lettura), a+ (accodamento, lettura e scrittura)
	 */

	FILE *file = NULL;
	int a[4] = {0, 1, 2, 3};

	file = fopen("prova", "w");
	if (file == NULL){
		exit(-1);
	}

	/*  SCRITTURA SU FILE
	 *  fprintf(fp, "blablba %d", int);
	 *
	 * */

	fprintf(file, "%d\t%d\t%d\t%d\n", a[0], a[1], a[2], a[3]);






	/*  CHIUSURA FILE
	 *  fclose(fp);
	 */

	fclose(file);
	return 0;
}

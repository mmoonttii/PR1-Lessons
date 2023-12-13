#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *file = NULL;
	int a[4],
		i = 0, read = 0;

	file = fopen("prova", "r");
	if (file == NULL)
		exit(-1);

	do {
		printf("\nLettura riga %d\n", i);

		/*  LETTURA FILE
		 *
		 *  int fscanf(fp, "blabla %d", int);
		 *
		 *  fscanf restituisce un intero che corrsiponde al numero di letture avvenute correttamente
		 *
		 */

		read = fscanf(file, "%d\t%d\t%d\t%d\n", &a[0],&a[1],&a[2],&a[3]);

		if (read != 4) {
			printf("Errore di lettura o nessun dato in riga %d", i);
		} else {
			printf("%d\n%d\n%d\n%d", a[0],a[1],a[2],a[3]);
			i++;
		}
	} while (read == 4);

	fclose(file);
    return 0;
}
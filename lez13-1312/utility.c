//  rewind(FILE *file);
//  Riporta il cursore all'inizio del file

//  fseek (FILE *file, int offset, int origin)
/*
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *file = NULL;

	file = fopen("esempio", "w");
	if (file == NULL) exit(-1);
	fprintf(file, "%s", "Questo è un test");

	fseek(file, 10, SEEK_SET);
	fprintf(file, "%s", "una prova");

	fclose(file);
    return 0;
}
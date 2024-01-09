#include <stdio.h>
#include <stdlib.h>

#define LEN_STR 31

typedef struct {
	char nome[LEN_STR + 1];
	char cpu[LEN_STR + 1];
	int mp;
} Smartphone;


int main() {
	Smartphone sp;
	int read = 0;

	FILE *f = NULL;
	f = fopen("../smartphone.txt", "r");
	if (f == NULL) exit(EXIT_FAILURE);

	do {
		read = 0;

		read += fscanf(f, " %[^\n]31s", sp.nome);
		read += fscanf(f, " %[^\n]31s", sp.cpu);
		read += fscanf(f, " %d", &sp.mp);

		if (read == 3) {
			printf("\nNome: %s"
			       "\nCpu: %s"
			       "\nMp: %d\n",
			       sp.nome, sp.cpu, sp.mp);
		}
	} while (read == 3);

	fclose(f);
	return 0;
}

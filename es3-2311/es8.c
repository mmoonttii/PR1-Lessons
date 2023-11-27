/* Scrivere un programma in linguaggio C per gestire una rubrica di nomi e numeri telefonici.
 * La rubrica può contenere fino a 100 voci diverse e non possono esserci duplicati. Ogni voce è composta
 * da un nome (max 40 caratteri) e da un numero di telefono (max 10 caratteri). Il programma deve fornire
 * all’utente un menu di scelta, con le seguenti voci:
 * • 1) Aggiungi nuova voce in rubrica
 * • 2) Ricerca per nome
 * • 3) Stampa completa rubrica
 * • 0) Esci dal programma
 * Sia la stampa del menu che le prime tre voci del menu devono essere implementate con subroutine.
 * Testare il funzionamento dell’intero programma dal main.
 */

#include <stdio.h>
#include <string.h>

#define ROWS 100
#define NAME_MAX 40
#define NUMB_MAX 10

void menu();
void new(int rows, int nameLen, int numLen, char names[rows][nameLen], char nums[rows][numLen], int i);
void search(int rows, int nameLen, int numLen, char names[rows][nameLen], char nums[rows][numLen]);
void print(int rows, int nameLen, int numLen, char names[rows][nameLen], char nums[rows][numLen]);

int es8(){
	char names[ROWS][NAME_MAX + 1] = {},
		 numbers[ROWS][NUMB_MAX + 1] = {};

	int userIn,
		i = 0;

	do {
		menu();
		scanf("%d", &userIn);

		switch (userIn) {
			case 1:
				new(ROWS, NAME_MAX, NUMB_MAX + 1, names, numbers, i);
				++i;
				break;
			case 2:
				search(ROWS, NAME_MAX, NUMB_MAX + 1, names, numbers);
				break;
			case 3:
				print(ROWS, NAME_MAX, NUMB_MAX + 1, names, numbers);
				break;
			case 0:
				printf("Chiusura programma\n");
				break;
			default:
				printf("Inserisci un valore valido\n");
				menu();
				break;
		}
	} while (userIn != 0);

	return 0;
}

void menu(){
	printf("Rubrica:\n"
		   "[1] Aggiungi nuova voce in rubrica\n"
	       "[2] Ricerca per nome\n"
	       "[3] Stampa completa rubrica\n"
	       "[0] Esci dal programma\n"
		   "Scegli: ");
}

void new(int rows, int nameLen, int numLen, char names[ROWS][NAME_MAX], char nums[ROWS][NUMB_MAX], int i){
	char name[NAME_MAX + 1] = {};
	char number[NUMB_MAX + 1] = {};

	printf("Inserisci nuovo nome: ");
	scanf(" %[^\n]40s", name);
	printf("Inserisci nuovo numero: ");
	scanf(" %[^\n]10s", number);

	strcpy(names[i], name);
	strcpy(nums[i], number);

}

void search(int rows, int nameLen, int numLen, char names[rows][nameLen], char nums[rows][numLen]) {
	char name[nameLen + 1],
		 output[nameLen + 1];

	printf("Inserisci nome da cercare: ");
	scanf(" %[^\n]40s", name);

	for (int i = 0; i < rows; ++i) {
		if (strcmp(names[i], name) == 0){
			strcpy(output, nums[i]);
		}
	}
	printf("Numero associato a %s: %s", name, output);
}

void print(int rows, int nameLen, int numLen, char names[rows][nameLen], char nums[rows][numLen]) {
	for (int i = 0; i < rows; ++i) {
		printf("%d: %s, %s", i, names[i], nums[i]);
	}
}

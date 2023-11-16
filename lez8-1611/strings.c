#include <stdio.h>

#define DIM 20
int strings() {
	// Le stringhe sono array di char

	char stringa[DIM+1]; // Ogni array stringa termina con un carattere \0.
						 // Con un array [10] abbiamo 9 Caratteri, con 10 + 1 abbiamo 10 caratteri

	// Init stringhe
	char blabla[] = "Bla Bla"; // Non è obbligatorio inserire la dimensione, e capisce automaticamente

	char word[10] = "Ciao"; // I caratteri rimanenti sono occupati da \0

	char input[20];

	// Parametri acquisizione stringhe
	scanf("%[^\n]s", input); // [^\n] permette di inserire anche spazi, indica prendi tutto fino all'a capo
	scanf("%9s", input); // Limita l'inserimento a 9 caratteri

	printf("Inserisci il tuo nome");
	scanf("%s", stringa);

	printf("%s");


	return 0;
}

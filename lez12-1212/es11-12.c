/*  === ESERCIZIO 11 ===
 *  Scrivere un programma che permetta di visualizzare la k-esima stringa tra le n inserite dall'utente in un array di
 *  stringhe. Chiedere inizialmente all'utente quante stringhe vuole inserire, dopodiché acquisirle una alla volta.
 *  L'array deve essere allocato dinamicamente.
 *
 *  === ESERCIZIO 12 ===
 *  Scrivere una funzione che concateni tutte le stringhe presenti nell'array dell'esercizio precedente. La stringa
 *  risultante deve essere allocata dinamicamente, e la sua lunghezza deve essere esattamente pari al numero di
 *  caratteri che contiene (più il carattere \0). La funzione deve restituire poi il puntatore al primo carattere della
 *  stringa.
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 31

// === ESERCIZIO 11 ===
char **arrayStringhe(int n, int len);
int acquisisciNum();
int acquisisciK();
void stampaK(int k, char **arr);
char *concatStr(char **arr, int n, int len);

// === ESERCIZIO 12 ===

int main(){
	char **arrStr = NULL;
	int n = acquisisciNum(),
		k;

	arrStr = arrayStringhe(n, LEN);

	k = acquisisciK();

	stampaK(k, arrStr);

	if (arrStr != NULL) {
		for (int i = 0; i < n, i++;) {
			if (arrStr[i] == NULL){
				free(arrStr[i]);
				arrStr[i] = NULL;
			}
		}

		free(arrStr);
		arrStr = NULL;
	}

    return 0;
}

// === ESERCIZIO 11 ===

char **arrayStringhe(int n, int len){

	char **arr = NULL;

	arr = (char **) calloc(n, sizeof(char *));
	if (arr == NULL) exit(-1);

	for (int i = 0; i < n; ++i) {
		arr[i] = (char *)calloc(len + 1, sizeof(char ));
		if (arr[i] == NULL) exit(-2);
	}

	for (int i = 0; i < n; ++i) {
		printf("\nInserisci str %d: ", i);
		scanf(" %[^\n]31s", arr[i]);
	}

	return arr;
}

int acquisisciNum() {
	int num;
	printf("Inserisci num di stringhe da inserire: ");
	scanf("%d", &num);
	return num;
}

int acquisisciK() {
	int num;
	printf("Inserisci num di stringhe da visualizzare: ");
	scanf("%d", &num);
	return num;
}

void stampaK(int k, char **arr) {
	printf("Stringa %d: %s", k, arr[k]);
}

// === ESERCIZIO 12 ===

/*  RICORSIONE
 *      Per definizione un algoritmo deve terminare, per cui abbiamo bisogno di un cosiddetto caso base,
 *      caso che determina la fine della ricorsione e permette di ricosturire tutti i passi precedenti.
 *      ad esempio
 */

int fattoriale (int n) {
	if (n == 0)
		return 1;
	else
		return n * fattoriale(n - 1);
}

// Esistono diversi tipi di ricorsione
/*  PRO
 *      Permette di definire in maniera semplice funzioni complesse
 *
 *  CONTRO
 *      Nonostante sia più breve e facilmente leggibile, spesso è molto più lenta di una funzione iterativa e occupa
 *          più memoria
 */

/*====================================================================================================================*/

/*  LISTE
 *      Collezione di elementi omogenei
 *        dove ogni elemento occupa posizioni qualsiasi e non obbligatoriamente contigue
 *        con dimensione non nota a priori e variabile nel tempo
 *
 *      Ogni elemento contiene campi di informazioni e un puntatore che lo lega all'elemento successivo
 */

struct nodo{
	int info;
	struct nodo *next;
};

typedef struct nodo Nodo;

// L'ultimo elemento della lista avrà pointer next == NULL;
/* Una matrice P di dimensione NxN che rappresenta il tabellone di un campionato (ogni cella rappresenta una partita)
 * P deve essere inizializzata casuale, e l'elemento P[i][j] può avere un valore che indica pareggio, vittoria della
 * sq di casa (i-esima) o la vittoria della sq in trasferta.
 * Definire un vettore C di dimensione N che contenga il punteggio finale per ogni squadra (3 vittoria, 1 pareggio,
 * 0 sconfitta) Indicare quale squadra ha vinto il campionato
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define MIN -1
#define MAX 1

int randRange();
void initMtx(int mtx[N][N]);
void countWin(int mtx[N][N], int arr[N]);

int main(){
    int p[N][N],
		c[N] = {};

    srand(time(NULL));

	initMtx(p);


    return 0;
}

int randRange(){
	int random;

		random = MIN + rand() % (MAX - MIN + 1);

	return random;

}

void initMtx(int mtx[N][N]){

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			mtx[i][j] = randRange();
		}
	}

}

void countWin(int mtx[N][N], int arr[N]) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[]
		}
	}
}

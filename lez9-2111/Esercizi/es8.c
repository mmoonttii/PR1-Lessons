/* Scrivere due procedure che andranno richiamate nel main:
 * • popolaMatrice che riceva come parametro una matrice di float e generi casualmente i suoi elementi in un
 * range definito dall’utente, sfruttando randRangeFloat dell’esercizio 1; anche righe e colonne vanno generate
 * casualmente.
 * • stampaMatrice che prenda come parametro una matrice di float e ne stampi il suo contenuto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 5
void popolaMatrice(int min, int max, int r, int c, float mx[][c]);

int main(){
	float matrix[R][C];

    popolaMatrice(min, max, r, c, matrix);
    return 0;
}

void popolaMatrice(int min, int max, int r, int c, float mx[][c]){
    

}
/* Scrivere una funzione in C, chiamata iniziali(), che valuti quanti caratteri iniziali sono in comune tra due
 * stringhe date. La funzione riceve come parametri due stringhe, e restituisce il numero intero
 * corrispondente. Testare la subroutine nel main.
 * Es: inserendo «ciao» e «cibo», iniziali() deve restituire 2
 */
#include <stdio.h>

#define DIM 20

int iniziali(int dim, char w1[dim], char w2[dim]);
void acquisisci(int dim, char word[dim]);
int es7(){
    char w1[DIM + 1] = {},
         w2[DIM + 1] = {};
    int count;

    acquisisci(DIM, w1);
    acquisisci(DIM, w2);

    count = iniziali(DIM, w1, w2);

    printf("%s e %s hanno i primi %d caratteri in comune", w1, w2, count);
    return 0;
}

int iniziali(int dim, char w1[], char w2[]) {

    int count = 0;

    for (int i = 0; i < dim; ++i) {
        if (w1[i] == w2[i]){
            count++;
            if (i != 0 && (w1[i - 1] != w2[i - 1])){
                i = dim;
            }
        }
    }

    return count;
}

void acquisisci(int dim, char *word) {
    printf("Inserisci parola: ");
    scanf(" %[^\n]20s", word);
}

/* Acquisire una stringa e definire
 * void strCapsLock(...) trasforma la stringa tutta maiuscola
 * void strMinus(...) trasforma la stringa tutta minuscola
 * void strInvertCaps(...) inverte maiuscolo e minuscolo
 * void strInitCaps(...) iniziali di ogni parola maiuscole e resto minuscolo
 * void strSigla(...) mantenere nella stringa solo le iniziali e costruire una sigla
 */
#include <stdio.h>

#define DIM 30
void strCapsLock(int dim, char string[dim]);
void strMinus(int dim, char string[dim]);
void strInvertCaps(int dim, char string[dim]);
void strInitCaps(int dim, char string[dim]);
void strSigla(int dim, char string[dim]);

int main(){
    char string[DIM + 1];

    printf("Inserisci stringa");
    scanf("%[^\n]30s", string);

    strCapsLock(DIM, string);
    printf("\n%s", string);

    strMinus(DIM, string);
    printf("\n%s", string);

    strInvertCaps(DIM, string);
    printf("\n%s", string);

    strInitCaps(DIM, string);
    printf("\n%s", string);

    strSigla(DIM, string);
    printf("\n%s", string);

    return 0;

}

void strCapsLock(int dim, char string[dim]){
    for (int i = 0; i < dim; ++i) {
        if (string[i] >= 'a' && string[i] <= 'z'){
            string[i] -= 32;
        }
    }
}

void strMinus(int dim, char string[dim]){
    for (int i = 0; i < dim; ++i) {
        if (string[i] >= 'A' && string[i] <= 'Z'){
            string[i] += 32;
        }
    }
}

void strInvertCaps(int dim, char string[dim]){
    for (int i = 0; i < dim; ++i) {
        if (string[i] >= 'A' && string[i] <= 'Z'){
            string[i] += 32;
        } else if (string[i] >= 'a' && string[i] <= 'z'){
            string[i] -= 32;
        }
    }
}

void strInitCaps(int dim, char string[dim]){
    if (string[0] >= 'a' && string[0] <= 'z'){
        string[0] -= 32;
    }
    for (int i = 1; i < dim; ++i) {
        if (string[i-1] == ' '){
            if (string[0] >= 'a' && string[0] <= 'z'){
                string[0] -= 32;
            }
        } else {
            if (string[i] >= 'A' && string[i] <= 'Z'){
                string[i] += 32;
            }
        }
    }
}


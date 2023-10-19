#include <stdio.h>
#include <stdbool.h>

int nah() {
    int aux;
    bool flag;

    printf("Inserisci un booleano");
    scanf("%d", &aux);

    flag = aux == 0 ? false : true;

    printf("%c");

    return 0;
}

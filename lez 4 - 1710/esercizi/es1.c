#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VOTO_MAX 10
#define VOTO_MIN 2

int es1(){
    // varibaile vot
    int voto;

    // seed init
    srand(time(NULL));

    // rand gen
    voto = VOTO_MIN + rand() % (VOTO_MAX - VOTO_MIN + 1);

    printf("Debug voto: %d\n", voto);

    switch (voto) {
        case 10:
            printf("Ottimo");
            break;
        case 9:
            printf("Distinto");
            break;
        case 8:
            printf("Buono");
            break;
        case 7:
            printf("Discreto");
            break;
        case 6:
            printf("Sufficiente");
            break;
        case 5:
            printf("Lievemente insufficiente");
            break;
        case 4:
        case 3:
        case 2:
            printf("Gravemente insufficiente");
            break;
    }
    return 0;
}
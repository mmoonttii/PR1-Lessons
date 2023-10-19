#include <stdio.h>

#define SCONTO_2 10
#define SCONTO_1 5
int eses(){

    float spesa, sconto = 0;
    int fasciaSconto;
    printf("Inserisic quanto hai speso: ");
    scanf("%f", &spesa);

    /* Risoluzione if - else
    if (spesa >= 360){
       sconto = spesa * SCONTO_350 / 100;
    } else if (spesa >= 120){
        sconto = spesa * SCONTO_120 / 100;
    }
    */

    /* Risoluzione if - switch
    if (spesa >= 360){
        fasciaSconto = 2;
    } else if (spesa >= 120){
        fasciaSconto = 1;
    }

    switch (fasciaSconto) {
        case 1:
            sconto = spesa * SCONTO_1 / 100;
            break;
        case 2:
            sconto = spesa * SCONTO_2 / 100;
            break;
    }
    */

    fasciaSconto = (int)spesa / 120;
    switch (fasciaSconto) {
        case 0:
        case 1:
        case 2:
            sconto = spesa * SCONTO_1 / 100;
            break;
        default:
            sconto = spesa * SCONTO_2 / 100;
            break;
    }

    spesa -= sconto;
    printf("Costo spesa: %.2f", spesa);
    return 0;
}

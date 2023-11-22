#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomic(){
    int num, min, max;

    srand(time(NULL));
    num = min + rand()%(max-min+1); // Tramite questa formula possiamo impostare un massimo e minimo al rand()

    printf("\n%d", num);

    return 0;
}
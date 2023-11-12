#include <stdio.h>
#include <math.h>

int es8(){
    float x, result;
    printf("Inserire valore di x:");
    scanf("%f", &x);

    result = (8 * pow(x, 3)) + (4 * pow(x, 2)) + (3 * x) - 4;

    printf("\nresult: %f", result);
    return 0;
}
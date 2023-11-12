#include <stdio.h>
#define EUR_GBP 0.84

int es6(){
    float importoEur, importoGbp;

    printf("Inserire Eur: ");
    scanf("%f", &importoEur);

    importoGbp = importoEur * EUR_GBP;

    printf("Importo in Sterline pari a %.2f GBP", importoGbp);
    return 0;
}

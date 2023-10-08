#include <stdio.h>
#define IVA 0.22

int es7(){
    float prezzoProdotto, ivaApplicata, prezzoFinale;
    printf("Inserire prezzo prodotto: ");
    scanf("%f", &prezzoProdotto);

    ivaApplicata = prezzoProdotto * IVA;
    prezzoFinale = prezzoProdotto + ivaApplicata;

    printf("\nImporto Iniziale: %.2f EUR", prezzoProdotto);
    printf("\nIVA applicata (%.0f%%): %.2f EUR", IVA*100, ivaApplicata);
    printf("\nImporto finale: %.2f EUR", prezzoFinale);
    return 0;
}
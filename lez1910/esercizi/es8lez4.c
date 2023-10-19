#include <stdio.h>

int es8lez4(){
    char carattere;

    printf("Inserire carattere: ");
    scanf(" %c", &carattere);

    if (carattere >= 'A' && carattere <= 'Z'){
        carattere += 32;
    }

    switch (carattere) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Vocale");
            break;
        default:
            printf("Carattere non consentito");
            break;
    }

    return 0;
}
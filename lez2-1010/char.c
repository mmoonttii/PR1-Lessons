#include <stdio.h>

int chars(){
    char var = 'a';

    var = var + 3;

    int a = 75;
    char c1 = 'a';
    char c2 = a;

    char c3 = '5';
    char c4 = 2;

    printf("%c, %c, %c, %c", c1, c2, c3, c4);

    char b = 'f';
    b -= 32; /* -= è un operatore composto è uguale a b = b - 32, ma ha la priorità MINIMA
              * +=, -=, *=, /=, %= */

    printf("\n%c, %d", b, b);
    return 0;
}
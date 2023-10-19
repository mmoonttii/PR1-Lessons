#include <stdio.h>

int es2() {
    int a, b, c;

    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);
    printf("Inserisci c: ");
    scanf("%d", &c);

    if (a > b && a > c){
        printf("a maggiore");
    } else if (b > c){
            printf("b maggiore");
    } else {
            printf("c maggiore");
    }

    return 0;
}
#include <stdio.h>

int main() {
    // Dichiarazione delle variabili
    int var1, var3;
    int var2;
    float var_float;
    char var_char;

    /* Assgnazione valori alle variabili: valuta ciò che è a destra dell'uguale,
     * una volta valutato lo assegna alla variabile */
    var1 = 10;
    var2 = 4;
    var3 = var1 % var2; // var3 = 2

    var_char = 'A';

    var_float = 5 * 7 / ((3 + 5) - 3) - 3; /* Segue le regole di precedenza,
            * possiamo alterare il flusso con le parentesi tonde */

    printf("Il valore di %d \% % %d è: %d\n", var1, var2, var3);
    return 0;
}

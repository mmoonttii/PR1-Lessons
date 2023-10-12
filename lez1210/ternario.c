int main(){
    int i = 0, j = 2, k;

    k = i < j ? i : j;

    if (i<j)
        k = i;
    else
        k = j;

    // Le due espressioni sono equivalenti
    return 0;
}
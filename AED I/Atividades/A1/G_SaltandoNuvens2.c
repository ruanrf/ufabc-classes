#include <stdio.h>

int main() {

    int qtdNuvens, salto;
    scanf("%d %d", &qtdNuvens, &salto);

    int energia = 100;
    // gasta 1 de energia por salto; perde +2 se a nuvem for "1" (tempestade)

    int *nuvens =  (int *)malloc(qtdNuvens * sizeof(int));

    for (int i = 0; i < qtdNuvens; i++) {
        scanf("%d", &nuvens[i]);
    }   

    for (int i = 0; i < qtdNuvens; i += salto) {
        if (nuvens[i] == 1) {
            energia -= 3;
        } else if (nuvens[i] == 0) {
            energia--;
        }
    }
    printf("%d\n", energia);

}
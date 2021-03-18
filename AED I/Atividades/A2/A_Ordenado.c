#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int verificaOrdenado(int *, int);

int main() {

    int *vetor, tam;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int *)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++) {
            scanf("%d", &vetor[i]);
        }

        if (verificaOrdenado(vetor, tam) == true) {
            printf("S\n");
        } else {
            printf("N\n");
        }

        // for(int i = 0; i < tam; i++) {
        //     printf("%d%s", vetor[i], i < tam-1 ? " " : "\n");
        // }

        free(vetor);
    }
    return 0;
}

int verificaOrdenado(int *vetor, int tam) {

    bool ordenado = false;
    int crescente = 0;
    int decrescente = 0;

    // verifica crescente - 1 = ordenado, 0 = não
    for (int i = 0; i < tam - 1; i++) { 
        if (vetor[i] > vetor[i+1]) {
            crescente = 0;
            break; 
        } else {
            crescente = 1;
        }
    }
    // verifica decrescente - 1 = ordenado, 0 = não
    for (int i = 0; i < tam - 1; i++) {
        if (vetor[i] < vetor[i+1]) {
            decrescente = 0;
            break;
        } else {
            decrescente = 1;
        }
    }
    // se for ordenado crescente || decrescente || se 0 < tamanho < 1
    if (crescente == 1 || decrescente == 1 || tam <= 1) {
        ordenado = true;
    } 
    return ordenado;
}


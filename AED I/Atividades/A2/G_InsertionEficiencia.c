#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *, int);

void insertionSort(int *, int);

int main() {
    int tam, *vetor, i;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int*) malloc(tam * sizeof(int));

        for(i=0; i<tam; i++) {
            scanf("%d", &vetor[i]);
        }

        insertionSort(vetor, tam);
        // imprimeVetor(vetor, tam);

        free(vetor);
    }
    return 0;
}

void imprimeVetor(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        if (i == tam-1) printf("%d\n", vetor[i]);
        else printf("%d ", vetor[i]);
    }
}

void insertionSort(int *vetor, int tam)
{
    int chave, j, movimentos = 0;
    for(int i=1; i<tam; i++) {
        chave = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            // imprimeVetor(vetor, tam);
            vetor[j] = chave;
            j--;
            movimentos++;
        }
    }
    printf("%d\n", movimentos);
}
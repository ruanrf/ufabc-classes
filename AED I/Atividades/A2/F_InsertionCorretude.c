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
    int chave, j;
    for(int i=1; i<tam; i++) {
        chave = vetor[i];
        j = i-1;
        printf("Sublista Ordenada: ");
        imprimeVetor(vetor, i);
        printf("Sublista Desordenada: ");
        for (int k = i; k < tam; k++) {
            if (k == tam-1) printf("%d\n", vetor[k]);
            else printf("%d ", vetor[k]);
        }
        while(j>=0 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            vetor[j] = chave;
            j--;
        }
    }
        printf("Sublista Ordenada: ");
        imprimeVetor(vetor, tam);
        printf("Sublista Desordenada:\n");
}
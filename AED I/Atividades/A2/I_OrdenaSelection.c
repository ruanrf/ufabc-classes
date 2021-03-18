#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *, int);

void selectionSort(int *, int);

int main() {
    int tam, *vetor;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int *) malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++) {
            scanf("%d", &vetor[i]);
        }

        imprimeVetor(vetor, tam);
        selectionSort(vetor, tam);

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

void selectionSort(int *vetor, int tam)
{
    int aux, iMin, trocas=0;
    for(int i=0; i<tam-1; i++) {
        iMin=i;
        for(int j=i+1; j<tam; j++) {
            if(vetor[j] < vetor[iMin]) {
                iMin = j;
                trocas++;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[iMin];
        vetor[iMin] = aux;
        imprimeVetor(vetor, tam);
    }
    imprimeVetor(vetor, tam);
    printf("%d\n", trocas);
}
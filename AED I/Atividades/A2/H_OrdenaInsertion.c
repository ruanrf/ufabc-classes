#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprimeVetor(int *, int);

void insertionSort(int *, int);

int main() {
    int tam, *vetor, i;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int*) malloc(tam * sizeof(int));

        for(i=0; i<tam; i++) {
            scanf("%d", &vetor[i]);
        }

        imprimeVetor(vetor, tam);
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
    int chave, j, trocas = 0, piorCaso;
    for(int i=1; i<tam; i++) {
        chave = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            vetor[j] = chave;
            j--;
            imprimeVetor(vetor, tam);
            trocas++;
        }
    }
    imprimeVetor(vetor, tam);
    printf("Trocas:%d\n", trocas);

    piorCaso = ((tam*tam) - tam) / 2;
    
    if (trocas == piorCaso) printf("PIOR CASO\n");
    else if (trocas == 0) printf("MELHOR CASO\n");
    else printf("CASO ALEATORIO\n");
}
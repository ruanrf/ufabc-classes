#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *);

void bubbleSort(int *, int);

int main() {
    int tam, *vetor;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int*) malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++) {
            scanf("%d", &vetor[i]);
        }
        
        imprimeVetor(vetor);
        bubbleSort(vetor, tam);

        free(vetor);
    }
    return 0;
}

void imprimeVetor(int *vetor) {
    int tam = sizeof(vetor);
    for (int i = 0; i < tam; i++) {
        if (i == tam-1) printf("%d\n", vetor[i]);
        else printf("%d ", vetor[i]);
    }
}

void bubbleSort(int *vetor, int tam)
{
    int aux, trocas=0;

    for(int i=0; i<tam-1; i++) {

        for(int j=0; j<tam-1-i; j++) {

            if(vetor[j] > vetor[j+1]) {   
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

                trocas++;
                imprimeVetor(vetor);
            }
        }
    }
    imprimeVetor(vetor);
    printf("Trocas: %d\n", trocas);
}
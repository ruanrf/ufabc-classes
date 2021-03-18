#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *, int);
void qSort(int *, int);
void quickSort(int *, int, int, int);
int particiona(int *, int, int, int);

int main() {
    int tam, *vetor, i;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int *)malloc(tam * sizeof(int));

        for(i = 0; i < tam; i++) {
            scanf("%d", &vetor[i]);
        }

        imprimeVetor(vetor, tam);
        qSort(vetor, tam);
        imprimeVetor(vetor, tam);
        
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

void qSort(int *vetor, int tam) {
    quickSort(vetor, 0, tam-1, tam);
}

void quickSort(int *vetor, int e, int d, int tam) {
    int p;
    if(e < d) {
        p = particiona(vetor, e, d, tam);
        quickSort(vetor, e, p-1, tam);
        quickSort(vetor, p+1, d, tam);
    }
}

int particiona(int *vetor, int e, int d, int tam) {
    int i, pm, aux;
    for(i=e, pm=e-1; i<d; i++) {
        if(vetor[i] <= vetor[d]) {
            pm++;
            aux = vetor[pm];
            vetor[pm] = vetor[i];
            vetor[i] = aux;
        }
        imprimeVetor(vetor, tam);
    }
    aux = vetor[pm+1];
    vetor[pm+1] = vetor[d];
    vetor[d] = aux;
    imprimeVetor(vetor, tam);
    return pm+1;
}
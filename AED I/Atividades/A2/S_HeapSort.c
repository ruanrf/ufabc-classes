#include <stdio.h>
#include <stdlib.h>

int filhoEsquerda(int);
int filhoDireita(int);
int ultimoPai(int);
void peneirar(int *, int, int);
void constroiHeap(int *, int);
int selecionaMax(int *, int);
void heapSort(int *, int);
void imprimeVetor(int *, int);

int main() {
    int *vetor, tam, i;

    while(scanf("%d", &tam) != EOF) {
        vetor = (int*) malloc(tam * sizeof(int));

        for(i=0; i<tam; i++) {
            scanf("%d", &vetor[i]);
        }

        imprimeVetor(vetor, tam);
        heapSort(vetor, tam);
        imprimeVetor(vetor, tam);

        free(vetor);
    }
    return 0;
}


int filhoEsquerda(int p) {
    return 2*p+1;
}

int filhoDireita(int p) {
    return 2*p+2;
}

int ultimoPai(int n) {
    return (n/2)-1;
}

void peneirar(int *h, int n, int p) {
    int iMaior = p, aux;
    if(filhoEsquerda(p) < n && h[filhoEsquerda(p)] > h[iMaior]) {
        iMaior = filhoEsquerda(p);
    }
    if(filhoDireita(p) < n && h[filhoDireita(p)] > h[iMaior]) {
        iMaior = filhoDireita(p);
    }
    if(iMaior != p) {
        aux = h[p];
        h[p] = h[iMaior];
        h[iMaior] = aux;
        peneirar(h, n, iMaior);
    }
}

void constroiHeap(int *h, int n) {
    int i;
    for(i=ultimoPai(n); i>=0; i--) {
        peneirar(h, n, i);
    }
}

int selecionaMax(int *h, int n) {
    int aux = h[0];
    h[0] = h[n-1];
    h[n-1] = aux;
    return n-1;
}

void heapSort(int *h, int n) {
    int i;
    constroiHeap(h, n);
    for(i=n; i>0; i--)
    {   
        imprimeVetor(h, n);
        n = selecionaMax(h, n);
        peneirar(h, n, 0);
    }
}

void imprimeVetor(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        if (i < tam-1) printf("%d ", vetor[i]);
        else if (i == tam-1) printf("%d\n", vetor[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int *itens;
    int tamanho;
};

struct Heap criaHeap(int);
int filhoEsquerda(int);
int filhoDireita(int);
int ultimoPai(int);
void peneirar(struct Heap *, int);
void constroiHeap(struct Heap *);
void imprimeVetor(int *, int);

int main() {
    int tam;
    struct Heap h;

    while(scanf("%d", &tam) != EOF) {
        h = criaHeap(tam);
        for(int i=0; i<h.tamanho; i++) {
            scanf("%d", &h.itens[i]);
        }

        constroiHeap(&h);

        imprimeVetor(h.itens, tam);

    }
    return 0;
}

struct Heap criaHeap(int n) {
    struct Heap h;
    h.tamanho = n;
    h.itens = (int*) malloc(n * sizeof(int));
    return h;
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

void peneirar(struct Heap *h, int p) {
    int iMenor = p, aux;

    if(filhoDireita(p) < h->tamanho && h->itens[filhoDireita(p)] < h->itens[iMenor]) {
        iMenor = filhoDireita(p);
    }
    if(filhoEsquerda(p) < h->tamanho && h->itens[filhoEsquerda(p)] < h->itens[iMenor]) {
        iMenor = filhoEsquerda(p);
    }
    if(iMenor != p) {
        aux = h->itens[p];
        h->itens[p] = h->itens[iMenor];
        h->itens[iMenor] = aux;
        peneirar(h, iMenor);
    }
}

void constroiHeap(struct Heap *h) {
    int i;
    for(i=ultimoPai(h->tamanho); i>=0; i--) {
        peneirar(h, i);
    }
}

void imprimeVetor(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        if (i < tam-1) printf("%d ", vetor[i]);
        else if (i == tam-1) printf("%d\n", vetor[i]);
    }
}
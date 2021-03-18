#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *, int);
void mergeSort(int *, int, int);
void intercala(int *, int, int, int);

int main() {

    int tamA, tamB, tamC, *vetor;

    while (scanf("%d", &tamA) != EOF) {

        scanf("%d", &tamB);
        tamC = tamA + tamB;

        vetor = (int *) malloc(tamC * sizeof(int));

        for (int i = 0; i < tamA; i++) {
            scanf("%d", &vetor[i]);
        }
        
        for (int i = 0; i < tamB; i++) {
            scanf("%d", &vetor[tamA+i]);
        }        
        
        // printf("tamC: %d\n", tamC);

        mergeSort(vetor, 0, tamC-1);
        imprimeVetor(vetor, tamC);

        free(vetor);
    }
    return 0;
}

void imprimeVetor(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        if (i == tam-1) printf("%d\n", vetor[i]);
        else printf("%d\n", vetor[i]);
    }
}

void mergeSort(int *v, int e, int d) {
    int meio;
    if(e < d)
    {
        meio = (e+d)/2;
        mergeSort(v, e, meio);
        mergeSort(v, meio+1, d);
        intercala(v, e, meio+1, d);
    }
}

void intercala(int *v, int e, int m, int d) {
    int *vTemp, lim_esq = m-1, tamanho = d-e+1, i, j, iTemp;
    vTemp = (int*) malloc((tamanho)* sizeof(int));

    for(i=e, j=m, iTemp=0; i<=lim_esq && j<=d; iTemp++) {
        if(v[i] < v[j]) {
            vTemp[iTemp] = v[i];
            i++;
        } else {
            vTemp[iTemp] = v[j];
            j++;
        }
    }

    for(;i<=lim_esq; iTemp++, i++) {
        vTemp[iTemp] = v[i];
    }

    for(;j<=d; iTemp++, j++) {
        vTemp[iTemp] = v[j];
    }

    for(i=e, j=0; i<=d; i++, j++) {
        v[i] = vTemp[j];
    }
    free(vTemp);
}
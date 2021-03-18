#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *, int);
void mergeSort(int *, int, int, int);
void intercala(int *, int, int, int);

int main()
{
    int *vetor, tam, i;
    while(scanf("%d", &tam) != EOF)
    {
        vetor = (int*) malloc((tam+2) * sizeof(int));
        for(i=0; i<tam; i++)
        {
            scanf("%d", &vetor[i]);
        }

        imprimeVetor(vetor, tam);        
        mergeSort(vetor, 0, tam-1, tam);
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

void mergeSort(int *vetor, int e, int d, int tam) {
    int meio;
    if(e < d)
    {
        meio = (e+d)/2;
        mergeSort(vetor, e, meio, tam);
        mergeSort(vetor, meio+1, d, tam);
        imprimeVetor(vetor, tam);        
        intercala(vetor, e, meio+1, d);
    }
}

void intercala(int *vetor, int e, int m, int d) {
    int *vetorTemp, lim_esq = m-1, tamanho = d-e+1, i, j, iTemp;
    vetorTemp = (int*) malloc((tamanho)* sizeof(int));

    for(i=e, j=m, iTemp=0; i<=lim_esq && j<=d; iTemp++) {
        if(vetor[i] < vetor[j]) {
            vetorTemp[iTemp] = vetor[i];
            i++;
        } else {
            vetorTemp[iTemp] = vetor[j];
            j++;
        }
    }

    for(;i<=lim_esq; iTemp++, i++) {
        vetorTemp[iTemp] = vetor[i];
    }

    for(;j<=d; iTemp++, j++) {
        vetorTemp[iTemp] = vetor[j];
    }

    for(i=e, j=0; i<=d; i++, j++) {
        vetor[i] = vetorTemp[j];
    }
    free(vetorTemp);
}
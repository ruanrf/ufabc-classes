#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

float buscaRacional(int *, int, float, float);

int main() {
    int tam, *vetor;
    float r1, r2;

    scanf("%d", &tam);

    tam = tam*2;

    vetor = (int *)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }

    while(scanf("%f %f", &r1, &r2) != EOF) {

        bool isRacional = buscaRacional(vetor, tam, r1, r2);

        if (isRacional == true) 
            printf("S\n");
        else 
            printf("N\n");
    }

    free(vetor);
    return 0;
}

float buscaRacional(int *vetor, int tam, float r1, float r2) {

    float valorBusca = r1 / r2, valorVetor = 0;

    for (int i = 0; i < tam; i+=2) {
        float valorVetor = (float) vetor[i] / (float) vetor[i+1];

        if(valorBusca == valorVetor) return true;
    }
    return false;
}
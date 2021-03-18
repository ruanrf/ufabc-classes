#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscaBinaria(int *, int, int, int);

int main() {

    int tam, busca, index, *vetor;
    
    // recebe tamanho do vetor
    scanf("%d", &tam);

    vetor = (int *)malloc(tam * sizeof(int));

    // recebe vetor
    for(int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }

    // Valores para verificar até o fim do arquivo
    while(scanf("%d", &busca) != EOF) {

        index = buscaBinaria(vetor, busca, 0, tam - 1);

        if (index == -1) {
            printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", busca);
        }
        else {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", busca);
        }
    
    }
    free(vetor);

    return 0;
}

int buscaBinaria(int vetor[], int busca, int menor, int maior) {
  
    int meio = (menor + maior)/2;

    if (vetor[meio] == busca) // encontrado
        return meio;

    if (menor > maior) // não encontrado
        return -1;

    else {
        if (vetor[meio] < busca) {
            for (int i = menor; i < meio; i++) {
                printf("%d ", vetor[i]);
            }
            printf("%d", vetor[meio]);
            printf("\n");
            return buscaBinaria(vetor, busca, meio+1, maior);
        }
        else {
            for (int i = meio; i < maior; i++) {
                printf("%d ", vetor[i]);
            }
            printf("%d", vetor[maior]);
            printf("\n");
            return buscaBinaria(vetor, busca, menor, meio-1);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

int somaVetor(int *, int[], int);

int main() {
    int n, soma;
    scanf("%d\n", &n);
    
    int *vet = (int *)malloc(sizeof(int) * n);
    
    for (int i=0; i<n; i++) {
        scanf("%d\n", &vet[i]);
    }

    somaVetor(&soma, vet, n);

    printf("\n%d", soma);
    
    free(vet);
    return 0;
}

int somaVetor(int *soma, int vet[], int n) {
    
    for (int i=0; i<n; i++) {
        soma += *soma + vet[i];
    }
}

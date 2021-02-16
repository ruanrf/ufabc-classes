#include <stdlib.h>
#include <stdio.h>

int somaVetor(int, int *, long int *);

int main() {

  int n, *vet;
  long int soma = 0; 

  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  somaVetor(n, vet, &soma);
  
  printf("%ld\n", soma);

  return 0;
}


int somaVetor(int n, int *vet, long int *soma) { 

  for (int i=0; i<n; i++) {
    *soma += vet[i];
  }
  
}
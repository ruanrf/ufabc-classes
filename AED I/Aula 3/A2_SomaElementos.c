#include <stdlib.h>
#include <stdio.h>

int somaElementos(int, int *, int *);

int main() {

  int tam, soma = 0, i, *vet;
  scanf("%d", &tam);

  vet = (int *)malloc(tam * sizeof(int));

  for (int i = 0; i < tam; i++) {
    scanf("%d", &vet[i]);
  }

  somaElementos(tam, vet, &soma);
  
  printf("%d\n", soma);

  free(vet);
  return 0;
}

int somaElementos(int tam, int *vet, int *soma) { 

  for (int i=0; i<tam; i++) {
    *soma += vet[i];
  }

}
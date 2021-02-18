#include <stdio.h>

int main() {

    int qtdAlbum, qtdCompradas, faltantes, unicas = 0;

    scanf("%d", &qtdAlbum); // tamanho do álbum
    scanf("%d", &qtdCompradas); // qtd figurinhas compradas

    int *album = malloc(qtdAlbum * sizeof(int));
    int *compradas = malloc(qtdCompradas * sizeof(int));

    // cria o álbum
    for (int i = 0; i < qtdAlbum; i++) {
        album[i] = i + 1; 
    }

    // lista as compradas
    for (int i = 0; i < qtdCompradas; i++) { 
        scanf("%d", &compradas[i]); // recebe as figurinhas compradas
    }

    for (int i = 0; i < qtdAlbum; i++) {
        for (int j = 0; j < qtdCompradas; j++) {
            if (album[i] == compradas[j]) {
                unicas++;
                break;
            }
        }
    }

    faltantes = qtdAlbum - unicas;
    printf("%d\n", faltantes);

}

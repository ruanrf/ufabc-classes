#include <stdio.h>

int verificaBissexto(int);

int main() {

    int ano;
    scanf("%d", &ano);

    printf("%s", verificaBissexto(ano));

    return 0;
}

int verificaBissexto(int ano) {
    
    if(ano % 400 == 0)
        return("ANO BISSEXTO\n");
    else if ((ano % 4 == 0) && (ano % 100 != 0)) 
        return("ANO BISSEXTO\n");
    else 
        return("ANO NAO BISSEXTO\n");

    return 0;
} 

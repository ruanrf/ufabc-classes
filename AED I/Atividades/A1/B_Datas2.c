#include <stdio.h>
#include <stdbool.h>

bool verificaBissexto(long int);

int validaData(long int, long int, long int);

int main() {

    long int dia, mes, ano;
    scanf("%ld %ld %ld", &dia, &mes, &ano);

    printf("%s\n", validaData(dia, mes, ano));

    return 0;
}

bool verificaBissexto(long int ano) {
    
    if(ano % 400 == 0)
        return true;
    else if ((ano % 4 == 0) && (ano % 100 != 0)) 
        return true;
    else 
        return false;
} 

int validaData(long int dia, long int mes, long int ano) {
    // verifica fevereiro
    if (mes == 2) { 
        if ((dia <= 29 && dia > 0 && verificaBissexto(ano) == true) ||
            (dia <= 28 && dia > 0 && verificaBissexto(ano) == false)) {
            return("DATA VALIDA");
        } else {
            return("DATA INVALIDA");
        }
    } 
    // verifica meses de 31 dias
    else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        if(dia <= 31 && dia > 0) {
            return("DATA VALIDA");
        } else {
            return("DATA INVALIDA");
        }
    } 
    // verifica meses de 30 dias
    else if (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia <= 30 && dia > 0) {
            return("DATA VALIDA");
        } else {
            return("DATA INVALIDA");
        }
    } else {
        return("DATA INVALIDA");
    }
    
    return 0;
}

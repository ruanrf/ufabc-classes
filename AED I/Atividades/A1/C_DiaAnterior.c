#include <stdio.h>
#include <stdbool.h>

bool verificaBissexto(int);

void diaAnterior(int, int, int, int *, int *, int *);

int main() {

    int dia, mes, ano, diaA, mesA, anoA;

    scanf("%d %d %d", &dia, &mes, &ano);
    
    diaAnterior(dia, mes, ano, &diaA, &mesA, &anoA);

    printf("%d %d %d\n", diaA, mesA, anoA);

/*// teste para verificar a integridade das condições:
    for(int i = 0; i < 365; i++) {
        diaAnterior(diaA, mesA, anoA, &diaA, &mesA, &anoA);
        printf("%d %d %d\n", diaA, mesA, anoA);
    } */

    return 0; 
}

bool verificaBissexto(int ano) {
    if(ano % 400 == 0)
        return true;
    else if ((ano % 4 == 0) && (ano % 100 != 0)) 
        return true;
    else 
        return false;
} 

void diaAnterior(int dia, int mes, int ano, int *diaA, int *mesA, int *anoA) {
    
    if (mes == 3) {  // mes 03
        if (verificaBissexto(ano) == true && dia == 1) { // ano bissexto, dia 01
            *diaA = 29;
            *mesA = 2;
            *anoA = ano; 
        } else if (dia == 1) { // ano não bissexto, dia 01
            *diaA = 28;
            *mesA = 2;
            *anoA = ano;
        } else {
            *diaA = dia - 1;
            *mesA = mes;
            *anoA = ano;
        }
    } else if (mes == 1 && dia == 1) { // primeiro dia do ano
        *diaA = 31;
        *mesA = 12;
        *anoA = ano - 1;

    // meses com anterior = 30
    } else if ((mes == 5 || mes == 7 || mes == 10 || mes == 12) && dia == 1) {
        *diaA = 30;
        *mesA = mes - 1;
        *anoA = ano; 

    // meses com anterior = 31
    } else if ((mes == 2 || mes == 4 || mes == 6 || mes == 8 || mes == 9 || mes == 11) && dia == 1) {
        *diaA = 31;
        *mesA = mes - 1;
        *anoA = ano;    
    } else {
        *diaA = dia - 1;
        *mesA = mes;
        *anoA = ano;
    }
}

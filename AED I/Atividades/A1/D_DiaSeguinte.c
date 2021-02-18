#include <stdio.h>
#include <stdbool.h>

bool verificaBissexto(int);

void diaSeguinte(int, int, int, int *, int *, int *);

int main() {

    int dia, mes, ano, diaS, mesS, anoS;

    scanf("%d %d %d", &dia, &mes, &ano);

    diaSeguinte(dia, mes, ano, &diaS, &mesS, &anoS);

    printf("%d %d %d\n", diaS, mesS, anoS);

/* // teste para verificar a integridade das condições:
    for(int i = 0; i < 365; i++) {
        diaSeguinte(diaS, mesS, anoS, &diaS, &mesS, &anoS);
        printf("%d %d %d\n", diaS, mesS, anoS);
    }
 */
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

void diaSeguinte(int dia, int mes, int ano, int *diaS, int *mesS, int *anoS) {
    if (mes == 2) { // mes 02
        if (verificaBissexto(ano) == true && dia == 28) { //ano bissexto e dia 28
            *diaS = 29;
            *mesS = mes;
            *anoS = ano;
        } else if (dia == 29 || (verificaBissexto(ano) == false && dia == 28)) { // dia 29 ou não bissexto dia 28
            *diaS = 1; 
            *mesS = 3;
            *anoS = ano;
        } else {
            *diaS = dia+1;
            *mesS = mes;
            *anoS = ano;
        }
    // virada do ano - 31 de dezembro
    } else if (mes == 12 && dia == 31) {
        *diaS = 1;
        *mesS = 1;
        *anoS = ano+1;
    // meses de 31 dias ou meses de 30 dias
    } else if (((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10) && dia == 31) ||
           ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia == 30)) {
        *diaS = 1;
        *mesS = mes+1;
        *anoS = ano;
    // demais
    } else {
        *diaS = dia+1;
        *mesS = mes;
        *anoS = ano;
    }
}

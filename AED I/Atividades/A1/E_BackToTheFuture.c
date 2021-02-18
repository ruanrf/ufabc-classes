#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificaBissexto(int);

void diaAnterior(int, int, int, int *, int *, int *);

void diaSeguinte(int, int, int, int *, int *, int *);

int main() {

    int qtdTestes, qtdComandos, dia, mes, ano, diaS = 0, mesS = 0, anoS = 0;
    int *diaF, *mesF, *anoF;
    char *sequencia;

    scanf("%d", &qtdTestes);

    diaF = (int *)malloc(qtdTestes * sizeof(int));
    mesF = (int *)malloc(qtdTestes * sizeof(int));
    anoF = (int *)malloc(qtdTestes * sizeof(int));

    for (int i = 0; i < qtdTestes; i++) {
        scanf("%d %d %d", &dia, &mes, &ano);
        scanf("%d\n", &qtdComandos);
        sequencia = (char *)malloc(qtdComandos * sizeof(char));
        scanf("%s", sequencia);

        diaS = dia;
        mesS = mes;
        anoS = ano;

        for (int j = 0; j < qtdComandos; j++) {

            // 62 = ">"
            if (sequencia[j] == 62) { 
                diaSeguinte(diaS, mesS, anoS, &diaS, &mesS, &anoS);
            
            // 60 = "<"
            } else if (sequencia[j] == 60) {
                diaAnterior(diaS, mesS, anoS, &diaS, &mesS, &anoS);
            }
        }     
        diaF[i] = diaS;
        mesF[i] = mesS;
        anoF[i] = anoS;     
    }

    for (int j = 0; j < qtdTestes; j++) {
        printf("%d/%d/%d\n", diaF[j], mesF[j], anoF[j]);
    }
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

void diaAnterior(int dia, int mes, int ano, int *diaS, int *mesS, int *anoS) {
    
    if (mes == 3) {  // mes 03
        if (verificaBissexto(ano) == true && dia == 1) { // ano bissexto, dia 01
            *diaS = 29;
            *mesS = 2;
            *anoS = ano; 
        } else if (dia == 1) { // ano não bissexto, dia 01
            *diaS = 28;
            *mesS = 2;
            *anoS = ano;
        } else {
            *diaS = dia - 1;
            *mesS = mes;
            *anoS = ano;
        }
    } else if (mes == 1 && dia == 1) { // primeiro dia do ano
        *diaS = 31;
        *mesS = 12;
        *anoS = ano - 1;

    // meses com anterior = 30
    } else if ((mes == 5 || mes == 7 || mes == 10 || mes == 12) && dia == 1) {
        *diaS = 30;
        *mesS = mes - 1;
        *anoS = ano; 

    // meses com anterior = 31
    } else if ((mes == 2 || mes == 4 || mes == 6 || mes == 8 || mes == 9 || mes == 11) && dia == 1) {
        *diaS = 31;
        *mesS = mes - 1;
        *anoS = ano;    
    } else {
        *diaS = dia - 1;
        *mesS = mes;
        *anoS = ano;
    }
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

#include <stdio.h>
#include <stdlib.h>

void divide(int, int, int *, int *);

int main() {

    int a, b, divisao, resto;
    scanf("%d %d", &a, &b);
    divide(a, b, &divisao, &resto);
    printf("%d %d\n", divisao, resto);

    return 0;
}

void divide(int a, int b, int *ptDiv, int *ptRes) {
    *ptDiv = a / b;
    *ptRes = a % b;
}

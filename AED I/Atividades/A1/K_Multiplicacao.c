#include <stdio.h>

long int multiplica(int, int);

int main() {

    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%ld\n", multiplica(a, b));

    return 0;
}

long int multiplica(int a, int b) {

    long int valor;
    if (b == 1) 
        return(a); 

    else
        valor = (a + multiplica(a, b-1));
    // return a * b;
    return valor;
}

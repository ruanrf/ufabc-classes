#include <stdio.h>

long int soma(long int a, long int b);

int main() {

    long int a, b;
    
    scanf("%ld %ld", &a, &b);
    
    printf("%ld\n", soma(a, b));

    return 0;
}

long int soma(long int a, long int b) {

    if (b == 0) 
        return a;
    
    else
        return(1 + soma(a, --b));
    // return a + b;
}


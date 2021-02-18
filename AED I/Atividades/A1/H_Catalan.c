#include <stdio.h>

long int catalan(int);

int main() {

    int n;
    scanf("%d", &n);

    while (n != -1) {
        printf("%ld\n", catalan(n));
        scanf("%d", &n);
    }

    return 0;
}

long int catalan(int n) {
    // caso base
    if (n <= 1)
    return 1;

    long int res = 0;
    for (int i = 0; i < n; i++){
        res += catalan(i)*catalan(n-i-1);
    }

    return res;
}
#include <stdio.h>

int subtrai(int, int);

int main() {

    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d\n", subtrai(a, b));

    return 0;
}

int subtrai(int a, int b) {

    if (b == 0) 
        return(a); 

    else
        return subtrai(a, b-1) -1;
    // return a - b;
}

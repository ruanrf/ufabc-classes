#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculaRaizes(float, float, float, float *, float *, float *);

int main() {
    
    float a, b, c, r1, r2, delta;
    scanf("%f %f %f", &a, &b, &c);
    calculaRaizes(a, b, c, &r1, &r2, &delta);

    if (delta > 0) {
        printf("%.4f %.4f\n", r1, r2);
    } else if (delta == 0) {
        printf("%.4f\n", r1);
    } else {
        printf("nao ha raiz real\n");
    }
    
    return 0;
}

void calculaRaizes(float a, float b, float c, float *ptr1, float *ptr2, float *delta) {
    *delta = pow(b, 2) - 4 * a * c;

    *ptr1 = (- b + sqrt(*delta)) / (2 * a);
    *ptr2 = (- b - sqrt(*delta)) / (2 * a);

}

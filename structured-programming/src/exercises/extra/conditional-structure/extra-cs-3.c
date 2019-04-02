#include <stdio.h>

void ordemDecrescente(float *x, float *y, float *z) {
    float n1, n2, n3;

    if(*x >= *y && *x >= *z) {
        n1 = *x;

        if(*y >= *z) {
            n2 = *y;
            n3 = *z;
        }
        else {
            n2 = *z;
            n3 = *y;
        }
    }
    else if(*y >= *x && *y >= *z) {
        n1 = *y;

        if(*x >= *z) {
            n2 = *x;
            n3 = *z;
        } else {
            n2 = *z;
            n3 = *x;
        }
    } else {
        n1 = *z;

        if(*x >= *y) {
            n2 = *x;
            n3 = *y;
        }
        else {
            n2 = *y;
            n3 = *x;
        }
    }

    *x = n1;
    *y = n2;
    *z = n3;
}

main() {
    float p, s, t;

    printf("Forneca o primeiro valor: ");
    scanf("%f", &p);

    printf("Forneca o segundo valor: ");
    scanf("%f", &s);

    printf("Forneca o primeiro valor: ");
    scanf("%f", &t);

    ordemDecrescente(&p, &s, &t);

    printf("A ordem crescente dos números e: %.2f, %.2f, %.2f .", p, s, t);
}

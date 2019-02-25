/*
Um número racional possui dois componentes: o numerador e o denominador, representados matematicamente por n/d
Considere dois números racionais x e y, n e , bem como as expressões que refletem:
a adição, a subtração, a multiplicação e a divisão de números racionais, dadas abaixo:

*/
#include <stdio.h>
#include <stdlib.h>

void soma(float nx, float dx, float ny, float dy, float *n, float *d) {
    *n = (nx*dy)+(ny*dx);
    *d = dx*dy;
}

void subtracao(float nx, float dx, float ny, float dy, float *n, float *d) {
    *n = (nx*dy)-(ny*dx);
    *d = dx*dy;
}

void multiplicacao(float nx, float dx, float ny, float dy,  float *n, float *d) {
    *n = nx*ny;
    *d = dx*dy;
}

void divisao(float nx, float dx, float ny, float dy,  float *n, float *d) {
    *n = nx*dy;
    *d = dx*ny;
}

main () {
    float nx, dx, ny, dy, n, d;

    printf("o numerador de x: ");
    scanf("%f", &nx);

    printf("o denominador de x: ");
    scanf("%f", &dx);

    printf("o numerador de y: ");
    scanf("%f", &ny);

    printf("o denominador de y: ");
    scanf("%f", &dy);

    soma(nx, dx, ny, dy, &n, &d);
    printf("\na soma resulta em %.1f/%.1f ", n, d);

    subtracao(nx, dx, ny, dy, &n, &d);
    printf("\na subtracao resulta em %.1f/%.1f ", n, d);

    multiplicacao(nx, dx, ny, dy, &n, &d);
    printf("\na multiplicacao resulta em %.1f/%.1f ", n, d);

    divisao(nx, dx, ny, dy, &n, &d);
    printf("\na divisao resulta em %.1f/%.1f ", n, d);
}

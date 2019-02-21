/*
Uma equação do segundo grau possui a forma Ax2 + Bx + C = 0. 
Crie um módulo para receber os valores de A, B e C e retornar o valor de delta (∆ = B2 – 4AC).
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float calcularDelta(float a, float b, float c) {
    return pow(b, 2)-4*(a*c);
}

main() {
    float a, b, c;

    printf("A: ");
    scanf("%f", &a);

    printf("B: ");
    scanf("%f", &b);

    printf("C: ");
    scanf("%f", &c);

    printf("O resultado e : %f", calcularDelta(a,b,c));

}
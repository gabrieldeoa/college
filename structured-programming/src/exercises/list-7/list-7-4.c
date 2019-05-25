/*
No sistema de coordenadas conhecido como R2, um ponto é definido por um componente que corresponde ao eixo x e outro que corresponde ao eixo y.
Escreva uma definição para um tipo de dado capaz de representar um ponto no R2.
*/
#include <stdio.h>

typedef struct TPonto {
    float x;
    float y;
} Ponto;

main ()  {
    Ponto r2;

    printf("Forneca o valor x do ponto: ");
    scanf("%f", &r2.x);

    printf("Forneca o valor y do ponto: ");
    scanf("%f", &r2.y);

    printf("O valor do ponto e [%f, %f]", r2.x, r2.y);
}

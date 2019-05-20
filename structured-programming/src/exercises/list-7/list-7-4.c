#include <stdio.h>
#include <stdlib.h>

typedef struct TPonto {
    float x;
    float y;
} Ponto;

main ()  {
    Ponto ponto;

    printf("Forneca o valor x do ponto: ");
    scanf("%f", &ponto.x);

    printf("Forneca o valor y do ponto: ");
    scanf("%f", &ponto.y);

    printf("O valor do ponto e [%f, %f]", ponto.x, ponto.y);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct TPonto {
    float x;
    float y;
} Ponto;

Ponto calcularPontoMedio(Ponto pI, Ponto pF) {
    Ponto pM;
    pM.x = (pI.x + pF.x)/2;
    pM.y = (pI.y + pF.y)/2;

    return pM;
}

main ()  {
    Ponto pI, pF, pM;

    printf("Forneca o valor x do ponto inicial: ");
    scanf("%f", &pI.x);

    printf("Forneca o valor y do ponto inicial: ");
    scanf("%f", &pI.y);

    printf("Forneca o valor x do ponto final: ");
    scanf("%f", &pF.x);

    printf("Forneca o valor y do ponto final: ");
    scanf("%f", &pF.y);

    pM = calcularPontoMedio(pI, pF);

    printf("O valor do ponto medio e [%f, %f]", pM.x, pM.y);
}

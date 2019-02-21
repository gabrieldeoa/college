#include <math.h>
#include <stdio.h>

void calcularPontoMedio(float *xInicial, float *yInicial, float xFinal, float yFinal) {
    float xMedio = (*xInicial+xFinal)/2;
    float yMedio = (*yInicial+yFinal)/2;

    *xInicial = xMedio;
    *yInicial = yMedio;
}

main() {
    float xP1, xP2, yP1, yP2;

    printf("Forneca o Primeiro ponto de x: ");
    scanf("%f", &xP1);

    printf("Forneca o Primeiro ponto de y: ");
    scanf("%f", &yP1);

    printf("Forneca o Segundo ponto de x: ");
    scanf("%f", &xP2);

    printf("Forneça o Segundo ponto de y: ");
    scanf("%f", &yP2);

    calcularPontoMedio(&xP1, &yP1, xP2, yP2);

    printf("Os Valores do Ponto Medio sao: \n");
    printf("O x medio: %.2f", xP1);
    printf("\nO y medio: %.2f", yP1);
}

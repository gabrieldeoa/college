
/*
No sistema de coordenadas conhecido como R2, um ponto é constituído de dois componentes: a abscissa indica a sua localização no eixo x
e a ordenada indica a sua localização no eixo y. Um segmento de reta é delimitado por um ponto inicial (xi, yi) e um ponto final (xf, yf).
O ponto médio (xm, ym) de um segmento de reta é calculado pelas seguintes expressões: xM = (xI + xF)/2  e yM = (yI + yF)/2.
Programe um módulo para receber em seus parâmetros os pontos que delimitam um segmento de reta e devolver como resposta o seu ponto médio.
Observe que seu módulo precisa exportar duas informações: a abscissa e a ordenada do ponto médio.
Pense em como resolver esta questão. Em seguida, chame este módulo em um módulo main para testar seu programa.
*/
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

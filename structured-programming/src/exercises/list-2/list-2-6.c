/*
Dois pontos A e B são definidos como (xa, ya) e (xb, yb). A distância entre estes pontos é dada por sqrt((xa - xb)²+(ya - yb)²).
Escreva um módulo para receber dois pontos e retornar a distância entre eles.
Repare que, para cada ponto, seu módulo deve receber dois dados.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float calcularDistanciaEntreDoisPontos(float xA, float yA, float xB, float yB) {
    float distanciaX = pow((xA-xB), 2);
    float distanciaY = pow((yA-yB), 2);

    return sqrt(distanciaX+distanciaY);
}

main() {
    float xA, yA, xB, yB, resultado;

    printf("Calculado a distancia entre dois pontos:\n");

    printf("Forneca o valor X do ponto A: ");
    scanf("%f", &xA);

    printf("Forneca o valor Y do ponto A: ");
    scanf("%f", &yA);


    printf("Forneca o valor X do ponto B: ");
    scanf("%f", &xB);

    printf("Forneca o valor Y do ponto B: ");
    scanf("%f", &yB);

    resultado = calcularDistanciaEntreDoisPontos(xA, yA, xB, yB);

    printf("\nA distancia entre o ponto A e o B é: %.2f", resultado);


}

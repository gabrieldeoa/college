/*
O volume de uma esfera é dado pela seguinte expressão:
 V = (4/3*pi)*R³,onde V é o volume e R é o raio da esfera.
Crie um módulo para receber o raio da esfera e retornar o seu volume.
Use a constante 3,141592 para o valor de PI.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularVolumeEsfera(float raio) {
    const float PI = 3.141592;
    return (4*PI*pow(raio, 3))/3;
}

main() {
    float raio;

    printf("Forneça o raio da esfera: ");
    scanf("%f", &raio);

    printf("O Volume da esfera de raio %.2f é %.2f", raio, calcularVolumeEsfera(raio));
}

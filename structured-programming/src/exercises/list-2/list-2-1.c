/*
A conversão de um ângulo medido em graus para um ângulo medido em radianos obedece à esta equação:
R = (pi*G)/180 onde R é o ângulo em radianos e G é o ângulo em graus. 
Crie um módulo para receber o ângulo medido em graus e retornar o ângulo medido em radianos. 
Use a constante 3,141592 para o valor de . 
Para definir uma constante, use a seguinte sintaxe: 
    const tipoDaConstante nomeDaConstante = valorDaConstante;
Em seguida, chame este módulo a partir de um módulo main para testar seu programa. 
*/

#include <stdio.h>

float grausParaRadianos(float graus) {
    float radianos;
    const float PI = 3.141592;
    radianos = (PI*graus)/180;
    return radianos;
}

main() {
    float graus, radianos;

    printf("Angulo em graus: ");
    scanf("%f", &graus);

    radianos = grausParaRadianos(graus);

    printf("Angulo em radianos: %f", radianos);
}

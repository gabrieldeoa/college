
/*
Crie um módulo para receber as medidas de dois lados de um triângulo e o ângulo formado entre eles.
Este módulo deve retornar a área do triângulo, respeitando a expressão:
A = (a*b*sen(teta))/2 onde a e b são as medidas dos lados,  é o ângulo formado entre estes lados, e A é a área do triângulo. 
Chame este módulo a partir de um módulo main para testar seu programa. 
Use os valores 3 e 4 para as medidas dos lados e 90 graus para o ângulo. 
Se a sua programação estiver correta, seu programa deve apresentar o valor 6 como resultado. 
No entanto, função sin, da biblioteca math.h, espera receber um ângulo em radianos em seu parâmetro para retornar o seno deste ângulo.
Chame o módulo que você programou no exercício anterior para realizar a conversão necessária.
*/

#include <math.h>
#include <stdio.h>

float grausParaRadianos(float graus) {
    float radianos;
    const float PI = 3.141592;
    radianos = (PI*graus)/180;
    return radianos;
}

float calcularAreaDoTriangulo(float ladoA, float ladoB, float graus) {
    float radianos;

    radianos = grausParaRadianos(graus);

    return (ladoA * ladoB * sin(radianos))/2;

}

// a =  3 b = 4 angulo = 90 resposta 6
main() {
    float graus, ladoA, ladoB;

    printf("Forneça o Lado A: ");
    scanf("%f", &ladoA);

    printf("Forneça o Lado B: ");
    scanf("%f", &ladoB);

    printf("Forneça o Angulo em graus: ");
    scanf("%f", &graus);

    printf("A area do Triangulo é: %f", calcularAreaDoTriangulo(ladoA, ladoB, graus));
}

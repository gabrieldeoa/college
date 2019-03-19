/*
O Índice de Massa Corpórea (IMC) indica o grau de obesidade de um paciente.
A tabela a seguir ilustra os diferentes níveis de obesidade em que uma pessoa pode se encontrar:
 
IMC (kg/m2)
Tipo de obesidade 
< 25 Ausente
≥ 25 e < 30 Sobrepeso
≥ 30 e < 35 Obesidade Grau I
≥ 35 e < 40 Obesidade Grau II
≥ 40 Obesidade Mórbida

O Índice de Massa Corpórea é calculado pela expressão .
Programe um módulo para receber em seus parâmetros o o peso e a altura de uma pessoa para retornar:
    0, para ausente de obesidade;
    1, para sobrepeso;
    2, para obesidade grau 1;
    3, para obesidade grau 2;
    4, para obesidade mórbida. 
Em seguida, a partir de um módulo main, peça para o usuário fornecer seu peso e sua altura para
, em seguida, conhecer seu tipo de obesidade.
*/
#include <stdio.h>

int calcularIMC(float peso, float altura) {
    float imc = peso/(altura*altura);
    if (imc >= 25.0 && imc < 30.0) return 1;
    else if(imc >= 30.0 && imc < 35.0) return 2;
    else if (imc >= 35.0 && imc < 40.0) return 3;
    else if (imc >= 40.0) return 4;
    else return 0;
}

main() {
    float p, a;
    int imc;

    printf("Forneca o seu peso em quilos (ex: 89.00): ");
    scanf("%f", &p);

    printf("\nForneca sua altura em metros (ex: 1.75): ");
    scanf("%f", &a);

    imc = calcularIMC(p, a);
    printf("Seu tipo de obsidade e: ");

    switch (imc){
        case 1:
            printf(" Sobrepeso.");
            break;
        case 2:
            printf(" Obesidade 1 grau.");
            break;
        case 3:
            printf(" Obesidade 2 grau.");
            break;
        case 4:
            printf(" Obesidade morbida.");
            break;
        default:
            printf(" Ausente.");
            break;
    }


}

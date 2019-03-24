#include <stdio.h>

float contaTelefonica(int minutos, float valorMinuto, float valorAssinatura) {
    float total = minutos * valorMinuto;

    return (total < valorAssinatura) ? valorAssinatura : total;
}

main() {
    int min;
    float vMin, vAss;

    printf("Forneca a quantidade de minutos: ");
    scanf("%d", &min);

    printf("\nForneca o valor do minuto: ");
    scanf("%f", &vMin);

    printf("\nForneca o valor da assinatura: ");
    scanf("%f", &vAss);

    printf("O valor da conta mensal e %.2f", contaTelefonica(min, vMin, vAss));
}

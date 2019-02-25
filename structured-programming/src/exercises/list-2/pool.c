#include <stdlib.h>
#include <stdio.h>

void areaVolume(float *profundidade, float *comprimento, float largura) {
    float volume = *profundidade * *comprimento * largura;
    float area = *comprimento * largura;

    *profundidade = volume;
    *comprimento = area;
}

main () {
    float comprimento, largura, profundidade;

    printf("Forneca a pronfundidade da piscina: ");
    scanf("%f", &profundidade);

    printf("Forneca o comprimento da piscina: ");
    scanf("%f", &comprimento);

    printf("Forneca a largura da piscina: ");
    scanf("%f", &largura);


    areaVolume(&profundidade, &comprimento, largura);

    printf("O volume de agua da piscina e %f e a area de piso a ser trocado e %f", profundidade, comprimento);
}

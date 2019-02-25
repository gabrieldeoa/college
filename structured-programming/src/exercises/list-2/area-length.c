#include <stdlib.h>
#include <stdio.h>

void areaPerimetro(float *comprimento, float *largura) {
    float area = *comprimento**largura;
    float perimetro = (*comprimento*2)+(*largura*2);

    *comprimento = area;
    *largura = perimetro;
}

main () {
    float comprimento, largura;

    printf("Forneca o comprimento do comodo: ");
    scanf("%f", &comprimento);

    printf("Forneca a largura do comodo: ");
    scanf("%f", &largura);

    areaPerimetro(&comprimento, &largura);

    printf("A areaa do comodo e %f e seu perimetro e %f", comprimento, largura);
}

#include <stdio.h>

int triangulo(float ladoA, float ladoB, float ladoC) {
    return (ladoA+ladoB+ladoC == 180);
}

int tipoTriangulo(float ladoA, float ladoB, float ladoC) {
    if(!triangulo(ladoA, ladoB, ladoC))
        return 0;
    else if(ladoA == 90.0 || ladoB == 90.0 || ladoC == 90.0)
        return 1;
    else if (ladoA > 90.0 || ladoB > 90.0 || ladoC > 90.0)
        return 2;
    else
        return 3;
}

main() {
    float a, b, c;

    printf("Forneca os 3 valores dos lados do triangulo em graus: ");

    printf("\nLado A: ");
    scanf("%f", &a);

    printf("\nLado B: ");
    scanf("%f", &b);

    printf("\nLado C: ");
    scanf("%f", &c);

    switch(tipoTriangulo(a,b,c)) {
        case 0: printf("\nNao e triangulo.");
            break;
        case 1: printf("\nTriangulo do tipo: Retangulo");
            break;
        case 2: printf("\nTriangulo do tipo: Obtusangulo");
            break;
        case 3: printf("\nTriangulo do tipo: Acutangulo");
            break;
    }
}

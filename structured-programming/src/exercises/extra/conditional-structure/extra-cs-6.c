#include <stdio.h>
#include <math.h>

int equacaoSegundoGrau(float a, float b, float c, float *t1, float *t2 ) {
    float delta = b*b - 4*a*c;

    // termo 1 comum em todas as possibilidades
    *t1 = -b/(2*a);

    if(delta > 0) {
        // termo 2
        *t2 = sqrt(delta)/(2*a);
        // qtd raizes
        return 2;
    }
    else if(delta == 0) {
        // sem termo 2
        //qtd raizes
        return 1;
    }
    else { // delta < 0

        //termo 2
        *t2 = sqrt(-delta)/(2*a);
        // qtd raizes
        return 0;
    }
}

main() {
    float a, b, c, t1, t2;
    int resultado;

    printf("Forneça os dados para a equação de segundo grau: ");

    printf("\nA: ");
    scanf("%f", &a);

    printf("\nB: ");
    scanf("%f", &b);

    printf("\nC: ");
    scanf("%f", &c);

    resultado = equacaoSegundoGrau(a, b, c, &t1, &t2);

    switch(resultado) {
        case 0: printf("\nPossui 2 raizes complexas:");
                printf("\nx1 = %f - i%f", t1, t2);
                printf("\nx2 = %f + i%f", t1, t2);
                break;
        case 1: printf("\nPossui 1 raiz real:");
                printf("\nx1 = %f", t1);
                break;
        case 2: printf("\nPossui 2 raizes reias:");
                printf("\nx1 = %f - %f", t1, t2);
                printf("\nx1 = %f + %f", t1, t2);
    }
}

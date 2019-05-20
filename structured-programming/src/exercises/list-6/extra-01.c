/*
Cria um modulo para receber dois vetores distintos do mesmo tamanho e somar os elementos
de mesmo indice para um terceiro
*/

#include <stdio.h>
#include <stdlib.h>

void requisitarValoresVetor(int *v, int col) {
    int i;
    for(i = 0; i < col; i++) {
        printf("\nForneca o valor da posicao %d: ", i);
        scanf("%d", &v[i]);
    }
    printf("\n");
}

void escreverVetor(int *v, int col) {
    int i;
    for(i = 0; i < col; i++) {
        printf("[%d]", v[i]);
    }
    printf("\n");
}

void somaVetor(int *v1, int *v2, int *v3, int col) {
    int i;

    for(i = 0; i < col; i++) {
        v3[i] = v1[i] + v2[i];
    }
}


main() {
    int const tam = 3;

    int *v1 = (int *)malloc(sizeof(int[tam]));
    int *v2 = (int *)malloc(sizeof(int[tam]));
    int *v3 = (int *)malloc(sizeof(int[tam]));

    requisitarValoresVetor(v1, tam);
    requisitarValoresVetor(v2, tam);

    somaVetor(v1, v2, v3, tam);

    escreverVetor(v1, tam);
    escreverVetor(v2, tam);

    printf("\nOs vetores acimas somas resulta em:\n");
    escreverVetor(v3, tam);

    free(v1);
    free(v2);
    free(v3);
}




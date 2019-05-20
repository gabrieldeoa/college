/*
Dado um vetor com um determinado tamanho gerar um outro com valores invertidos.
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

void inverteVetor(int *v1, int *v2, int col) {
    int i, j = col;
    for(i = 0; i < col; i++){
        j--;
        v2[j] = v1[i];
    }
}

main() {
    const int col = 3;
    int * v1 = (int *)malloc(sizeof(int[col]));
    int * v2 = (int *)malloc(sizeof(int[col]));

    requisitarValoresVetor(v1, col);
    escreverVetor(v1, col);

    inverteVetor(v1, v2, col);

    escreverVetor(v2, col);

    free(v1);
    free(v2);
}






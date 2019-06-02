/*
Escreva duas funções para receber por parâmetro um vetor de números e devolver uma coleção
que armazene cada elemento deste vetor multiplicado pelo seu índice.
Escreva uma função recebendo um arranjo e outra recebendo um ponteiro.
Em seguida, chame estes módulos a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

void escreverVetor(int v[], int colunas) {
    for(int i = 0; i < colunas; i++)
        printf("[%d]", v[i]);

    printf("\n");
}

void multiplicarIndicePorValor(int v[], int colunas) {
    for(int i = 0; i < colunas; i++)
        v[i] = v[i] * i;
}

void multiplicarIndicePorValorPonteiro(int *vP, int colunas) {
    for(int i = 0; i < colunas; i++)
        vP[i] = vP[i] * i;
}

main() {
    int colunas;

    printf("Forneca a quantidade de colunas do vetor: ");
    scanf("%d", &colunas);

    int v[colunas];
    int *vP = (int *)malloc(sizeof(int[colunas]));

    for(int i = 0; i < colunas; i++) {
        printf("Valor da posição %d: ", i);
        scanf("%d", &v[i]);
        vP[i] = v[i];
    }

    printf("\nVetores inicialmente:");

    printf("\nv:");
    escreverVetor(v, colunas);

    printf("\nvP:");
    escreverVetor(vP, colunas);

    multiplicarIndicePorValor(v, colunas);
    multiplicarIndicePorValorPonteiro(vP, colunas);

    printf("\nVetores multiplicando posicao pelo valor:");

    printf("\nv: ");
    escreverVetor(v, colunas);

    printf("\nvP:");
    escreverVetor(vP, colunas);

    free(vP);
}

/*
Escreva duas funções para ordenar um vetor de números de forma crescente.
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

void vetorOrdemCrescente(int v[], int colunas) {
    int aux, i, j;

    for(i = 0;i < colunas - 1; i++) {
        for(j = 0; j < colunas - 1 - i; j++) {
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void vetorOrdemDecrescente(int v[], int colunas) {
    int aux, i, j;

    for(i = 0;i < colunas - 1; i++) {
        for(j = 0; j < colunas - 1 - i; j++) {
            if(v[j] < v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void vetorOrdemCrescentePonteiro(int *vP, int colunas) {
    int aux, i, j;

    for(i = 0;i < colunas - 1; i++) {
        for(j = 0; j < colunas - 1 - i; j++) {
            if(vP[j] > vP[j + 1]){
                aux = vP[j];
                vP[j] = vP[j + 1];
                vP[j + 1] = aux;
            }
        }
    }
}

void vetorOrdemDecrescentePonteiro(int *vP, int colunas) {
    int aux, i, j;

    for(i = 0;i < colunas - 1; i++) {
        for(j = 0; j < colunas - 1 - i; j++) {
            if(vP[j] < vP[j + 1]){
                aux = vP[j];
                vP[j] = vP[j + 1];
                vP[j + 1] = aux;
            }
        }
    }
}

main() {
    int colunas = 5;

    int v[] = {3, 5, 1, 2, 4};
    int *vP = (int *)malloc(sizeof(int[colunas]));

    vP[0] = 10;
    vP[1] = 6;
    vP[2] = 9;
    vP[3] = 8;
    vP[4] = 7;

    printf("Vetor v:");
    escreverVetor(v, colunas);

    printf("Vetor v ordem crescente: \n");
    vetorOrdemCrescente(v, colunas);
    escreverVetor(v, colunas);

    printf("Vetor v ordem decrescente: \n");
    vetorOrdemDecrescente(v, colunas);
    escreverVetor(v, colunas);


    printf("\n\nVetor vP:");
    escreverVetor(vP, colunas);

    printf("Vetor vP ordem crescente: \n");
    vetorOrdemCrescentePonteiro(vP, colunas);
    escreverVetor(vP, colunas);

    printf("Vetor vP ordem decrescente: \n");
    vetorOrdemDecrescentePonteiro(vP, colunas);
    escreverVetor(vP, colunas);

    free(vP);
}


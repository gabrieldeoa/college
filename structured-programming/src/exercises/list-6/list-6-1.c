/*
Escreva duas funções para inverter um vetor, substituindo as posições dos seus elementos.
O primeiro elemento do vetor será deslocado para o último índice do vetor,
o segundo elemento do vetor será deslocado para o penúltimo índice do vetor, e assim por diante.
Escreva uma função recebendo um arranjo e outra recebendo um ponteiro.
Em seguida, chame estes módulos a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

void escreverVetor(int vetor[], int colunas) {
    for(int i = 0; i < colunas; i++)
        printf("[%d]", vetor[i]);

    printf("\n");
}

void inverteVetor(int v[], int colunas) {
    int i = colunas-1;
    int x = 0;
    int aux = 0;

    for(i; i >= (colunas/2); i--) {
        aux = v[i];
        v[i] = v[x];
        v[x] = aux;
        x = x + 1;
    }
}

void inverteVetorPonteiro(int *vP, int colunas) {
    int i = colunas-1;
    int x = 0;
    int aux = 0;

    for(i; i >= (colunas/2); i--) {
        aux = vP[i];
        vP[i] = vP[x];
        vP[x] = aux;
        x = x + 1;
    }
}

main() {
    int colunas;

    printf("Forneca o numero de colunas do vetor: ");
    scanf("%d", &colunas);

    int v[colunas];
    int *vP = (int *)malloc(sizeof(int[colunas]));

    for(int i = 0; i < colunas; i++) {
        printf("Forneca o elemento da posição %d do vetor: ", i);
        scanf("%d", &v[i]);
        vP[i] = v[i];
    }

    printf("\n\nVetor inicial: \n");
    escreverVetor(v, colunas);

    printf("Vetor inicial com ponteiro: \n");
    escreverVetor(vP, colunas);

    inverteVetor(v, colunas);
    inverteVetor(vP, colunas);

    printf("\n\nVetor invertido: \n");
    escreverVetor(v, colunas);

    printf("Vetor invertido com ponteiro: \n");
    escreverVetor(vP, colunas);

    free(vP);
}


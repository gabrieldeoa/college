/*
Escreva duas funções para retornar o maior número presente em um vetor recebido por parâmetro.
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

int maiorElementoVetor(int v[], int colunas) {
    int maior = v[0];

    for(int i = 0; i < colunas; i++) {
        if(v[i] > maior)
            maior = v[i];
    }
    return maior;
}

int maiorElementoVetorPonteiro(int *vP, int colunas) {
    int maior = vP[0];

    for(int i = 0; i < colunas; i++) {
        if(vP[i] > maior)
            maior = vP[i];
    }
    return maior;
}

main() {
    int colunas;

    printf("Colunas: ");
    scanf("%d", &colunas);

    int v[colunas];
    int *vP = (int *)malloc(sizeof(int[colunas]));

    for(int i = 0; i < colunas; i++) {
        printf("Valor da posição %d: ", i);
        scanf("%d", &v[i]);
        vP[i] = v[i];
    }

    printf("\nv:");
    escreverVetor(v, colunas);

    printf("\nvP:");
    escreverVetor(vP, colunas);

    printf("\nO maior elemento de v[] é: %d\n", maiorElementoVetor(v, colunas));
    printf("maior elemento de vP[] é: %d\n", maiorElementoVetorPonteiro(vP, colunas));

    free(vP);
}

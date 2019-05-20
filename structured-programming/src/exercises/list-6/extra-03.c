/*
Cria dois vetores de um determinado tamanho, e ordeneos alternadamente entre os vetores em um terceiro com o dobro do tamanho.
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

void altenaVetor(int *v1, int *v2, int *v3, int col) {
    int i = 0, j = 0, k =0;

    for(i; i < col * 2; i++) {
        if(i % 2 == 0) {
            v3[i] = v1[j];
            j++;
        }
        else { 
            v3[i] = v2[k];
            k++;
        }
    }
}


main() {
    int const tam = 3;
    int const dobro = tam*2;

    int *v1 = (int *)malloc(sizeof(int[tam]));
    int *v2 = (int *)malloc(sizeof(int[tam]));
    int *v3 = (int *)malloc(sizeof(int[dobro]));

    requisitarValoresVetor(v1, tam);
    requisitarValoresVetor(v2, tam);

    escreverVetor(v1, tam);
    escreverVetor(v2, tam);

    altenaVetor(v1, v2, v3, dobro);
    printf("\nOs vetores acimas somas resulta em:\n");
    escreverVetor(v3, dobro);

    free(v1);
    free(v2);
    free(v3);
}




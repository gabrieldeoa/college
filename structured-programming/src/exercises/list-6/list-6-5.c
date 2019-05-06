/*
Escreva uma função para receber uma matriz de números através de ponteiros e retornar a média aritmética destes números.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

float mediaMatriz(int **m, int linha, int coluna) {
    int i, j;
    float somatorio = 0;

    for(i = 0; i < linha; i++) {
        for(j=0; j < coluna; j++){
            somatorio = somatorio + m[i][j];
        }
    }

    return somatorio/(linha*coluna);
}

void escreverMatriz(int **m, int linha, int coluna) {
    int i, j;

    for(i = 0; i < linha; i++) {
        for(j=0; j < coluna; j++){
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void preencherMatriz(int **m, int linha, int coluna) {
    int i, j;

    for(i = 0; i < linha; i++) {
        for(j=0; j < coluna; j++){
            m[i][j] = i + j;
        }
    }
}

main() {
    int **matriz;
    const int linha = 3;
    const int coluna = 3;

    int i, j;
    float media;

    // --- Criando Matriz
    matriz = (int **)malloc(sizeof(int*[linha]));
    for(i = 0; i < linha; i++) {
        matriz[i] = (int *)malloc(sizeof(int[coluna]));
    }
    // ---

    preencherMatriz(matriz, linha, coluna);
    escreverMatriz(matriz, linha, coluna);

    media = mediaMatriz(matriz, linha, coluna);

    printf("A media dos elementos da matriz é %f", media);

    // --- Liberando memória
    for(i = 0; i < linha; i ++)
        free(matriz[i]);
    free(matriz);

}

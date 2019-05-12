/*
*/

#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"


int bispo(int xi, int yi, int xf, int yf) {
    return ( movimentoValido(xi, yi, xf, yf) && (xi + yi == xf + yf || xi - xf ==  yi - yf));
}

main() {
    int xI, xF, yI, yF;
    const int linhas = 8, colunas = 8;

    // -- Criando Matriz
    int **m = (int **)malloc(sizeof(int*[linhas]));
    for(int i = 0; i < linhas; i++) {
        m[i] = (int *)malloc(sizeof(int[colunas]));
    }
    //

    preencherMatrizXadrez(m, linhas, colunas);

    printf("Posicao inicial de x: ");
    scanf("%d", &xI);

    printf("Posicao inicial de y: ");
    scanf("%d", &yI);

    printf("\nPosicao inicial da peca (1): ");
    prencherPosicao(m, linhas, colunas, xI, yI, 1);
    escreverMatriz(m, linhas, colunas);

    printf("Posicao a qual ira mover a peca, x: ");
    scanf("%d", &xF);

    printf("Posicao Posicao a qual ira mover a peca, y: ");
    scanf("%d", &yF);

    if(bispo(xI, yI, xF, yF)) {
        printf("\nO movimento e possivel, segue onde a peca ira (2)");
        prencherPosicao(m, linhas, colunas, xF, yF, 2);
        escreverMatriz(m, linhas, colunas);

    } else {
        printf("\nO movimento nao e permitido");

    }
}


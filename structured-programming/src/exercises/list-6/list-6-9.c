/*
Mais uma sobre o jogo de xadrez: O cavalo é uma peça que se movimenta em L.
Entenda este L como os cantos opostos da diagonal de um retângulo 3x2.
Escreva uma função para verificar se duas posições do tabuleiro podem ser a origem e o destino de um movimento do cavalo e retornar verdadeiro ou falso.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"


int cavalo(int xi, int yi, int xf, int yf) {
    if(!movimentoValido(xi, yi, xf, yf)) return 0;

    return (((xf == xi + 2 || xf == xi - 2 ) && (yf == yi + 1 || yf == yi - 1)) || ((xf == xi + 1 || xf == xi - 1) && (yf == yi + 2 || yf == yi - 2)));
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

    if(cavalo(xI, yI, xF, yF)) {
        printf("\nO movimento e possivel, segue onde a peca ira (2)");
        prencherPosicao(m, linhas, colunas, xF, yF, 2);
        escreverMatriz(m, linhas, colunas);

    } else {
        printf("\nO movimento nao e permitido");

    }
}


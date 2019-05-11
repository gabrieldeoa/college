/*
No jogo de xadrez, a torre é uma peça que se movimenta apenas horizontal ou verticalmente.
Este jogo é disputado em um tabuleiro de 8 linhas e 8 colunas.
Escreva uma função para verificar se duas posições do tabuleiro podem ser a origem e o destino de um movimento da torre e retornar verdadeiro ou falso.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"


int torre(int xi, int yi, int xf, int yf) {
    return ( yi == yf || xi == xf);
}

prencherPosicao(int **m, int linhas, int colunas, int x, int y, int marcador) {
    int i, j;
    for(i = 0; i < linhas; i++) {
        for(j=0; j < colunas; j++){
            if(i == x && j == y) {
                m[i][j] = marcador;
            }
        }
    }
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

    printf("\nPosição inicial da peça (posição representada pelo numero 1): ");
    prencherPosicao(m, linhas, colunas, xI, yI, 1);
    escreverMatriz(m, linhas, colunas);

    printf("Posicao a qual ira mover a peca, x: ");
    scanf("%d", &xF);

    printf("Posicao Posicao a qual ira mover a peca, y: ");
    scanf("%d", &yF);

    if(torre(xI, yI, xF, yF)) {
        printf("\nO movimento é possivel, segue onde a peca irá (posição representada pelo numero 2)");
        prencherPosicao(m, linhas, colunas, xF, yF, 2);
        escreverMatriz(m, linhas, colunas);

    } else {
        printf("\nO movimento não permitido");

    }
}


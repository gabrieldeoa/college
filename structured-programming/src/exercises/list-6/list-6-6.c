/*
Escreva uma função para receber uma matriz de números através de ponteiros e ordená-la linha a linha,
de tal forma que o menor elemento ficará na primeira coluna da primeira linha
e o maior elemento ficará na última coluna da última linha.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"

void ordenarMatriz(int *v, int **m, int linhas, int colunas) {
    copiarMatrizParaVetorPonteiro(v, m, linhas, colunas);
    vetorOrdemCrescentePonteiro(v, linhas*colunas);
    copiarVetorParaMatrizPonteiro(v, m, linhas, colunas);
}

main() {
    int **m;

    int const linhas = 4, colunas = 4;

    int *v = (int *)malloc(sizeof(int[linhas*colunas]));

    int c = 1;

    //-- Criando matriz
    m = (int **)malloc(sizeof(int*[linhas]));
    for(int i = 0; i < linhas; i++) {
        m[i] = (int *)malloc(sizeof(int[colunas]));
    }
    //

    requisistarPrenchimentoMatriz(m, linhas, colunas);

    printf("\nMatriz inicial: ");
    escreverMatriz(m, linhas, colunas);

    ordenarMatriz(v, m, linhas, colunas);

    printf("\nMatriz ordenada: ");
    escreverMatriz(m, linhas, colunas);


    //-- Liberando memória
    free(v);
    
    for(int i = 0; i < linhas; i ++)
        free(m[i]);
    free(m);



}

#include <stdlib.h>

void escreverMatriz(int **m, int linhas, int colunas) {
    int i, j;

    printf("\n");
    for(i = 0; i < linhas; i++) {
        for(j=0; j < colunas; j++){
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void preencherMatrizSequencial(int **m, int linhas, int colunas) {
    int i, j;
    for(i = 0; i < linhas; i++) {
        for(j=0; j < colunas; j++){
            m[i][j] = i + j;
        }
    }
}

void preencherMatrizXadrez(int **m, int linhas, int colunas) {
    int i, j;
    for(i = 0; i < linhas; i++) {
        for(j=0; j < colunas; j++){
            m[i][j] = 0;
        }
    }
}

void requisistarPrenchimentoMatriz(int **m, int linhas, int colunas) {
    int i, j, c = 1;

    printf("Forneca os %d elementos da matriz: ", linhas*colunas);
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("\nForneca o %d° elemento : ", c);
            scanf("%d", &m[i][j]);
            c++;
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

void copiarMatrizParaVetorPonteiro(int *v, int **m, int linhas, int colunas) {
    int i, j, k = 0;

    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            v[k] = m[i][j];
            k++;
        }
    }
}

void copiarVetorParaMatrizPonteiro(int *v, int **m, int linhas, int colunas) {
    int i, j, k = 0;

    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            m[i][j]= v[k];
            k++;
        }
    }
}


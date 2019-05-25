#include <stdio.h>
#include <stdlib.h>

typedef enum TELEMENTO { peao = 1, bispo, cavalo, torre, rainha, rei } TElemento;

typedef enum TCOR { branco = -1, preto = 1 } TCor;

typedef struct TPECA {
    TElemento elemento;
    TCor cor;
} TPeca;

// 1)
typedef struct TJOGO {
    TPeca tabuleiro[8][8];
    TPeca reinoPreto[16];
    TPeca reinoBranco[16];
} TJogo;

// 2)
void inicializarTabuleiro(TJogo *jogo, int lin, int col) {
    TPeca pecaNula;
    pecaNula.elemento = 0;
    pecaNula.cor = 0;

    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            jogo->tabuleiro[i][j] = pecaNula;
        }
    }
}

void inicializarReinos(TJogo *jogo, int lin) {
    TPeca pecaBranca, pecaPreta;
    pecaBranca.cor = branco;
    pecaPreta.cor =  preto;

    for(int i = 0; i < lin*2; i++) {

        // peao
        if(i < 8) {
            pecaBranca.elemento = pecaBranca.elemento = peao;
            pecaPreta.elemento = pecaPreta.elemento = peao;
        }

        // bispo
        if(i >= 8 && i <= 9) {
            pecaBranca.elemento = pecaBranca.elemento = bispo;
            pecaPreta.elemento = pecaPreta.elemento = bispo;
        }

        // cavalo
        if(i >= 10 && i <= 11) {
            pecaBranca.elemento = pecaBranca.elemento = cavalo;
            pecaPreta.elemento = pecaPreta.elemento = cavalo;
        }

        // torre
        if(i >= 12 && i <= 13) {
            pecaBranca.elemento = pecaBranca.elemento = torre;
            pecaPreta.elemento = pecaPreta.elemento = torre;
        }

        // rei
        if(i == 14) {
            pecaBranca.elemento = pecaBranca.elemento = rei;
            pecaPreta.elemento = pecaPreta.elemento = rei;
        }

        // rainha
        if(i == 15) {
            pecaBranca.elemento = pecaBranca.elemento = rainha;
            pecaPreta.elemento = pecaPreta.elemento = rainha;
        }

        jogo->reinoBranco[i] = pecaBranca;
        jogo->reinoPreto[i] = pecaPreta;
    }
}

void criarJogo(TJogo *jogo, int lin, int col) {
    inicializarReinos(jogo, lin);
    inicializarTabuleiro(jogo, lin, col);
}

//3)
void iniciarJogo(TJogo *jogo, int lin, int col) {
    TPeca pecaNula;
    pecaNula.elemento = 0;
    pecaNula.cor = 0;

    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            //peao preto
            if(i == 1) {
                jogo->tabuleiro[i][j] = jogo->reinoPreto[j];
            }
            //peao branco
            if(i == 6) {
                jogo->tabuleiro[i][j] = jogo->reinoBranco[j];
            }

            //torre
            if(jogo->reinoPreto[12].elemento == torre) {
                jogo->tabuleiro[0][0] = jogo->reinoPreto[12];
                jogo->tabuleiro[0][7] = jogo->reinoPreto[12];
            }

            if(jogo->reinoBranco[12].elemento == torre) {
                jogo->tabuleiro[7][0] = jogo->reinoBranco[12];
                jogo->tabuleiro[7][7] = jogo->reinoBranco[12];
            }

            //cavalo
            if(jogo->reinoPreto[10].elemento) {
                jogo->tabuleiro[0][1] = jogo->reinoPreto[10];
                jogo->tabuleiro[0][6] = jogo->reinoPreto[10];
            }

            if(jogo->reinoBranco[10].elemento == cavalo) {
                jogo->tabuleiro[7][1] = jogo->reinoBranco[10];
                jogo->tabuleiro[7][6] = jogo->reinoBranco[10];
            }

            //bispo
            if(jogo->reinoPreto[8].elemento == bispo) {
                jogo->tabuleiro[0][2] = jogo->reinoPreto[8];
                jogo->tabuleiro[0][5] = jogo->reinoPreto[8];
            }

            if(jogo->reinoBranco[8].elemento == bispo) {
                jogo->tabuleiro[7][2] = jogo->reinoBranco[8];
                jogo->tabuleiro[7][5] = jogo->reinoBranco[8];
            }

            // rainha
            if(jogo->reinoPreto[15].elemento == rainha) {
                jogo->tabuleiro[0][4] = jogo->reinoPreto[15];
            }

            if(jogo->reinoBranco[15].elemento == rainha) {
                jogo->tabuleiro[7][4] = jogo->reinoBranco[15];
            }

            // rei
            if(jogo->reinoPreto[14].elemento == rei) {
                jogo->tabuleiro[0][3] = jogo->reinoPreto[14];
            }

            if(jogo->reinoBranco[14].elemento == rei) {
                jogo->tabuleiro[7][3] = jogo->reinoBranco[14];
            }
        }
    }

    for(int i = 0; i < lin; i++) {
        jogo->reinoBranco[i] = pecaNula;
        jogo->reinoPreto[i] = pecaNula;
    }

}

int valor(TPeca peca){
    return (peca.elemento * peca.cor);
}

void escreveJogo(TJogo *jogo, int lin, int col) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            printf("[%2d]", valor(jogo->tabuleiro[i][j]));
        }
        printf("\n");
    }
}

main() {
    int const  COL = 8, LIN = 8;
    TJogo jogo;
    criarJogo(&jogo, LIN, COL);
    iniciarJogo(&jogo, LIN, COL);
    escreveJogo(&jogo, LIN, COL);
}
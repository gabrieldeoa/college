#include <stdio.h>
#include <stdlib.h>

typedef enum TColuna { A = 1, B, C, D, E, F, G, H } Coluna;
typedef enum TLinha { um = 1, dois, tres, quatro, cinco, seis, sete, oito} Linha;

typedef struct TTabuleiro {
    Coluna coluna;
    Linha linha;
} Tabuleiro;

char* ColunaParaTexto(Coluna col) {
    switch(col) {
        case A: return "A";
        case B: return "B";
        case C: return "C";
        case D: return "D";
        case E: return "E";
        case F: return "F";
        case G: return "G";
        case H: return "H";
    }
}

char* LinhaParaTexto(Linha lin) {
    switch(lin) {
        case um: return "um";
        case dois: return "dois";
        case tres: return "tres";
        case quatro: return "quatro";
        case cinco: return "cinco";
        case seis: return "seis";
        case sete: return "sete";
        case oito: return "oito";
    }
}

Coluna CharParaColuna(char c) {
    switch(c) {
        case 'a':
        case 'A': return A;
        case 'b':
        case 'B': return B;
        case 'c':
        case 'C': return C;
        case 'd':
        case 'D': return D;
        case 'e':
        case 'E': return E;
        case 'f':
        case 'F': return F;
        case 'g':
        case 'G': return G;
        case 'h':
        case 'H': return H;
    }
}

Linha InteiroParaColuna(int i) {
    switch(i) {
        case 1: return um;
        case 2: return dois;
        case 3: return tres;
        case 4: return quatro;
        case 5: return cinco;
        case 6: return seis;
        case 7: return sete;
        case 8: return oito;
    }
}

main() {
    Tabuleiro tabuleiro;
    int l;
    char c;

    printf("Informe a Linha entre 1 e 8: ");
    scanf("%d", &l);

    printf("Informe a Coluna entre a e h: ");
    scanf("\n%c", &c);

    if((l < 1 || l > 8) || ((c < 'a' || c > 'h') && ( c < 'A' || c > 'H'))) {
        printf("Posição inválida !!");
    } else {
        tabuleiro.linha = InteiroParaColuna(l);
        tabuleiro.coluna = CharParaColuna(c);

        printf(
            "A posição escolhida é coluna %s e linha %s",
            ColunaParaTexto(tabuleiro.coluna),
            LinhaParaTexto(tabuleiro.linha)
        );
    }

}

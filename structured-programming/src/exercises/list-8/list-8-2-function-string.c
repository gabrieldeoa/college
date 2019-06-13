/*
Escreva um procedimento para listar os 256 caracteres da tabela ASCII com seus respectivos códigos.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

void tabelaASCII () {
    int i;
    printf("---------------------------------");
    printf("\n|    CODIGO     |    CARACTER   |");
    for(i = 0; i < 256; i++) {
        printf("\n---------------------------------\n");
        printf("|\t%d\t|\t%1c\t|", i, i);
    }
    printf("\n---------------------------------");

}

main() {
    printf("|\t   TABELA ASCII\t\t|\n");
    tabelaASCII();
}
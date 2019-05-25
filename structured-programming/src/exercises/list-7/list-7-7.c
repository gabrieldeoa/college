/*
Em um ginásio, as 1000 cadeiras estão dispostas em 4 setores coloridos diferentes: verde, amarelo, azul e branco.
Cada setor comporta 10 fileiras numeradas de 1 a 10. Em cada fileira, perfilam-se 25 colunas identi­ficadas de A a Y.
Escreva definições para tipos de dados capazes de representar uma cadeira deste ginásio.
*/

#include <stdio.h>

typedef enum TCOR { verde = 1, amarelo, azul, branco } Cor;

typedef struct TSETOR {
    Cor cor;
    int fileira;
    char coluna;

} Setor;

char * CorParaTexto(Cor cor) {
    switch(cor) {
        case verde: return "verde";
        case amarelo: return "amarelo";
        case azul: return "azul";
        case branco: return "branco";
    }
}

main () {
    Setor setor;

    printf("\t\tCADEIRA DO ESTADIO\n");
    
    printf("Setor\n");
    printf("1 - Verde \n2 - Amarelo \n3 - Azul \n4 - Branco");
    printf("\nCor: ");
    scanf("%d", &setor.cor);

    printf("\nNúmero da Fileira [1 até 10]: ");
    scanf("%d", &setor.fileira);

    printf("Letra da Coluna [A até Y(Maisculas)]: ");
    scanf("\n%c", &setor.coluna);

    printf(
        "\nSua cadeira tem as seguintes caracteristicas: \nSetor %s \nFileira %d \nColuna %c",
        CorParaTexto(setor.cor),
        setor.fileira,
        setor.coluna
    );
}
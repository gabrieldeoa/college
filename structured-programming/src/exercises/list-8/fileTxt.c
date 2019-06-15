/*
Inserindo dados em um arquivo texto.
*/
#include <stdio.h>

typedef struct TASCII {
    int codigo;
    char caractere;
} ASCII;

main() {
    const int registros = 256;
    ASCII ascii;
    FILE * arquivo;
    char c, nomeArquivo[80];
    int i;
    char opcao;

    printf("*******************************\n");
    printf("*** Manipulacao de arquivos ***\n");
    printf("*******************************\n\n");
    printf("Informe o nome (com caminho) do arquivo a ser usado: ");
    gets(nomeArquivo);

    arquivo = fopen(nomeArquivo, "w+");
    printf("\nARMAZENANDO DADOS NO ARQUIVO...\n");

    for(i = 0; i < registros; i = i+1){
        ascii.codigo = i;
        ascii.caractere = (char)(i);
        fprintf(arquivo, "\n%2d\t %c", ascii.codigo, ascii.caractere);
    }

    printf("\nLENDO DADOS DO ARQUIVO...\n");
    printf("Tabela ASCII:\n");
    rewind(arquivo);

    while(1) {
        fscanf(arquivo, "\n%2d\t %c", &ascii.codigo, &ascii.caractere);
        printf("\n%2d\t%c" , ascii.codigo, ascii.caractere);
        if (feof(arquivo)) break;
    }

    fclose(arquivo);
    printf("\nDeseja apagar o arquivo?\n");
    printf("[S]im\n");
    printf("[N]ao\n");
    printf("[S/N]: ");
    scanf("\n%c", &opcao);
    if ((opcao == "S") || (opcao == "s"))
    remove(nomeArquivo);
}

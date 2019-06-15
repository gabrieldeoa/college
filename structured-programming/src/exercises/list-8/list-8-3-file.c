/*
Reescreva o programa acima, mas modifique a abordagem.
Em vez de considerar um arquivo binário, considere um arquivo de texto.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TASCII {
  int codigo;
  char caractere;
} ASCII;

main() {
    ASCII asc;
    FILE * arqTxt;
    char nomeArq[80];
    int i = 0;

    printf("===> Contagem de dados no arquivo <===");

    printf("\n Forneca o nome do arquivo a ser lido: ");
    gets(nomeArq);

    //abrindo arquivo, ligação do arquivo em disco com a memória
    arqTxt = fopen(nomeArq, "r");


    while(1) {
      // lendo da disco e armazendo um ou mais registros na memória. Para mover o cursos é preciso ler
      fscanf(arqTxt, "\n%2d\t%c", &asc.codigo, &asc.caractere);

      // Se chegar ao final do arquivo, pare
      if(feof(arqTxt) )break;

      i++;
    }

    printf("A quantidade de registros no arquivo %s: %d", nomeArq, i);

    //Fecha a ligação com o arquivo no disco com a memória.
    fclose(arqTxt);
}

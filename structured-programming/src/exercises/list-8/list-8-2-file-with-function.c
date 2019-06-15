/*
Escreva um programa para criar uma cópia exata do arquivo criado pelo programa acima.
Trata-se de um novo arquivo, com outro nome.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TASCII {
  int codigo;
  char caractere;
} ASCII;

void copiarArquivoBinario(FILE **arq, FILE **copia) {
    ASCII asc;

    while(1) {
      // lendo da disco e armazendo um ou mais registros na memória. Para mover o cursos é preciso ler
      fread(&asc, sizeof(ASCII), 1, *arq);
      fwrite(&asc, sizeof(ASCII), 1, *copia);
      // Se chegar ao final do arquivo, pare
      if(feof(*arq))break;
    }
}

main() {
    FILE * arq, *copia;
    char nome[80], nomeCopia[80];

    printf("===> Copiando o arquivo <===");

    printf("\n Forneca o nome do arquivo: ");
    gets(nome);

    printf("\n Forneca o nome da copia do arquivo: ");
    gets(nomeCopia);

    //abrindo arquivo, ligação do arquivo em disco com a memória
    arq = fopen(nome, "rb");
    copia = fopen(nomeCopia, "wb");

    copiarArquivoBinario(&arq, &copia);

    //Fecha a ligação com o arquivo no disco com a memória.
    fclose(arq);
    fclose(copia);
}

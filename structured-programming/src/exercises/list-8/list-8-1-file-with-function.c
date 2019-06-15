/*
Escreva um programa para fornecer como saída a quantidade de registros armazenados no arquivo criado pelo programa acima.
A única informação que você, programador, dispõe é a estrutura de cada registro,
enquanto a única informação que o usuário do programa dispõe é o nome do arquivo.
Suponha total desconhecimento sobre quantos registros o programa acima inseriu; isso é tarefa do seu programa.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TASCII {
  int codigo;
  char caractere;
} ASCII;

int totalDeRegistros(FILE* arq) {
  ASCII asc;
  int i;

  while(1) {
    fread(&asc, sizeof(ASCII), 1, arq);

    if(feof(arq)) break;
    
    i++;
  }

  return i;
}
main() {
    FILE * arq;
    int quantidade;
    char nomeArq[80];


    printf("===> Contagem de dados no arquivo <===");

    printf("\n Forneca o nome do arquivo a ser lido: ");
    gets(nomeArq);

    //abrindo arquivo, ligação do arquivo em disco com a memória
    arq = fopen(nomeArq, "rb");

    quantidade = totalDeRegistros(arq);
    printf("A quantidade de registros no arquivo %s: %d", nomeArq, quantidade);

    //Fecha a ligação com o arquivo no disco com a memória.
    fclose(arq);
}

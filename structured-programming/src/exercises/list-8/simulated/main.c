#include"implementacoesIniciais.h"

void distribuiPecas(TJogoDeDomino*); //FALTA PROGRAMAR � MATRIZES E TIPOS
void arquivaPecasDeJogador(TJogoDeDomino, int, FILE**); // FALTA PROGRAMAR - ARQUIVOS
void arquivoTxtParaBin(FILE**, FILE**, int); //FALTA PROGRAMAR - ARQUIVOS
int  geraCodigo(TPecaDeDomino); //FALTA PROGRAMAR � RACIOC�NIO L�GICO
void imprimePecasComCodigosGerados(TJogoDeDomino*);

//N�O MODIFICAR!!!
void imprimePecasComCodigosGerados(TJogoDeDomino *jogo)
{
  int i;
  for(i = 0; i < pecas; i = i+1)
  {
    //(*jogo).pecasDoJogo[i].codigo = geraCodigo((*jogo).pecasDoJogo[i]);
    imprimePeca((*jogo).pecasDoJogo[i]);
  }
  printf("\n");
}

void distribuiPecas(TJogoDeDomino* jg) {
  TPecaDeDomino pecaInvalida;
  pecaInvalida.codigo = pecaInvalida.face1 = pecaInvalida.face2 = (TValor)-1;

  srand(time(NULL));

  int random, i, j;

  for (i = 0; i < jogadores; i++)
  {
    for (j = 0; j < maoInicial;)
    {
      random = rand() % pecas;
      if(jg->pecasDoJogo[random].codigo != -1)
      {
        jg->pecasDosJogadores[i][j] = jg->pecasDoJogo[random];
        jg->pecasDoJogo[random] = pecaInvalida;
        j++;
      }
    }
  }
}

void arquivaPecasDeJogador(TJogoDeDomino jg, int jogador, FILE** arq) {
  int j;
  for (j = 0; j < maoInicial; j++)
  {

    if(jg.pecasDosJogadores[jogador][j].codigo != -1)
    {
      fprintf(
        *arq,
        "\n%2d ---> %d | %d",
        jg.pecasDosJogadores[jogador][j].codigo,
        jg.pecasDosJogadores[jogador][j].face1,
        jg.pecasDosJogadores[jogador][j].face2
      );
    }
  }
}

void arquivoTxtParaBin(FILE** arqTxt, FILE** arqBin, int tamanho) {
  TPecaDeDomino peca;
  rewind(*arqTxt);

  while(1) {
    fscanf(*arqTxt, "%2d ---> %d | %d", &peca.codigo, &peca.face1, &peca.face2);

    if(feof(*arqTxt)) break;

    fwrite(&peca, tamanho, 1, *arqBin);
  }
}

main()
{
  TJogoDeDomino jogo;
  FILE * arqTxt, *arqBin;
  int i;

  iniciaPecasDoJogo(&jogo);
  imprimePecasComCodigosGerados(&jogo);
  imprimePecasDoJogo(jogo);

  distribuiPecas(&jogo);
  imprimePecasDosJogadores(jogo);

  arqTxt = fopen("jogador1.txt", "w+");
  arquivaPecasDeJogador(jogo, 0, &arqTxt);

  arqBin = fopen("jogador1.dat", "wb+");
  arquivoTxtParaBin(&arqTxt, &arqBin, sizeof(TPecaDeDomino));

  fclose(arqTxt);
  fclose(arqBin);
}

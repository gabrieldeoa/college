#include "definicoes.h"

void iniciaPecasDoJogo (TJogoDeDomino*);
void imprimePeca(TPecaDeDomino);
void imprimePecasDoJogo(TJogoDeDomino);
void imprimePecasDosJogadores(TJogoDeDomino);
int  min(TPecaDeDomino);
int  max(TPecaDeDomino);

void iniciaPecasDoJogo (TJogoDeDomino *jogo)

{
  int i, j, k = 0;
  for (i = 0; i < maoInicial; i++)
    for (j = i; j < maoInicial; j++)
    {
      (*jogo).pecasDoJogo[k].codigo = k;
      (*jogo).pecasDoJogo[k].face1  = (TValor)i;
      (*jogo).pecasDoJogo[k].face2  = (TValor)j;
      k = k+1;
    }

  for (i = 0; i < jogadores; i++)
    for (j = 0; j < maoInicial; j++)
    {
      (*jogo).pecasDosJogadores[i][j].codigo = (TValor)-1;
      (*jogo).pecasDosJogadores[i][j].face1  = (TValor)-1;
      (*jogo).pecasDosJogadores[i][j].face2  = (TValor)-1;
    }
}

void imprimePeca(TPecaDeDomino peca)
{
  printf("%2d ---> %d | %d\n", peca.codigo, peca.face1, peca.face2);
}

void imprimePecasDoJogo(TJogoDeDomino jogo)
{
  int i;
  for (i = 0; i < pecas; i++)
    if ((jogo).pecasDoJogo[i].codigo != -1)
      imprimePeca((jogo).pecasDoJogo[i]);
  printf("\n");
}

void imprimePecasDosJogadores(TJogoDeDomino jogo)
{
  int i, j;
  for (i = 0; i < jogadores; i++)
  {
    for (j = 0; j < maoInicial; j++)
      if ((jogo).pecasDosJogadores[i][j].codigo != -1)
        imprimePeca((jogo).pecasDosJogadores[i][j]);
    printf("\n");
  }
}

int min(TPecaDeDomino peca)
{
  return peca.face1 < peca.face2 ? peca.face1 : peca.face2;
}

int max(TPecaDeDomino peca)
{
  return peca.face1 > peca.face2 ? peca.face1 : peca.face2;
}

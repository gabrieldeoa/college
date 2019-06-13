#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define pecas      28
#define maoInicial  7
#define jogadores   4

typedef enum _TValor_ {zero, um, dois, tres, quatro, cinco, seis} TValor;

typedef struct _TPecaDeDomino_
{
  int codigo;
  TValor face1, face2;
} TPecaDeDomino;

typedef struct _TJogoDeDomino_
{
  TPecaDeDomino pecasDoJogo[pecas];
  TPecaDeDomino pecasDosJogadores[jogadores][maoInicial];
} TJogoDeDomino;

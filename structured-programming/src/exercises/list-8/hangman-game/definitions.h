#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VIDAS               5
#define DIR_WORDS "words.txt"

typedef struct TForca {
    int vidas;
    char * palavraSecreta;
    char * palavra;
    char * letrasUsadas;
} Forca;

typedef struct TJogoDaForca {
    char * jogador;
    int resultado;
    Forca forca;
} JogoDaForca;
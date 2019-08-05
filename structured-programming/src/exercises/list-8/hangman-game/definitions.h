#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VIDAS               5
#define DIR_WORDS "words.txt"
#define DIR_RESULT "result.dat"

typedef struct TForca {
    int vidas;
    char palavraSecreta[80];
    char palavra[80];
    char letrasUsadas[26];
} Forca;

typedef struct TJogoDaForca {
    char jogador[80];
    int resultado;
    Forca forca;
} JogoDaForca;
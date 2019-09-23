#ifndef LISTA_DE_CARACTERES
#define LISTA_DE_CARACTERES

#include <stdio.h>
#include <stdlib.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -10

char** criarListaChar(int tam) {
    char **lista;
    int i;

    lista = calloc(tam, sizeof(char*[tam]));

    return lista;
}

int tamanhoDaListaChar(char **lista, int tam) {
    int i;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    for(i=0; i < tam; i++)
        if(lista[i] == NULL)
            return i;

    return tam;
}

int posicaoDoElementoChar(char elemento, char** lista, int tam) {
    int i, totalElementos;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    totalElementos = tamanhoDaListaChar(lista, tam);

    for(i=0; i < totalElementos; i++)
        if(*(lista[i]) == elemento)
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

int inserirElementoChar(char elemento, char** lista, int tam) {
    int i, totalElementos, posicaoElemento;

    totalElementos = tamanhoDaListaChar(lista, tam);

    if(totalElementos >= tam )
        return LISTA_CHEIA;

    posicaoElemento = posicaoDoElementoChar(elemento, lista, tam);

    if(posicaoElemento != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    lista[totalElementos] = malloc(sizeof(char));

    *(lista[totalElementos]) = elemento;

    return SUCESSO;


}

int removerElemento(char elemento, char** lista, int tam) {
    int i, posicao, totalElementos;

    totalElementos = tamanhoDaListaChar(lista, tam);
    posicao = posicaoDoElementoChar(elemento, lista, tam);

    if(totalElementos <= 0)
        return LISTA_VAZIA;

    if(posicao == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    free(lista[posicao]);

    for(i = posicao; i < totalElementos-1; i++)
        lista[i] = lista[i + 1];

    lista[i] = NULL;

    return SUCESSO;
}

void exibirListaChar(char **lista, int tam) {
    int i;

    if(lista == NULL)
        printf("LISTA NAO ALOCADA");

    for(i = 0; i < tam; i++)
        if(lista[i] != NULL)
            printf("%c|", *(lista[i]));
        else
            printf("N|");
    printf("\n");
}

char** lerListaChar(int tam) {
    int i;
    char elemento, ** lista;

    lista = criarListaChar(tam);

    for(i=0; i < tam; i++) {
        printf("LISTA[%d] = ", i);
        scanf("\n%c", &elemento);

        if(elemento == '\0')
            return lista;

        inserirElementoChar(elemento, lista, tam);
    }

    return lista;
}

void destruirListaChar(char** lista, int tam) {
    int i;

    for(i=0; i < tam; i++)
        free(lista[i]);

    free(lista);
}

#endif

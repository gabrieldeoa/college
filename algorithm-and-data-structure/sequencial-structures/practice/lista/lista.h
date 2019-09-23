#ifndef LISTA_INTEIRO
#define LISTA_INTEIRO

#include <stdlib.h>
#include <stdio.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define ELEMENTO_EXISTENTE -2
#define LISTA_NAO_ALOCADA -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

/*
    REPRESENTACAO
    tipo ** variavel;

    int ** lista;
*/

/*
    OPERACAOES
*/

//criar
int** lista_criar(int tam) {
    int **lista;
    lista = calloc(tam, sizeof(int*[tam]));
    return lista;
}

//numero de elementos
int lista_numero_elementos(int **lista, int tam) {
   int i;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;
    
    for(i = 0; i < tam; i++) {
        if(lista[i] == NULL)
            return i;
    }

    return tam;
}

//posicao do elemento
int lista_posicao_elemento(int elemento, int **lista, int tam) {
    int i, ne;
    ne = lista_numero_elementos(lista, tam);

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    for(i = 0; i < ne; i++) {
        if(*(lista[i]) == elemento)
            return i;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
int lista_obter_elemento(int posicao, int ** lista) {
    return *(lista[posicao]);
}

//inserir
int lista_inserir(int elemento, int **lista, int tam) {
    int ne, pos;

    ne = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam);

    if(ne >= tam)
        return LISTA_CHEIA;
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    lista[ne] = malloc(sizeof(int));
    *(lista[ne]) = elemento;
    
    return SUCESSO;
}

//remover
int lista_remover(int elemento, int **lista, int tam) {
    int i, ne, pos;
    ne = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam);

    if(ne <= 0)
        return LISTA_VAZIA;

    if(pos == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;
    
    free(lista[pos]);

    for(i = pos; i < ne; i++) {
        lista[i] = lista[i + 1];
    }

    lista[i] = NULL;

    return SUCESSO;
}

//exibir
void lista_exibir(int **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        if(lista[i] != NULL)
            printf("%d|", *(lista[i])); 
        else
            printf("N|");
    }
    printf("\n");
}

//ler
int** lista_ler(int tam, int qtd_elementos) {
    int i, elemento, **lista;
    lista = lista_criar(tam);

    for(i = 0; i < tam  && i < qtd_elementos; i++) {
        printf("lista[%d] = ", i);
        scanf("%d", &elemento);
        lista_inserir(elemento, lista, tam);
    }
    return lista;
}

//destruir
void lista_destruir(int **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        free(lista[i]);
    }   
    free(lista);
}
#endif
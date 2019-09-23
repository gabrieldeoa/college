#ifndef PILHA_INTEIRO
#define PILHA_INTEIRO

#include <stdlib.h>
#include <stdio.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -10

/*
    REPRESENTACAO

    typedef struct {
        <tipo> *elementos;
        int topo, tamanho;
    } <variavel>;
*/

/* Representacao */
typedef struct {
    int * elementos;
    int tamanho, topo;
} pilha;

/* Operacoes */

//criar
void pilha_criar(pilha *p, int tam) {
    p->elementos = malloc(sizeof(int [tam]));
    p->tamanho = tam;
    p->topo = -1;
}

//numero de elementos
int pilha_numero_elementos(pilha p) {
    return p.topo + 1;
}

//posicao do elemento
int pilha_posicao_elemento(int elemento, pilha p) {
    int i, ne;
    ne = pilha_numero_elementos(p);

    for(i = 0; i < ne; i++) {
        if(p.elementos[i] == elemento)
            return i;
    }
    
    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
int pilha_obter_elemento(int posicao, pilha p) {
    return p.elementos[posicao];
}

//inserir
int pilha_inserir(int elemento, pilha *p) {
    int ne, pos;
    ne = pilha_numero_elementos(*p);
    pos = pilha_posicao_elemento(elemento, *p);

    if(ne >= p->tamanho)
        return PILHA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    p->elementos[ne] = elemento;
    p->topo++;

    return SUCESSO;
}

//remover
int pilha_remover(pilha *p) {
    int ne;
    ne = pilha_numero_elementos(*p);

    if(ne <= 0)
        return PILHA_VAZIA;
    
    p->topo--;

    return SUCESSO;
}

//exibir
void pilha_exibir(pilha p) {
    int i, ne;
    ne = pilha_numero_elementos(p);

    for(i = 0; i < ne; i++) {
        printf("%d |", p.elementos[i]);
    }
    printf("\n");
}

//ler
void pilha_ler(pilha *p, int tam, int qtd) {
    int elemento, i;

    pilha_criar(p, tam);

    for(i = 0; i < tam && i < qtd; i++) {
        printf("pilha[%d] = ");
        scanf("%d", &elemento);
        pilha_inserir(elemento, p);
    }
}

//destruir
void pilha_destruir(pilha *p) {
    free(p->elementos);
    p->elementos = NULL;
    p->tamanho = p->topo = PILHA_NAO_ALOCADA;
}

#endif
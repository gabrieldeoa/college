#ifndef PILHA_DUPLA_INTEIRO
#define PILHA_DUPLA_INTEIRO

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define ELEMENTO_EXISTENTE -2
#define PILHA_NAO_ALOCADA -3
#define PILHA_CHEIA -4
#define PILHA_VAZIA -5
#define SUCESSO -6

/* REPRESENTACAO/DEFINICAO DE TIPO */
typedef struct {
    int * elementos;
    int topo1, topo2, tamanho;
} pilha_dupla;

/* OPERACOES */

//criar
void pilha_dupla_criar(pilha_dupla *pd, int tam) {
    pd->elementos = malloc(sizeof(int [tam]));
    pd->topo1 = -1;
    pd->topo2 = tam;
    pd->tamanho = tam;
}

//numero elementos
int pilha_dupla_numero_elementos(pilha_dupla pd, int tipo_pilha) {
    if(tipo_pilha == 1)
        return pd.topo1 + 1;
    else
        return pd.tamanho - pd.topo2;
}

//posicao elemento
int pilha_dupla_posicao_elemento(int elemento, pilha_dupla pd, int tipo_pilha) {
    int i;

    if(tipo_pilha == 1) {
        for(i = 0; i <= pd.topo1; i++)
            if(pd.elementos[i] == elemento)
                return i;
    } else {
        for(i = pd.tamanho - 1; i >= pd.topo2; i--)
            if(pd.elementos[i] == elemento)
                return i;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
int pilha_dupla_obter_elemento(int posicao, pilha_dupla pd) {
    return pd.elementos[posicao];
}

//inserir
int pilha_dupla_inserir(int elemento, pilha_dupla *pd, int tipo_pilha) {
    int i, ne, pos, topo;
    
    ne = pilha_dupla_numero_elementos(*pd, tipo_pilha);
    pos = pilha_dupla_posicao_elemento(elemento, *pd, tipo_pilha);

    if(pd->topo1 + 1 == pd->topo2)
        return PILHA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    if(tipo_pilha == 1)
        topo = ++pd->topo1;
    else
        topo = --pd->topo2;

    pd->elementos[topo] = elemento;

    return SUCESSO;
}

//remover
int pilha_dupla_remover(pilha_dupla *pd, int tipo_pilha) {
    int ne;
    ne = pilha_dupla_numero_elementos(*pd, tipo_pilha);

    if(ne <= 0)
        return PILHA_VAZIA;
    if(tipo_pilha == 1)
        pd->topo1--;
    else
        pd->topo2++;
    
    return SUCESSO;
}

//exibir
void pilha_dupla_exibir(pilha_dupla pd, int tipo_pilha) {
    int i;

    if(tipo_pilha == 1)
        for(i = 0; i <= pd.topo1; i++)
            printf("%d |", pd.elementos[i]);
    else
        for(i = pd.tamanho-1; i >= pd.topo2; i--)
            printf("%d |", pd.elementos[i]);
    printf("\n");
}

//ler
void pilha_dupla_ler(pilha_dupla *pd, int tam, int qtd, int tipo_pilha) {
    int i, elemento;

    pilha_dupla_criar(pd, tam);

    for(i = 0; i < qtd && i < tam; i++) {
        printf("pilha[%d]= ", i);
        scanf("%d", &elemento);
        pilha_dupla_inserir(elemento, pd, tipo_pilha);
    }
}

//destruir
void pilha_dupla_destruir(pilha_dupla *pd) {
    free(pd->elementos);
    pd->elementos = NULL;
    pd->topo1 = pd->topo2 = pd->tamanho = PILHA_NAO_ALOCADA;
}

#endif
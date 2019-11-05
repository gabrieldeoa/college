#ifndef PILHA_DUPLAMENTE_ENCADEADA_INTEIRO
#define PILHA_DUPLAMENTE_ENCADEADA_INTEIRO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define PILHA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_dup_enc no_dup_enc;

typedef struct no_dup_enc* pilha;

typedef struct _no_dup_enc {
    int elemento;
    no_dup_enc* proximo;
    no_dup_enc* anterior;
};

/*** Operações ***/

// criar
no_dup_enc* pilha_criar_no(int dado) {
    no_dup_enc* no = malloc(sizeof(no_dup_enc));
    no->elemento = dado;
    no->proximo = no->anterior = NULL;
    return no;
}

// numero de elementos
int pilha_numero_elementos(pilha pilha) {
    int tamanho = 0;
    no_dup_enc* no = pilha;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no
no_dup_enc* pilha_obter_no_elemento(int elemento, pilha pilha) {
    no_dup_enc* no = pilha;

    while(no != NULL) {
        if(no->elemento == elemento)
            return no;
    }

    return NULL;
}

// inserir
int pilha_inserir(int elemento, pilha* pilha) {
    no_dup_enc* no, *novo;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    
    if(pilha_obter_no_elemento(elemento, *pilha) != NULL)
        return ELEMENTO_EXISTENTE;
    
    novo = pilha_criar_no(elemento);

    if(*pilha == NULL) {
        *pilha = novo;
    }
    else {
        no = *pilha;

        // avança ate o ultimo
        while(no->proximo != NULL)
            no = no->proximo;
        
        no->proximo = novo;
        novo->anterior = no;
    }
    
    return SUCESSO;
}

// remover
int pilha_remover(int elemento, pilha* pilha) {
    no_dup_enc *no, *ant;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*pilha == NULL)
        return PILHA_VAZIA;
    
    no = *pilha;

    //um no
    if(no->proximo == NULL) {
        free(*pilha);
        *pilha = NULL;
    }
    // a partir do segundo no
    else {
        no = no->proximo;

        while(no->proximo != NULL) {
            no = no->proximo;
        }
        ant->proximo = NULL;
    }
    return SUCESSO;
}

// exibir
void pilha_exibir ( pilha pilha ){
    no_dup_enc *no = pilha;
    while (no != NULL) {
        printf ("%d|", no->elemento );
        no = no->proximo;
    }
    printf("\n") ;
}

// ler
pilha pilha_ler() {
    pilha p = NULL;
    int i, elemento, quantidade;

    printf("Quantos elementos deseja inserir ?");

    for (i = 0; i < quantidade; i++) {
        printf("pilha[%d]= ", i);
        scanf("%d", &elemento);
        pilha_inserir(elemento, &p);
    }

    return p;
}

// desalocar
void pilha_desalocar(pilha* pilha) {
    no_dup_enc *no, *prx;
    
    if(pilha != NULL) {
        if(*pilha != NULL) {
            no = *pilha;
            prx = no->proximo;

            while(no != NULL) {
                free(no);
                no = prx;
                if(prx != NULL) {
                    prx = prx->proximo;
                }
            }
        }
    }

    *pilha = NULL;
}

#endif
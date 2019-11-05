#ifndef LISTA_DUPLAMENTE_ENCADEADA_ALUNO
#define LISTA_DUPLAMENTE_ENCADEADA_ALUNO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define LISTA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_dup_enc no_dup_enc;

typedef struct no_dup_enc* lista;

typedef struct {
    char nome[40];
    char disciplina[40];
    int idade;
    float p1, p2;
} aluno;

typedef struct _no_dup_enc {
    aluno aluno;
    no_dup_enc* proximo;
    no_dup_enc* anterior;
};

/*** Operações ***/

// criar
no_dup_enc* lista_criar_no(int dado) {
    no_dup_enc* no = malloc(sizeof(no_dup_enc));
    no->elemento = dado;
    no->proximo = no->anterior = NULL;
    return no;
}

// numero de elementos
int lista_numero_elementos(lista lista) {
    int tamanho = 0;
    no_dup_enc* no = lista;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no
no_dup_enc* lista_obter_no_elemento(int elemento, lista lista) {
    no_dup_enc* no = lista;

    while(no != NULL) {
        if(no->elemento == elemento)
            return no;
    }

    return NULL;
}

// inserir
int lista_inserir(int elemento, lista* lista) {
    no_dup_enc* no, *novo;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;
    
    if(lista_obter_no_elemento(elemento, *lista) != NULL)
        return ELEMENTO_EXISTENTE;
    
    novo = lista_criar_no(elemento);

    if(*lista == NULL) {
        *lista = novo;
    }
    else {
        no = *lista;

        // avança ate o ultimo
        while(no->proximo != NULL)
            no = no->proximo;
        
        no->proximo = novo;
        novo->anterior = no;
    }
    
    return SUCESSO;
}

// remover
int lista_remover(int elemento, lista* lista) {
    no_dup_enc *no, *ant, *prx;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*lista == NULL)
        return LISTA_VAZIA;
    
    if(lista_obter_no_elemento(elemento, *lista) == NULL)
        return ELEMENTO_INEXISTENTE;
    
    no = *lista;

    // elemento e o primeiro no
    if(no->elemento == elemento) {
        no = no->proximo;
        free(*lista);
        *lista = no;

        if(no != NULL)
            no->anterior = NULL;
    }
    // a partir do segundo elemento
    else {
        no = no->proximo;

        while(no != NULL) {
            if(no->elemento == elemento) {
                ant = no->anterior;
                prx = no->proximo;
                ant->proximo = prx;

                if(prx != NULL)
                    prx->anterior = ant;
                free(no);
                break;
            }
            no = no->proximo;
        }
    }
    return SUCESSO;
}

// exibir
void lista_exibir ( lista lista ){
    no_dup_enc *no = lista;
    while (no != NULL) {
        printf ("%d|", no->elemento );
        no = no->proximo;
    }
    printf("\n") ;
}

// ler
lista lista_ler() {
    lista l = NULL;
    int i, elemento, quantidade;

    printf("Quantos elementos deseja inserir ?");

    for (i = 0; i < quantidade; i++) {
        printf("LISTA[%d]= ", i);
        scanf("%d", &elemento);
        lista_inserir(elemento, &l);
    }

    return l;
}

// desalocar
void lista_desalocar(lista* lista) {
    no_dup_enc *no, *prx;
    
    if(lista != NULL) {
        if(*lista != NULL) {
            no = *lista;
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

    *lista = NULL;
}

#endif
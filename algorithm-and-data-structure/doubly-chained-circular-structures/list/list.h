#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_INTEIRO
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_INTEIRO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define LISTA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_dup_enc no_dup_enc;

typedef struct _no_dup_enc* lista;

typedef struct _no_dup_enc {
    int elemento;
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

    if( no == NULL )
        return 0;

    do {
        no = no->proximo;
        tamanho++;
    } while(no->proximo != lista);

    return tamanho;
}

// obter no
no_dup_enc* lista_obter_no_elemento(int elemento, lista lista) {
    no_dup_enc* no = lista;

    if(lista != NULL) {
        do {
            if(no->elemento == elemento)
                return no;
            no = no->proximo;
        } while (no != lista);
    }
    return NULL;
}

// inserir
int lista_inserir(int elemento, lista* lista) {
    no_dup_enc *no, *novo;

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
        do {
            no = no->proximo;
        } while(no->proximo != *lista);

        no->proximo = novo;
        novo->anterior = no;
    }

    novo->proximo = *lista;
    (*lista)->anterior = novo;

    return SUCESSO;
}

// remover
int lista_remover(int elemento, lista* lista) {
    no_dup_enc *no, *ant, *prx, *final;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;

    if(*lista == NULL)
        return LISTA_VAZIA;

    if(lista_obter_no_elemento(elemento, *lista) == NULL)
        return ELEMENTO_INEXISTENTE;

    no = *lista;

    // elemento e o primeiro no
    if(no->elemento == elemento) {
        final = *lista;
        do {
            final = final->proximo;
        } while(final->proximo != *lista);

        no = no->proximo;

        if(no == *lista)
            no = NULL;

        free(*lista);
        *lista = no;

        if(no != NULL) {
            final->proximo = *lista;
            (*lista)->anterior = final;
        }
    }
    // a partir do segundo elemento
    else {
        no = no->proximo;

        while(no != *lista) {
            if(no->elemento == elemento) {
                ant = no->anterior;
                prx = no->proximo;
                ant->proximo = prx;
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
void lista_exibir ( lista lista ) {
    no_dup_enc *no = lista;

    if(no != NULL) {
        do {
            printf ("%d|", no->elemento );
            no = no->proximo;
        } while(no != lista);
    }
    printf("\n") ;
}

// ler
lista lista_ler() {
    lista l = NULL;
    int i, elemento, quantidade;

    printf("Quantos elementos deseja inserir ?");
    scanf("%d", &quantidade);

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

            do {
                free(no);
                no = prx;

                if(prx != *lista)
                    prx = prx->proximo;

            } while(no != *lista);
        }
    }
    *lista = NULL;
}

#endif

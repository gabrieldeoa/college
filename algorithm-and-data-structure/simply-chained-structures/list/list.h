#ifndef LISTA_SIMPLESMENTE_ENCADEADA_INTEIRO
#define LISTA_SIMPLESMENTE_ENCADEADA_INTEIRO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define LISTA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_enc no_enc;

typedef struct no_enc *lista;

typedef struct _no_enc {
    int elemento;
    no_enc* proximo;
};

/*** Operações ***/

// criar
no_enc* lista_criar_no(int dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    return no;
}

// numero de elementos
int lista_numero_elementos(lista lista) {
    int tamanho = 0;
    no_enc* no = lista;

    if(no == NULL)
        return 0;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no
no_enc* lista_obter_no_elemento(int elemento, lista lista) {
    no_enc* no = lista;

    while(no != NULL) {
        if(no->elemento == elemento)
            return no;
        no = no->proximo;
    }

    return NULL;
}

// inserir
int lista_inserir(int elemento, lista* lista) {
    no_enc * no, *novo;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;

    if(lista_obter_no_elemento(elemento, *lista) != NULL)
        return ELEMENTO_EXISTENTE;
    
    novo = lista_criar_no(elemento);

    if(*lista == NULL)
        *lista = novo;
    else {
        no = *lista;

        // varre ate o final
        while(no->proximo != NULL)
            no = no->proximo;

        no->proximo = novo;
    }
    return SUCESSO;
}

// remover
int lista_remover(int elemento, lista* lista) {
    no_enc* no, *anterior;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*lista == NULL)
        return LISTA_VAZIA;

    if(lista_obter_no_elemento(elemento, *lista) == NULL)
        return ELEMENTO_INEXISTENTE;
    
    no = *lista;

    //exclusao do primeiro no
    if(no->elemento == elemento) {
        no = no->proximo;
        free(*lista);
        *lista = no;
    }
    
    //exclusao a partir do segundo
    else {
        anterior = no;
        no = no->proximo;
        while(no != NULL) {
            if(no->elemento == elemento) {
                anterior->proximo = no->proximo;
                free(no);
                break;
            }
            anterior = no;
            no = no->proximo;
        }
    }
    return SUCESSO;
}

// exibir
void lista_exibir(lista lista) {
    no_enc* no = lista;
    if(no != NULL) {
        while(no != NULL) {
            printf("%d|", no->elemento);
            no = no->proximo;
        }
    }
    printf("\n");
}

// ler
lista lista_ler() {
    lista li = NULL;
    int i, elemento, quantidade;
    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        printf("LISTA [%d]: ", i);
        scanf("%d", &elemento);
        lista_inserir(elemento, &li);
    }

    return li;
}

//desalocar
void lista_desalocar(lista* lista) {
    no_enc* no, *proximo;

    if(lista != NULL) {
        if(*lista != NULL) {
            no = *lista;
            proximo = no->proximo;

            while(no != NULL) {
                free(no);
                no = proximo;
                if(proximo != NULL)
                    proximo = proximo->proximo;
            }
        }
    }

    *lista = NULL;
}

#endif
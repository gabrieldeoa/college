#ifndef FILA_SIMPLESMENTE_ENCADEADA_INTEIRO
#define FILA_SIMPLESMENTE_ENCADEADA_INTEIRO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define FILA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_enc no_enc;

typedef struct no_enc *fila;

typedef struct _no_enc {
    int elemento;
    no_enc* proximo;
};

/*** Operações ***/

// criar
no_enc* fila_criar_no(int dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    return no;
}

// numero de elementos
int fila_numero_elementos(fila fila) {
    int tamanho = 0;
    no_enc* no = fila;

    if(no == NULL)
        return 0;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no
no_enc* fila_obter_no_elemento(int elemento, fila fila) {
    no_enc* no = fila;

    while(no != NULL) {
        if(no->elemento == elemento)
            return no;
        no = no->proximo;
    }

    return NULL;
}

// inserir
int fila_inserir(int elemento, fila* fila) {

    no_enc *no, *novo, *anterior;

    if(fila == NULL) return REFERENCIA_INCORRETA;

    if(fila_obter_no_elemento(elemento, *fila) != NULL) return ELEMENTO_EXISTENTE;
    
    novo = fila_criar_no(elemento);

    if(*fila == NULL)
        *fila = novo;
    else {
        anterior = *fila;
        no = anterior->proximo;

        //primeiro no
        if(anterior->elemento > elemento) {
            *fila = novo;
            novo->proximo = anterior;
        }
        // a partir do segundo
        else{
            while ( no != NULL ) {
                if(no->elemento > elemento) {
                   break;
                }
                anterior = anterior->proximo;
                no = no->proximo;
            }

            novo->proximo = no;
            anterior->proximo = novo;
        }
    }

    return SUCESSO;
}

// remover
int fila_remover(fila* fila) {
    no_enc* no;

    if(fila == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*fila == NULL)
        return FILA_VAZIA;
    
    no = *fila;

    // fila contem somente um no
    if(no->proximo == NULL) {
        free(*fila);
        *fila = NULL;
    }
    
    // mais de um no
    else {
        no = no->proximo;
        free(*fila);
        *fila = no;
    }
    return SUCESSO;
}

//exibir
void fila_exibir(fila fila) {
    no_enc* no = fila;
    int i = 0;
    if(no != NULL) {
        while(no != NULL) {
            printf("%d|", no->elemento);
            i++;
            if(i == 5) break;
            no = no->proximo;
        }
    }
    printf("\n");
}

//ler
fila fila_ler() {
    fila li = NULL;
    int i, elemento, quantidade;
    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        printf("fila [%d]: ", i);
        scanf("%d", &elemento);
        fila_inserir(elemento, &li);
    }

    return li;
}

//desalocar
void fila_desalocar(fila* fila) {
    no_enc* no, *proximo;

    if(fila != NULL) {
        if(*fila != NULL) {
            no = *fila;
            proximo = no->proximo;

            while(no != NULL) {
                free(no);
                no = proximo;
                if(proximo != NULL)
                    proximo = proximo->proximo;
            }
        }
    }

    *fila = NULL;
}

#endif
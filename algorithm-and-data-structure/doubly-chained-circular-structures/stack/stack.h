#ifndef PILHA_DUPLAMENTE_ENCADEADA_CIRCULAR_INTEIRO
#define PILHA_DUPLAMENTE_ENCADEADA_CIRCULAR_INTEIRO

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

    if( no == NULL )
        return 0;

    do {
        no = no->proximo;
        tamanho++;
    } while(no->proximo != pilha);

    return tamanho;
}

// obter no
no_dup_enc* pilha_obter_no_elemento(int elemento, pilha pilha) {
    no_dup_enc* no = pilha;

    if(pilha != NULL) {
        do {
            if(no->elemento == elemento)
                return no;
            no = no->proximo;
        } while (no != pilha);
    }
    return NULL;
}

// inserir
int pilha_inserir(int elemento, pilha* pilha) {
    no_dup_enc *no, *novo;

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
        do {
            no = no->proximo;
        } while(no->proximo != *pilha);
        
        no->proximo = novo;
        novo->anterior = no;
    }

    novo->proximo = *pilha;
    (*pilha)->anterior = novo;

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

    // primeiro  no
    if( no->proximo == *pilha) {
        free(*pilha);
        *pilha = NULL;
    } else {
        no = no->proximo;

        do {
            no = no->proximo;
        } while (no->proximo != *pilha);

        ant = no->proximo;
        free(no);
        ant->proximo = *pilha;
        (*pilha)->anterior = ant;
    }

    return SUCESSO;
}

// exibir
void pilha_exibir ( pilha pilha ) {
    no_dup_enc *no = pilha;

    if(no != NULL) {
        do {
            printf ("%d|", no->elemento );
            no = no->proximo;
        } while(no != pilha);
    }
    printf("\n") ;
}

// ler
pilha pilha_ler() {
    pilha l = NULL;
    int i, elemento, quantidade;

    printf("Quantos elementos deseja inserir ?");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        printf("pilha[%d]= ", i);
        scanf("%d", &elemento);
        pilha_inserir(elemento, &l);
    }

    return l;
}

// desalocar
void pilha_desalocar(pilha* pilha) {
    no_dup_enc *no, *prx;
    
    if(pilha != NULL) {
        if(*pilha != NULL) {
            no = *pilha;
            prx = no->proximo;

            do {
                free(no);
                no = prx;

                if(prx != *pilha)
                    prx = prx->proximo;

            } while(no != *pilha);
        }
    }
    *pilha = NULL;
}

#endif
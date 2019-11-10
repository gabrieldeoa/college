#ifndef FILA_DUPLAMENTE_ENCADEADA_CIRCULAR_INTEIRO
#define FILA_DUPLAMENTE_ENCADEADA_CIRCULAR_INTEIRO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define FILA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_dup_enc no_dup_enc;

typedef struct no_dup_enc* fila;

typedef struct _no_dup_enc {
    int elemento;
    no_dup_enc* proximo;
    no_dup_enc* anterior;
};

/*** Operações ***/

// criar
no_dup_enc* fila_criar_no(int dado) {
    no_dup_enc* no = malloc(sizeof(no_dup_enc));
    no->elemento = dado;
    no->proximo = no->anterior = NULL;
    return no;
}

// numero de elementos
int fila_numero_elementos(fila fila) {
    int tamanho = 0;
    no_dup_enc* no = fila;

    if( no == NULL )
        return 0;

    do {
        no = no->proximo;
        tamanho++;
    } while(no->proximo != fila);

    return tamanho;
}

// obter no
no_dup_enc* fila_obter_no_elemento(int elemento, fila fila) {
    no_dup_enc* no = fila;

    if(fila != NULL) {
        do {
            if(no->elemento == elemento)
                return no;
            no = no->proximo;
        } while (no != fila);
    }
    return NULL;
}

// inserir
int fila_inserir(int elemento, fila* fila) {
    no_dup_enc *no, *novo;

    if(fila == NULL)
        return REFERENCIA_INCORRETA;
    
    if(fila_obter_no_elemento(elemento, *fila) != NULL)
        return ELEMENTO_EXISTENTE;
    
    novo = fila_criar_no(elemento);

    if(*fila == NULL) {
        *fila = novo;
    }
    else {
        no = *fila;

        // avança ate o ultimo
        do {
            no = no->proximo;
        } while(no->proximo != *fila);
        
        no->proximo = novo;
        novo->anterior = no;
    }

    novo->proximo = *fila;
    (*fila)->anterior = novo;

    return SUCESSO;
}

// remover
int fila_remover(int elemento, fila* fila) {
    no_dup_enc *no, *final;

    if(fila == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*fila == NULL)
        return FILA_VAZIA;
    
    final = *fila;

    do {
        final = final->proximo;
    } while(final->proximo != *fila);

    no = *fila;

    if(no->proximo == *fila) {
        free(*fila);
        *fila = NULL;
    } else {
        no = no->proximo;
        free(*fila);
        *fila = no;
    }
    final->proximo = *fila;
    (*fila)->anterior = final;
    return SUCESSO;
}

// exibir
void fila_exibir ( fila fila ) {
    no_dup_enc *no = fila;

    if(no != NULL) {
        do {
            printf ("%d|", no->elemento );
            no = no->proximo;
        } while(no != fila);
    }
    printf("\n") ;
}

// ler
fila fila_ler() {
    fila l = NULL;
    int i, elemento, quantidade;

    printf("Quantos elementos deseja inserir ?");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        printf("fila[%d]= ", i);
        scanf("%d", &elemento);
        fila_inserir(elemento, &l);
    }

    return l;
}

// desalocar
void fila_desalocar(fila* fila) {
    no_dup_enc *no, *prx;
    
    if(fila != NULL) {
        if(*fila != NULL) {
            no = *fila;
            prx = no->proximo;

            do {
                free(no);
                no = prx;

                if(prx != *fila)
                    prx = prx->proximo;

            } while(no != *fila);
        }
    }
    *fila = NULL;
}

#endif
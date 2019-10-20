#ifndef FILA_SIMPLESMENTE_ENCADEADA_CIRCULARES_INTEIRO
#define FILA_SIMPLESMENTE_ENCADEADA_CIRCULARES_INTEIRO

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

    do {
        no = no->proximo;
        tamanho++;
    } while(no != fila);

    return tamanho;
}

// obter no
no_enc* fila_obter_no_elemento(int elemento, fila fila) {
    no_enc* no = fila;

    if(fila != NULL) {
        do{
            if(no->elemento == elemento)
                return no;
            no = no->proximo;
        } while( no != fila);
    }

    return NULL;
}

// inserir
int fila_inserir(int elemento, fila* fila) {
    no_enc * no, *novo;

    if(fila == NULL)
        return REFERENCIA_INCORRETA;

    if(fila_obter_no_elemento(elemento, *fila) != NULL)
        return ELEMENTO_EXISTENTE;
    
    novo = fila_criar_no(elemento);

    if(*fila == NULL)
        *fila = novo;
    else {
        no = *fila;

        // varre ate o final
        do {
            no = no->proximo;
        } while(no->proximo != *fila);

        no->proximo = novo;
    }
    novo->proximo = *fila;

    return SUCESSO;
}

// remover
int fila_remover(int elemento, fila* fila) {
    no_enc *no, *final;

    if(fila == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*fila == NULL)
        return FILA_VAZIA;
    
    final = *fila;

    do {
        final = final->proximo;
    } while(final->proximo != *fila);

    no = *fila;

    // fila contem somente um no
    if(no->proximo == *fila) {
        free(*fila);
        *fila = NULL;
    }
    
    // mais de um no
    else {
        no = no->proximo;
        free(*fila);
        *fila = no;
        final->proximo = *fila;
    }
}

// exibir
void fila_exibir(fila fila) {
    no_enc* no = fila;
    if(no != NULL) {
        do {
            printf("%d|", no->elemento);
            no = no->proximo;
        } while(no != fila);
    }
    printf("\n");
}

// ler
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

// desalocar
void fila_desalocar(fila* fila) {
    no_enc* no, *proximo;

    if(fila != NULL) {
        if(*fila != NULL) {
            no = *fila;
            proximo = no->proximo;

            do {
                free(no);
                no = proximo;
                if(proximo != *fila)
                    proximo = proximo->proximo;
            } while(no != *fila) ;
        }
    }

    *fila = NULL;
}

#endif
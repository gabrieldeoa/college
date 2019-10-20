#ifndef PILHA_SIMPLESMENTE_ENCADEADA_INTEIRO
#define PILHA_SIMPLESMENTE_ENCADEADA_INTEIRO

#include <stdio.h>
#include <stdlib.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define PILHA_VAZIA -5

/*** Estrutura ***/
typedef struct _no_enc no_enc;

typedef struct no_enc *pilha;

typedef struct _no_enc {
    int elemento;
    no_enc* proximo;
};

/*** Operações ***/

// criar
no_enc* pilha_criar_no(int dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    return no;
}

// numero de elementos
int pilha_numero_elementos(pilha pilha) {
    int tamanho = 0;
    no_enc* no = pilha;

    if(no == NULL)
        return 0;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no
no_enc* pilha_obter_no_elemento(int elemento, pilha pilha) {
    no_enc* no = pilha;

    while(no != NULL) {
        if(no->elemento == elemento)
            return no;
        no = no->proximo;
    }

    return NULL;
}

// inserir
int pilha_inserir(int elemento, pilha* pilha) {
    no_enc * no, *novo;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;

    if(pilha_obter_no_elemento(elemento, *pilha) != NULL)
        return ELEMENTO_EXISTENTE;
    
    novo = pilha_criar_no(elemento);

    if(*pilha == NULL)
        *pilha = novo;
    else {
        no = *pilha;

        // varre ate o final
        while(no->proximo != NULL)
            no = no->proximo;

        no->proximo = novo;
    }
    return SUCESSO;
}

// remover
int pilha_remover(pilha* pilha) {
    no_enc *no, *anterior;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*pilha == NULL)
        return PILHA_VAZIA;
    
    no = *pilha;

    // pilha contem somente um no
    if(no->proximo == NULL) {
        free(*pilha);
        *pilha = NULL;
    }
    
    // mais de um no
    else {
        anterior = no;
        no = no->proximo;
        while(no->proximo != NULL) {
            anterior = no;
            no = no->proximo;
        }

        free(no);
        anterior->proximo = NULL;
    }
    return SUCESSO;
}

//exibir
void pilha_exibir(pilha pilha) {
    no_enc* no = pilha;
    if(no != NULL) {
        while(no != NULL) {
            printf("%d|", no->elemento);
            no = no->proximo;
        }
    }
    printf("\n");
}

//ler
pilha pilha_ler() {
    pilha li = NULL;
    int i, elemento, quantidade;
    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        printf("pilha [%d]: ", i);
        scanf("%d", &elemento);
        pilha_inserir(elemento, &li);
    }

    return li;
}

//desalocar
void pilha_desalocar(pilha* pilha) {
    no_enc* no, *proximo;

    if(pilha != NULL) {
        if(*pilha != NULL) {
            no = *pilha;
            proximo = no->proximo;

            while(no != NULL) {
                free(no);
                no = proximo;
                if(proximo != NULL)
                    proximo = proximo->proximo;
            }
        }
    }

    *pilha = NULL;
}

#endif
#ifndef LISTA_DUPLAMENTE_ENCADEADA_VEICULO
#define LISTA_DUPLAMENTE_ENCADEADA_VEICULO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define LISTA_VAZIA -5
#define IGUAIS -6
#define DIFERENTES -7

/*** Estrutura ***/
typedef struct _no_dup_enc no_dup_enc;

typedef struct no_dup_enc* lista;

typedef struct {
    char placa[10];
    char marca[20];
    char modelo[40];
    int ano;
} veiculo;

typedef struct _no_dup_enc {
    veiculo elemento;
    no_dup_enc* proximo;
    no_dup_enc* anterior;
};

/*** Operações ***/

/** Auxiliares **/
int sao_veiculos_iguais(veiculo v1, veiculo v2) {
    return (strcmp(v1.placa, v2.placa) == 0) ? IGUAIS : DIFERENTES;
    
}

veiculo ler_veiculo() {
    veiculo veiculo;

    printf("\nplaca: ");
    scanf("\n");
    gets(veiculo.placa);

    printf("marca: ");
    scanf("\n");
    gets(veiculo.marca);

    printf("modelo: ");
    scanf("\n");
    gets(veiculo.modelo);

    printf("ano: ");
    scanf("%d", &veiculo.ano);

    return veiculo;

}

void exibir_veiculo(veiculo veiculo) {
    printf("\nplaca: %s", veiculo.placa);
    printf("\nmarca: %s", veiculo.marca);
    printf("\nmodelo: %s", veiculo.modelo);
    printf("\nano: %d", veiculo.ano);

}

/** Biblioteca **/
// criar
no_dup_enc* lista_criar_no(veiculo dado) {
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
no_dup_enc* lista_obter_no_elemento(veiculo elemento, lista lista) {
    no_dup_enc* no = lista;

    while(no != NULL) {
        if(sao_veiculos_iguais(no->elemento, elemento) == IGUAIS)
            return no;
        no = no->proximo;
    }

    return NULL;
}

// inserir
int lista_inserir(veiculo elemento, lista* lista) {
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
        while(no->proximo != NULL)
            no = no->proximo;
        
        no->proximo = novo;
        novo->anterior = no;
    }
    
    return SUCESSO;
}

// remover
int lista_remover(veiculo elemento, lista* lista) {
    no_dup_enc *no, *ant, *prx;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*lista == NULL)
        return LISTA_VAZIA;
    
    if(lista_obter_no_elemento(elemento, *lista) == NULL)
        return ELEMENTO_INEXISTENTE;
    
    no = *lista;

    // elemento e o primeiro no
    if(sao_veiculos_iguais(no->elemento, elemento) == IGUAIS) {
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
            if(sao_veiculos_iguais(no->elemento, elemento) == IGUAIS) {
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
        exibir_veiculo(no->elemento);
        printf("\n");
        no = no->proximo;
    }
    printf("\n") ;
}

// ler
lista lista_ler() {
    lista l = NULL;
    int i, quantidade;
    veiculo elemento;

    printf("Quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        elemento = ler_veiculo();
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
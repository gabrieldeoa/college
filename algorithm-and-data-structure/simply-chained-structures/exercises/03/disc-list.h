#ifndef LISTA_SIMPLESMENTE_ENCADEADA_CD
#define LISTA_SIMPLESMENTE_ENCADEADA_CD

#include <stdio.h>
#include <stdlib.h>

#define IGUAIS -10
#define DIFERENTES -11
#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define LISTA_VAZIA -5

/*** Estrutura ***/

typedef struct _no_enc no_enc;
typedef struct no_enc *lista;

typedef struct {
    int codigo;
    char titulo[40];
    char artista[40];
    int ano;
} cd;

typedef struct _no_enc {
    cd elemento;
    no_enc * proximo;
};

/*** OPERACAOES ***/

/* auxiliares */
int sao_cds_iguais(cd c1, cd c2) {
    return (c1.codigo == c2.codigo ) ? IGUAIS : DIFERENTES;
}

void exibir_cd(cd cd) {
    printf("\ncodigo: %d", cd.codigo);
    printf("\ntitulo: %s", cd.titulo);
    printf("\nartista: %s", cd.artista);
    printf("\nano: %d", cd.ano);

}

cd ler_cd() {
    cd cd;
    printf("\ncodigo: ");
    scanf("%d", &cd.codigo);

    printf("\ntitulo: ");
    scanf("\n");
    gets(cd.titulo);

    printf("\nartista: ");
    scanf("\n");
    gets(cd.artista);

    printf("\nano: ");
    scanf("%d", &cd.ano);
    printf("-------\n");

    return cd;
}

/* biblioteca */

// criar
no_enc* lista_cd_criar_no(cd dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    
    return no;
}

// número de elementos
int lista_cd_numero_elementos(lista lista) {
    int tamanho = 0;
    no_enc* no = lista;

    if(no == NULL) return 0;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no elemento
no_enc* lista_cd_obter_no_elemento(cd elemento, lista lista) {
    no_enc* no = lista;

    while(no != NULL) {
        if(sao_cds_iguais(no->elemento, elemento) == IGUAIS)
            return no;

        no = no->proximo;
    }
    return NULL;
}

// inserir
int lista_cd_inserir(cd elemento, lista* lista) {
    no_enc* no, *novo;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;

    if(lista_cd_obter_no_elemento(elemento , *lista) != NULL)
        return ELEMENTO_EXISTENTE;

    novo = lista_cd_criar_no(elemento) ;

    if(*lista == NULL)
        *lista = novo ;
    else {
        no = *lista ;

        //varre ate o final
        while (no->proximo != NULL)
            no = no->proximo;

        no->proximo = novo;
    }
    return SUCESSO;
}

// remover
int lista_cd_remover(cd elemento, lista* lista) {
    no_enc* no, *anterior;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*lista == NULL)
        return LISTA_VAZIA;

    if(lista_cd_obter_no_elemento(elemento, *lista) == NULL)
        return ELEMENTO_INEXISTENTE;
    
    no = *lista;

    //exclusao do primeiro no
    if(sao_cds_iguais(no->elemento, elemento) == IGUAIS) {
        no = no->proximo;
        free(*lista);
        *lista = no;
    }

    //exclusao a partir do segundo
    else {
        anterior = no;
        no = no->proximo;
        while(no != NULL) {
            if(sao_cds_iguais(no->elemento, elemento) == IGUAIS) {
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

//exibir
void lista_cd_exibir(lista lista) {
    no_enc* no = lista;
    int i = 1;
    if(no != NULL) {
        while(no != NULL) {
            printf("\nCD - %d", i);

            exibir_cd(no->elemento);

            printf("\n");

            no = no->proximo;

            i++;
        }
    }
    printf("\n");
}

//ler
lista lista_cd_ler() {
    lista li = NULL;
    cd elemento;
    int i, quantidade;

    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        elemento = ler_cd();
        lista_cd_inserir(elemento, &li);
    }

    return li;
}

//desalocar
void lista_cd_desalocar(lista* lista) {
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
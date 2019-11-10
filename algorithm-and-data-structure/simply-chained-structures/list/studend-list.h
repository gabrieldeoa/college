#ifndef LISTA_SIMPLESMENTE_ENCADEADA_ALUNO
#define LISTA_SIMPLESMENTE_ENCADEADA_ALUNO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char nome[40];
    char disciplina[40];
    int idade;
    float p1, p2;
} aluno;

typedef struct _no_enc {
    aluno elemento;
    no_enc * proximo;
};

/*** OPERACAOES ***/

/* auxiliares */
int sao_alunos_iguais(aluno a1, aluno a2) {
    return (strcmp(a1.nome, a2.nome) == 0) ? IGUAIS : DIFERENTES;
}

void exibir_aluno(aluno aluno) {
    printf("\n--- Aluno ---");
    printf("\nNome: ", aluno.nome);
    printf("\nIdade: ", aluno.idade);
    printf("\nDisciplina: ", aluno.disciplina);
    printf("\nP1: ", aluno.p1);
    printf("\nP2: ", aluno.p2);
}

aluno ler_aluno() {
    aluno aluno;

    printf("\nNome: ");
    gets(aluno.nome);

    printf("\nIdade: ");
    scanf("%d", &aluno.idade);

    printf("\nDisciplina: ");
    gets(aluno.disciplina);

    printf("\nP1: ");
    scanf("%f", &aluno.p1);

    printf("\nP2: ");
    scanf("%f", &aluno.p2);
    
    return aluno;
}

/* biblioteca */

// criar
no_enc* lista_aluno_criar_no(aluno dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    
    return no;
}

// número de elementos
int lista_aluno_numero_elementos(lista lista) {
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
no_enc* lista_aluno_obter_no_elemento(aluno elemento, lista lista) {
    no_enc* no = lista;

    while(no != NULL) {
        if(sao_alunos_iguais(no->elemento, elemento) == IGUAIS)
            return no;

        no = no->proximo;
    }
    return NULL;
}

// inserir
int lista_aluno_inserir(aluno elemento, lista* lista) {
    no_enc* no, *novo;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;

    if(lista_aluno_obter_no_elemento(elemento , *lista) != NULL)
        return ELEMENTO_EXISTENTE;

    novo = lista_aluno_criar_no(elemento) ;

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
int lista_aluno_remover(aluno elemento, lista* lista) {
    no_enc* no, *anterior;

    if(lista == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*lista == NULL)
        return LISTA_VAZIA;

    if(lista_aluno_obter_no_elemento(elemento, *lista) == NULL)
        return ELEMENTO_INEXISTENTE;
    
    no = *lista;

    //exclusao do primeiro no
    if(sao_alunos_iguais(no->elemento, elemento) == IGUAIS) {
        no = no->proximo;
        free(*lista);
        *lista = no;
    }

    //exclusao a partir do segundo
    else {
        anterior = no;
        no = no->proximo;
        while(no != NULL) {
            if(sao_alunos_iguais(no->elemento, elemento) == IGUAIS) {
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
void lista_aluno_exibir(lista lista) {
    no_enc* no = lista;
    if(no != NULL) {
        while(no != NULL) {
            exibir_aluno(no->elemento);
            no = no->proximo;
        }
    }
    printf("\n");
}

//ler
lista lista_aluno_ler() {
    lista li = NULL;
    aluno elemento;
    int i, quantidade;

    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        elemento = ler_aluno();
        lista_aluno_inserir(elemento, &li);
    }

    return li;
}

//desalocar
void lista_aluno_desalocar(lista* lista) {
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
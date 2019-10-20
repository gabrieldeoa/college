#ifndef FILA_SIMPLESMENTE_ENCADEADA_ALUNO
#define FILA_SIMPLESMENTE_ENCADEADA_ALUNO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IGUAIS -10
#define DIFERENTES -11
#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define FILA_VAZIA -5

/*** Estrutura ***/

typedef struct _no_enc no_enc;
typedef struct no_enc *fila;

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
}

/* biblioteca */

// criar
no_enc* fila_aluno_criar_no(aluno dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    
    return no;
}

// número de elementos
int fila_aluno_numero_elementos(fila fila) {
    int tamanho = 0;
    no_enc* no = fila;

    if(no == NULL) return 0;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no elemento
no_enc* fila_aluno_obter_no_elemento(aluno elemento, fila fila) {
    no_enc* no = fila;

    while(no != NULL) {
        if(sao_alunos_iguais(no->elemento, elemento) == IGUAIS)
            return no;

        no = no->proximo;
    }
    return NULL;
}

// inserir
int fila_aluno_inserir(aluno elemento, fila* fila) {
    no_enc* no, *novo;

    if(fila == NULL)
        return REFERENCIA_INCORRETA;

    if(fila_aluno_obter_no_elemento(elemento , *fila) != NULL)
        return ELEMENTO_EXISTENTE;

    novo = fila_aluno_criar_no(elemento) ;

    if(*fila == NULL)
        *fila = novo ;
    else {
        no = *fila ;

        //varre ate o final
        while (no->proximo != NULL)
            no = no->proximo;

        no->proximo = novo;
    }
    return SUCESSO;
}

// remover
int fila_aluno_remover(fila* fila) {
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
}

// exibir
void fila_aluno_exibir(fila fila) {
    no_enc* no = fila;
    if(no != NULL) {
        while(no != NULL) {
            exibir_aluno(no->elemento);
            no = no->proximo;
        }
    }
    printf("\n");
}

// ler
fila fila_aluno_ler() {
    fila li = NULL;
    aluno elemento;
    int i, quantidade;

    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        elemento = ler_aluno();
        fila_aluno_inserir(elemento, &li);
    }

    return li;
}

// desalocar
void fila_aluno_desalocar(fila* fila) {
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
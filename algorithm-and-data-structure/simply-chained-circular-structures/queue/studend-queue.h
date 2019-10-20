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

    if(no == NULL)
        return 0;

    do {
        no = no->proximo;
        tamanho++;
    } while(no != fila);

    return tamanho;
}

// obter no elemento
no_enc* fila_aluno_obter_no_elemento(aluno elemento, fila fila) {
    no_enc* no = fila;

    do {
        if(sao_alunos_iguais(no->elemento, elemento) == IGUAIS)
            return no;
        no = no->proximo;
    } while(no != *fila);

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
        do {
            no = no->proximo;
        } while (no->proximo != *fila);

        no->proximo = novo;
    }
    novo->proximo = *fila;

    return SUCESSO;
}

// remover
int fila_aluno_remover(aluno elemento, fila* fila) {
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

//exibir
void fila_aluno_exibir(fila fila) {
    no_enc* no = fila;
    if(no != NULL) {
        do {
            exibir_aluno(no->elemento);
            no = no->proximo;
        } while(no != *fila);
    }
    printf("\n");
}

//ler
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
            } while(no != *fila);
        }
    }

    *fila = NULL;
}

#endif
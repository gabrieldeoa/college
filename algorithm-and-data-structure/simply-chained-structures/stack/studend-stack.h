#ifndef PILHA_SIMPLESMENTE_ENCADEADA_ALUNO
#define PILHA_SIMPLESMENTE_ENCADEADA_ALUNO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IGUAIS -10
#define DIFERENTES -11
#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define ELEMENTO_INEXISTENTE -3
#define SUCESSO -4
#define PILHA_VAZIA -5

/*** Estrutura ***/

typedef struct _no_enc no_enc;
typedef struct no_enc *pilha;

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
no_enc* pilha_aluno_criar_no(aluno dado) {
    no_enc* no = malloc(sizeof(no_enc));
    no->elemento = dado;
    no->proximo = NULL;
    
    return no;
}

// número de elementos
int pilha_aluno_numero_elementos(pilha pilha) {
    int tamanho = 0;
    no_enc* no = pilha;

    if(no == NULL) return 0;

    while(no != NULL) {
        no = no->proximo;
        tamanho++;
    }

    return tamanho;
}

// obter no elemento
no_enc* pilha_aluno_obter_no_elemento(aluno elemento, pilha pilha) {
    no_enc* no = pilha;

    while(no != NULL) {
        if(sao_alunos_iguais(no->elemento, elemento) == IGUAIS)
            return no;

        no = no->proximo;
    }
    return NULL;
}

// inserir
int pilha_aluno_inserir(aluno elemento, pilha* pilha) {
    no_enc* no, *novo;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;

    if(pilha_aluno_obter_no_elemento(elemento , *pilha) != NULL)
        return ELEMENTO_EXISTENTE;

    novo = pilha_aluno_criar_no(elemento) ;

    if(*pilha == NULL)
        *pilha = novo ;
    else {
        no = *pilha ;

        //varre ate o final
        while (no->proximo != NULL)
            no = no->proximo;

        no->proximo = novo;
    }
    return SUCESSO;
}

// remover
int pilha_aluno_remover(pilha* pilha) {
    no_enc* no, *anterior;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    
    if(*pilha == NULL)
        return PILHA_VAZIA;
    
    no = *pilha;

    //pilha contem somente um no
    if(no->proximo == NULL) {
        free(*pilha);
        *pilha = NULL;
    }
    
    //mais de um no
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

// exibir
void pilha_aluno_exibir(pilha pilha) {
    no_enc* no = pilha;
    if(no != NULL) {
        while(no != NULL) {
            exibir_aluno(no->elemento);
            no = no->proximo;
        }
    }
    printf("\n");
}

// ler
pilha pilha_aluno_ler() {
    pilha li = NULL;
    aluno elemento;
    int i, quantidade;

    printf("Informe quantos elementos deseja inserir: ");
    scanf("%d", &quantidade);
    
    for(i = 0; i < quantidade; i++) {
        elemento = ler_aluno();
        pilha_aluno_inserir(elemento, &li);
    }

    return li;
}

// desalocar
void pilha_aluno_desalocar(pilha* pilha) {
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
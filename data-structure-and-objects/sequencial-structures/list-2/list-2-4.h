#ifndef LISTA_ALUNOS
#define LISTA_ALUNOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

typedef struct TAluno{
    char nome[40];
    int idade;
    char disciplina[40];
    float p1;
    float p2;
} Aluno;

// Operação

void exibir_aluno(Aluno p) {
    printf(
        " Nome: %s\n Idade: %d\n disciplina: %s\n p1: %.2f\n p2: %.2f",
        p.nome,
        p.idade,
        p.disciplina,
        p.p1,
        p.p2
    );
}

Aluno preencher_aluno() {
    Aluno aluno;

    printf("\n Nome: ");
    scanf("\n", &aluno.nome);
    gets(aluno.nome);

    printf(" Idade: ");
    scanf("%d", &aluno.idade);

    printf(" Disciplina: ");
    scanf("\n", &aluno.disciplina);
    gets(aluno.disciplina);

    printf(" p1: ");
    scanf("%f", &aluno.p1);

    printf(" p2: ");
    scanf("%f", &aluno.p2);

    return aluno;
}


Aluno** lista_aluno_criar(int tam) {
    Aluno** lista;
    lista = calloc(tam, sizeof(Aluno*[tam]));
    return lista;
}

int lista_aluno_numero_elementos(Aluno **lista, int tam) {
    int i;

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    for(i = 0; i < tam; i++)
        if(lista[i] == NULL)
            return i;

    return tam;
}

int lista_aluno_posicao_elemento(Aluno elemento, Aluno **lista, int tam) {
    int i, totalElementos;

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    totalElementos = lista_aluno_numero_elementos(lista, tam);

    for(i = 0; i < totalElementos; i++)
        if(strcmp(lista[i]->nome, elemento.nome) == 0)
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

Aluno lista_aluno_obter_elemento(int pos, Aluno** lista) {
    return *(lista[pos]);
}

int lista_aluno_inserir(Aluno elemento, Aluno **lista, int tam) {
    int i, totalElementos, posicaoElemento;

    totalElementos = lista_aluno_numero_elementos(lista, tam);

    if(totalElementos >= tam ) return LISTA_CHEIA;

    posicaoElemento = lista_aluno_posicao_elemento(elemento, lista, tam);

    if(posicaoElemento != ELEMENTO_NAO_EXISTENTE) return ELEMENTO_EXISTENTE;

    lista[totalElementos] = malloc(sizeof(Aluno));

    *(lista[totalElementos]) = elemento;

    return SUCESSO;
}

void lista_aluno_exibir(Aluno **lista, int tam) {
    int i;

    printf("\n----- LISTANDO DADOS DE ALUNOS -----\n");

    for(i = 0; i < tam; i++) {
        if(lista[i] != NULL) {
            printf("\nAluno[%d]", i);
            exibir_aluno(*(lista[i]));
        }
        else
            printf("N|");
    }
}

Aluno** lista_aluno_ler(int tam, int qtd_elems) {
    int i;
    Aluno elemento, ** lista;

    lista = lista_aluno_criar(tam);

    printf("\n----- CAPTURANDO DADOS DE ALUNOS -----\n");

    for(i = 0; i < qtd_elems || i < tam; i++) {
        printf("\nALUNOS[%d]", i);
        elemento = preencher_aluno();

        lista_aluno_inserir(elemento, lista, tam);
    }
    return lista;
}

void lista_aluno_destruir(Aluno** lista, int tam) {
    int i;

    for(i = 0; i < tam; i++) free(lista[i]);

    free(lista);
}

float lista_aluno_media_das_medias(Aluno **lista, int tam) {
    float media_aluno = 0, media_todos_alunos = 0;
    int totalElementos, i;
    totalElementos = lista_aluno_numero_elementos(lista, tam);

    for(i = 0; i < totalElementos; i++) {
        media_aluno = (lista[i]->p1 + lista[i]->p2)/2;
        media_todos_alunos += media_aluno;
    }

    return media_todos_alunos/totalElementos;
}

#endif

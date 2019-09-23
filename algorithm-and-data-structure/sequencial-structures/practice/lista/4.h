/*
Escreva uma biblioteca que contenha a representação computacional e as operações
para manipulação de uma lista de Aluno
*/

#ifndef LISTA_ALUNO
#define LISTA_ALUNO

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define ELEMENTO_EXISTENTE -2
#define LISTA_NAO_ALOCADA -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

#define IGUAL 0
#define MAIOR 1
#define MENOR -1

/*
    REPRESENTACAO
    <tipo> **variavel

    Aluno **lista;
*/

/* DEFINICAO DO TIPO ALUNO */

typedef struct {
    char nome[40];
    int idade;
    char disciplina[20];
    float p1;
    float p2;
} aluno;

/* FUNCOES AUXILIARES ALUNO */

int aluno_iguais(aluno aluno_um, aluno aluno_dois) {
    
    int cmp = strcmp(aluno_um.nome, aluno_dois.nome);

    if(cmp == 0) return IGUAL;
    else if(cmp > 0) return MAIOR;
    else return MENOR;
}

void aluno_exibir(aluno aluno) {
    printf(
        "|NOME: %s, IDADE: %d, DISCIPLINA: %s, P1: %.2f, P2: %.2f|\n",
        aluno.nome,
        aluno.idade,
        aluno.disciplina,
        aluno.p1,
        aluno.p2
    );
}

aluno aluno_ler() {
    aluno aluno;
    printf("\nNOME:");
    scanf("\n");
    gets(aluno.nome);
    printf("DISCIPLINA:");
    gets(aluno.disciplina);
    printf("IDADE: ");
    scanf("%d",&aluno.idade);
    printf("P1: ");
    scanf("%f",&aluno.p1);
    printf("P2: ");
    scanf("%f",&aluno.p2);
    printf("\n");

    return aluno;
}

/* OPERACOES DE LISTA */

//criar
aluno ** lista_criar(int tam) {
    aluno **lista;
    lista = calloc(tam, sizeof(aluno*[tam]));
    return lista;
}

//numero de elementos
int lista_numero_elementos(aluno **lista, int tam) {
    int i;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;
    
    for(i = 0; i < tam; i++) {
        if(lista[i] == NULL)
            return i;
    }

    return tam;
}

//posicao elemento
int lista_posicao_elemento(aluno elemento, aluno **lista, int tam) {
    int i, ne;

    ne = lista_numero_elementos(lista, tam);

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;
    
    for(i = 0; i < ne; i++)
        if( aluno_iguais(*(lista[i]), elemento) == IGUAL)
            return i;
    
    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
aluno lista_obter_elemento(int posicao, aluno **lista) {
    return *(lista[posicao]);
}

//inserir
int lista_inserir(aluno elemento, aluno **lista, int tam) {
    int ne, pos;

    ne = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam);

    if(ne >= tam)
        return LISTA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    lista[ne] = malloc(sizeof(aluno));
    *(lista[ne]) = elemento;

    return SUCESSO;
}

//remover
int lista_remover(aluno elemento, aluno **lista, int tam) {
    int i, ne, pos;

    ne = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam);

    if(ne <= 0)
        return LISTA_VAZIA;
    
    if(pos == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;
    
    free(lista[pos]);

    for( i = pos; i < ne; i++) {
        lista[i] = lista[i + 1];
    }

    lista[i] = NULL;

    return SUCESSO;
}

//exibir
void lista_exibir(aluno **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        if(lista[i] != NULL)
            aluno_exibir(*(lista[i]));
        else
            printf("N|");
    }
    printf("\n");
}

//ler
aluno** lista_ler(int tam) {
    int i, qtd;
    aluno elemento, **lista;
    lista = lista_criar(tam);

    printf("Informe a quantidade de elementos a ser inserida: ");
    scanf("%d", &qtd);

    for(i = 0; i < qtd && i < tam; i++) {
        printf("Lista[%d] = ", i);
        elemento = aluno_ler();
        lista_inserir(elemento, lista, tam);
    }

    return lista;
}

//destruir
void lista_destruir(aluno **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++)
        free(lista[i]);
    
    free(lista);
}

#endif
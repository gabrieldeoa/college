
/*
Uma outra forma de implementarmos uma fila é mantermos o seu início sempre na
posição 0 e só deslocarmos o seu fim.

Para isso é preciso que quando haja uma exclusão, todos os elementos, exceto
o inicio, sejam deslocados uma posição para trás. Naturalmente, as rotinas de
inserção, remoção, contagem, busca e exibição podem precisar de alterações.

Escreva uma biblioteca que contenha a representação computacional e as operações
para manipulação para este modelo de fila.
*/

#ifndef FILA_INTEIROS_SIMPLIFICADA
#define FILA_INTEIROS_SIMPLIFICADA

#include <stdio.h>
#include <stdlib.h>

#define FILA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define FILA_CHEIA -4
#define FILA_VAZIA -5
#define SUCESSO -6

/* REPRESENTACAO */
//NAO TEM INICIO PQ ELE SEMPRE SERA A POSICAO 0
typedef struct {
    int * elementos;
    int fim, tamanho;
} fila;

/* OPERACAOES */

//criar
void fila_criar(fila *f, int tam) {
    f->elementos = malloc(sizeof(int [tam]));
    f->fim = -1;
    f->tamanho = tam;
}

//numero elementos
int fila_numero_elementos(fila f) {
    return f.fim + 1;
}

//posicao elemento
int fila_posicao_elemento(int elemento, fila f) {
    int i, ne;
    ne = fila_numero_elementos(f);

    for(i = 0; i < ne; i++)
        if(f.elementos[i] == elemento)
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
int fila_obter_elemento(int posicao, fila f) {
    return f.elementos[posicao];
}

//inserir
int fila_inserir(int elemento, fila *f) {
    int ne, pos;

    ne = fila_numero_elementos(*f);
    pos = fila_posicao_elemento(elemento, *f);

    if(ne >= f->tamanho)
        return FILA_CHEIA;
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    f->fim++;
    f->elementos[f->fim] = elemento;

    return SUCESSO;
}

//remover
int fila_remover(fila *f) {
    int ne, i;
    ne = fila_numero_elementos(*f);

    if(ne <= 0)
        return FILA_VAZIA;
    //EXCLUSAO
    f->fim--;
    // EXCLUI O INICIO SUBSTITUINDO O VALOR DO MESMO REORDERNANDO A FILA
    for(i = 0; i < ne -1; i++)
        f->elementos[i] = f->elementos[i + 1];
    
    return SUCESSO;
}

//exibir
void fila_exibir(fila f) {
    int i, ne;
    ne = fila_numero_elementos(f);

    for(i = 0; i < ne; i++)
        printf("%d |", f.elementos[i]);
    
    printf("\n");
}

//ler
void fila_ler(fila *f, int tam, int qtd) {
    int i, elemento;

    fila_criar(f, tam);

    for(i = 0; i < qtd && i < tam; i++) {
        printf("Fila[%d] = ", i);
        scanf("%d", &elemento);
        fila_inserir(elemento, f);
    }
}

//destrui
void fila_destruir(fila *f) {
    free(f->elementos);
    f->elementos = NULL;
    f->fim = f->tamanho = FILA_NAO_ALOCADA;
}

#endif
#ifndef FILA_INTEIROS
#define FILA_INTEIROS

#include <stdio.h>
#include <stdlib.h>

#define FILA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define FILA_CHEIA -4
#define FILA_VAZIA -5
#define SUCESSO -6

/* REPRESENTACAO */
typedef struct {
    int * elementos;
    int inicio, fim, tamanho;
} fila;

/* OPERACAOES */

//criar
void fila_criar(fila *f, int tam) {
    f->elementos = malloc(sizeof(int [tam]));
    f->tamanho = tam;
    f->inicio = f->fim = -1;
}

//numero elementos
int fila_numero_elementos(fila f) {
    int intervalo = f.fim - f.inicio;

    if(f.inicio == -1 || f.fim == -1)
        return 0;

    if(f.inicio <= f.fim)
        return intervalo + 1;
    
    return intervalo + f.tamanho + 1;
}

//posicao elemento
int fila_posicao_elemento(int elemento, fila f) {
    int i, j, ne;

    ne = fila_numero_elementos(f);

    j = f.inicio;

    for(i = 0; i < ne; i++) {
        if(f.elementos[j] == elemento)
            return j;

        if(j == f.tamanho - 1)
            j = 0;
        else
            j++;
    }
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

    if( ne >= f->tamanho)
        return FILA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    if(f->fim == -1) // SE A FILA ESTIVER VAZIA
        f->inicio = f->fim = 0;
    else if(f->fim == f->tamanho -1)//se o fim ta no final mas tem espaço no começo
        f->fim = 0;
    else // caso comum onde basta incrementar o fim
        f->fim++;

    f->elementos[f->fim] = elemento;

    return SUCESSO;
}

//excluir
int fila_remover(fila *f) {
    int ne;
    ne = fila_numero_elementos(*f);

    if(ne <= 0)
        return FILA_VAZIA;
    if(f->inicio == f->fim) // so possui um elemento na fila
        f->inicio = f->fim = -1;
    else if(f->inicio == f->tamanho - 1) // o primeiro elemento esta no final
        f->inicio = 0;
    else 
        f->inicio++;
    
    return SUCESSO;
}

//exibir
void fila_exibir(fila f) {
    int i, j, ne;

    ne = fila_numero_elementos(f);
    j = f.inicio;

    for(i = 0; i < ne; i++) {
        printf("%d |", f.elementos[j]);
        
        if(j == f.tamanho -1)   
            j = 0;
        else
            j++;
    }
    printf("\n");
}

//ler
void fila_ler(fila *f, int tam, int qtd) {
    int i, elemento;

    fila_criar(f, tam);

    for(i = 0; i < qtd && i < tam; i++) {
        printf("fila[%d] = ", i);
        scanf("%d", &elemento);
        fila_inserir(elemento, f);
    }
}

//destruir
void fila_destruir(fila *f) {
    free(f->elementos);
    f->elementos;
    f->inicio = f->fim = f->tamanho = FILA_NAO_ALOCADA;
}

#endif
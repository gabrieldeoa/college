#ifndef FILA_CLIENTE
#define FILA_CLIENTE

#include <stdio.h>
#include <stdlib.h>

#define FILA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define FILA_CHEIA -4
#define FILA_VAZIA -5
#define SUCESSO -6

#define IGUAL 0
#define DIFERENTE -1

/* DEFINICAO DE TIPO */
typedef struct {
    char nome[40];
    int codigo, idade, preferencial;
} cliente;

/* FUNCOES AUXILIARES DE TIPO */
int cliente_comparar(cliente c1, cliente c2) {
    if(c1.codigo == c2.codigo) {
        return IGUAL;
    }

    return DIFERENTE;
}

void cliente_exibir(cliente cliente) {
    printf(
        "|CODIGO: %d, NOME: %s, IDADE: %d, PREFERENCIAL: %s|\n",
        cliente.codigo,
        cliente.nome,
        cliente.idade,
        (cliente.preferencial) ? "SIM" : "NAO"
    );
}

cliente cliente_ler() {
    cliente c;

    printf("CODIGO:");
    scanf("%d",&c.codigo);
    printf("NOME: ");
    scanf("\n");
    gets(c.nome);
    printf("IDADE: ");
    scanf("%d",&c.idade);
    printf("PREFERENCIAL [0-NAO|1-SIM]: ");
    scanf("%d",&c.preferencial);

    return c;
}

/* REPRESENTACAO */
typedef struct {
    cliente *elementos;
    int inicio, fim, tamanho;
} fila;

/* OPERACAOES */
//criar
void fila_criar(fila *f, int tam) {
    f->elementos = malloc(sizeof(cliente[tam]));
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
int fila_posicao_elemento(cliente elemento, fila f) {
    int i, j, ne;
    ne = fila_numero_elementos(f);
    j = f.inicio;

    for(i = 0; i < ne; i++) {
        if(cliente_comparar(f.elementos[j], elemento) == IGUAL)
            return j;
        if(f.fim == f.tamanho -1)
            j = 0;
        else
            j++;
    }
    
    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
cliente fila_obter_elemento(int posicao, fila f) {
    return f.elementos[posicao];
}

//inserir
int fila_inserir(cliente elemento, fila *f) {
    int ne, pos;
    ne = fila_numero_elementos(*f);
    pos = fila_posicao_elemento(elemento, *f);

    if(ne >= f->tamanho)
        return FILA_CHEIA;

    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    if(f->fim == -1)//FILA VAZIA
        f->inicio = f->fim = 0;
    else if(f->fim == f->tamanho -1)
        f->fim = 0;
    else
        f->fim++;
    
    f->elementos[f->fim] = elemento;
    return SUCESSO;
}

//remover
int fila_remover(fila *f) {
    int ne;
    ne = fila_numero_elementos(*f);

    if(ne <= 0)
        return FILA_VAZIA;

    if(f->inicio == f->fim)
        f->inicio = f->fim = -1;

    else if(f->inicio == f->tamanho -1)
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
        cliente_exibir(f.elementos[j]);

        if(f.fim == f.tamanho -1)
            j = 0;
        else
            j++;
    }
    printf("\n");
}

//ler
void fila_ler(fila *f, int tam, int qtd) {
    int i;
    cliente elemento;

    fila_criar(f, tam);

    for(i = 0; i < tam && i < qtd; i++) {
        printf("fila[%d] = ", i);
        elemento = cliente_ler();
        fila_inserir(elemento, f);
    }
}

//destrui
void fila_destruir(fila *f) {
    free(f->elementos);
    f->elementos = NULL;
    f->inicio = f->fim = f->tamanho = FILA_NAO_ALOCADA;
}

#endif
#ifndef FILA_DE_INTEIROS
#define FILA_DE_INTEIROS

#include <stdio.h>
#include <stdlib.h>

#define FILA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define FILA_CHEIA -4
#define FILA_VAZIA -5
#define SUCESSO -6

/*
    Biblioteca para se trabalhar com fila sequencial de inteiros.
    OBS: Anotações somente para ajudar a entender e lembrar o passo-a-passo do algoritmo.
*/

/*
    REPRESENTACAO

    typedef struct {
        <TIPO>*  <IDENTIFICADOR>
        int inicio, fim, tamanho;
    } <NOME>;

    EXEMPLO

    typedef struct {
        int*  elementos
        int inicio, fim, tamanho;
    } fila;
*/

/* DEFINICAO TIPOS */
typedef struct {
    int*  elementos;
    int inicio, fim, tamanho;
} Fila;
/*-- FIM DEFINICAO TIPOS --*/



// CRIACAO DE FILA - dado a fila e o tamanho cria-se a fila por referencia.
void fila_criar(Fila* f, int tam) {
    f->elementos = malloc(sizeof(int[tam]));
    f->inicio = f->fim = -1;
    f->tamanho = tam;
}

// CONTAGEM DE ELEMENTOS - dado uma fila retorna a qtd de elementos validos na mesma.
int fila_numero_elementos(Fila f) {
    int intervalo = f.fim - f.inicio;

    if(f.inicio == -1 || f.fim == -1) return 0;

    if(f.inicio <= f.fim) return intervalo + 1;

    return intervalo + f.tamanho + 1;
    
}

// OBTER POSICAO DE UM ELEMENTO - dado uma elemento, a fila retorna o posicao do elemento.
int fila_posicao_elemento(int elem, Fila f) {
    int i, j, num_elems; 
    num_elems = fila_numero_elementos(f);
    j = f.inicio;
    for(i = 0; i < num_elems; i++) {
        if(f.elementos[j] == elem) return j;

        if(j == f.tamanho - 1)
            j = 0;
        else
            j++;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

// OBTER UM ELEMENTO NA FILA - dada a posicao e a FILA retorna o elemento(seu conteudo)
int fila_obter_elemento( int pos , Fila f ) {
    return f.elementos[ pos ];
}

//INSERIR UM ELEMENTO NA FILA - dado o elemento e a fila insere um elemento e retorna flag de sucesso
int fila_inserir(int elem, Fila* f) {
    int i, num_elems;
    num_elems = fila_numero_elementos(*f);

    if(num_elems >= f->tamanho) 
        return FILA_CHEIA;

    if(fila_posicao_elemento(elem, *f) != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    if(f->fim == -1)// fila vazia
        f->inicio = f->fim = 0;
    else if (f->fim == f->tamanho - 1)
        f->fim = 0;
    else
        f->fim++;

    f->elementos[ f->fim ] = elem;

    return SUCESSO


   
}

//REMOVER ELEMENTO - dada fila remover o elemento primeiro e retorna flag de sucesso
int fila_remover(Fila* f) {
    int i, num_elems;
    num_elems = fila_numero_elementos(*f);

    if(num_elems <= 0) 
        return FILA_VAZIA;

    if(f->inicio == f->fim)
        f->inicio = f->fim = -1;
    
    if(f->inicio == f->tamanho)
        f->inicio = 0;
    else
        f->inicio++;
    
    return SUCESSO;

}

// EXIBIR UMA FILA  - dado a fila printa-se seu conteudo
void fila_exibir(Fila f) {
    int i, j, num_elems;
    num_elems = fila_numero_elementos(f);
    
    j = f.inicio;
    for(i = 0; i < num_elems; i++) {
        printf("%d|", f.elementos[j]);
        if(j == f.tamanho - 1)
            j = 0;
        else 
            j++; 
    }
    printf("\n");
}

// LER UMA  - dado um tamanho maximo da fila e a quantidade de elementos que espera-se ler retorna a fila preenchida
void fila_ler ( Fila* f , int tam , int qtd_elems ) {
    int i , elem ;fila_criar (f , tam );

    for( i = 0; i < qtd_elems || i < tam ; i ++) {
        printf (" FILA [%d]= ",i ) ;
        scanf ("%d" ,&elem ) ;
        fila_inserir (elem , f ) ;
    }
}

// DESTRUIR UMA fila - dado a fila e seu tamanho a desaloca da memoria
void fila_destruir (Fila * f ) {
    free(f -> elementos ) ;
    f-> elementos = NULL ;
    f-> inicio = f-> fim = f-> tamanho = FILA_NAO_ALOCADA ;
}

#endif
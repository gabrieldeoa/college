/*
    Contrua uma rotina que amplie o tamanho máximo de uma lista já existente,
    preservando os valores presentes nela.

    Para isso, aloque uma nova lista com o tamanho desejado e transfira os valores da
    lista existente para ela e lembre-se de eliminar a lista antiga.
*/
#include <stdio.h>
#include <stdlib.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

int ** lista_criar(int tam) {
    int **lista;
    lista = calloc(tam, sizeof(int*[tam]));
    return lista;
}

int lista_numero_elementos(int **lista, int tam) {
    int i;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;
    
    for(i = 0; i < tam; i++) {
        if(lista[i] == NULL)
            return i;
    }

    return tam;
}

int lista_posicao_elemento(int elem, int **lista, int tam) {
    int i, num_elemes;

    num_elemes = lista_numero_elementos(lista, tam);

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    for(i = 0; i <  num_elemes; i++) {
        if(*(lista[i]) == elem)
            return i;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

int lista_obter_elemento(int pos, int** lista) {
    return *(lista[pos]);
}

int lista_inserir(int elemento, int **lista, int tam) {
    int i, num_elems, posicao_elemento;
    
    num_elems = lista_numero_elementos(lista, tam);
    posicao_elemento = lista_posicao_elemento(elemento, lista, tam);

    if(num_elems  >= tam) 
        return LISTA_CHEIA;
    
    if(posicao_elemento != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    lista[num_elems] = malloc(sizeof(int));
    *(lista[num_elems]) = elemento;

    return SUCESSO;
    
}

int lista_remover(int elemento, int **lista, int tam) {
    int i, num_elems, pos;

    num_elems = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam);

    if(num_elems <= 0)
        return LISTA_VAZIA;

    if(pos == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    //remocao
    free(lista[pos]);

    // caso que realoca a lista deixando sequencial
    for( i = pos; i < num_elems; i++) {
        lista[i] = lista[i + 1];
    }
    
    lista[i] = NULL;
}

void lista_exibir(int **lista, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        if(lista[i] != NULL)
            printf("%d|", *(lista[i]));
        else
            printf("N|");
    }
    printf("\n");
}

int** lista_ler(int tam, int qtd_elems) {
    int i, elem, **lista;

    lista = lista_criar(tam);

    for(i = 0; i < qtd_elems && i < tam; i++) {
        printf("Lista[%d]: ", i);
        scanf("%d", &elem);
        lista_inserir(elem, lista, tam);
    }

    return lista;
}

void lista_destruir(int** lista, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        free(lista[i]);
    }
    free(lista);
}



// QUESTAO 2
int** lista_realocar(int** lista, int tam, int novo_tam) {
    int** novaLista = lista_criar(novo_tam);
    int i, elemento;
    for(i = 0; i < tam; i++ ) {
        if(lista[i] != NULL)
            elemento = *(lista[i]);
            lista_inserir(elemento, novaLista, novo_tam);
    }

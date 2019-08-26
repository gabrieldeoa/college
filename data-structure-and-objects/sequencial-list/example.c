#include <stdio.h>
#include <stdlib.h>

const LISTA_NAO_ALOCADA = -1;
const ELEMENTO_NAO_EXISTENTE = -1;
const ELEMENTO_EXISTENTE = -1;
const LISTA_CHEIA = -1;
const LISTA_VAZIA = -1;
const SUCESSO = -1;

int** criarLista(int tam) {
    int **lista, i;

    lista = calloc(tam, sizeof(int*[tam]));

    return lista;
}

// extra
int tamanhoDaListaRecursivo(int **lista, int tam) {
    if(lista == NULL)
        return LISTA_NAO_ALOCADA;
    else if(lista[tam] == NULL)
        return tam;
    else
        tamanhoDaListaRecursivo(lista, tam - 1);
}

int tamanhoDaLista(int **lista, int tam) {
    int i;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    for(i=0; i < tam; i++)
        if(lista[i] == NULL)
            return i;
    
    return tam;
}

int posicaoDoElemento(int elemento, int** lista, int tam) {
    int i, totalElementos;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    totalElementos = tamanhoDaLista(lista, tam);

    for(i=0; i < totalElementos; i++)
        if(*(lista[i]) == elemento)
            return i;
    
    return ELEMENTO_NAO_EXISTENTE;
}

int inserirElemento(int elemento, int** lista, int tam) {
    int i, totalElementos, posicaoElemento;

    totalElementos = tamanhoDaLista(lista, tam);

    if(totalElementos >= tam )
        return LISTA_CHEIA;
    
    posicaoElemento = posicaoDoElemento(elemento, lista, tam);

    if(posicaoElemento != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    lista[totalElementos] = malloc(sizeof(int));

    *(lista[totalElementos]) = elemento;

    return SUCESSO;


}

int removerElemento(int elemento, int** lista, int tam) {
    int i, posicao, totalElementos;

    totalElementos = tamanhoDaLista(lista, tam);
    posicao = posicaoDoElemento(elemento, lista, tam);

    if(totalElementos <= 0)
        return LISTA_VAZIA;

    if(posicao == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    free(lista[posicao]);

    for(i = posicao; i < totalElementos-1; i++)
        lista[i] = lista[i + 1];
    
    lista[i] = NULL;

    return SUCESSO;
}

void exibirLista(int **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++)
        if(lista[i] != NULL)
            printf("%d|", *(lista[i]));
        else
            printf("N|");
    printf("\n");
}

int** lerLista(int tam) {
    int i, elemento, ** lista;

    lista = criarLista(tam);

    for(i=0; i < tam; i++) {
        printf("LISTA[%d] = ", i);
        scanf("%d", &elemento);

        if(elemento == '\0')
            return lista;
        
        inserirElemento(elemento, lista, tam);
    }
    
    return lista;
}

void destruirFila(int** lista, int tam) {
    int i;

    for(i=0; i < tam; i++)
        free(lista[i]);

    free(lista);
}
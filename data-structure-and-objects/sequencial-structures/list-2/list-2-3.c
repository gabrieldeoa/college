#include <stdio.h>
#include <stdlib.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

int** lista_criar(int tam) {
    int **lista;
    lista = calloc(tam, sizeof(int*[tam]));
    return lista;
}

int lista_numero_elementos(int **lista, int tam) {
    int i;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    for(i = 0; i < tam; i++)
        if(lista[i] == NULL)
            return i;

    return tam;
}

int lista_posicao_elemento(int elemento, int **lista, int tam, int ordenada) {
    int i, num_elems, inicio, fim, posicao;
    num_elems = lista_numero_elementos(lista, tam);

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    if(ordenada) {
        posicao = num_elems/2;

        if(elemento < 1 || elemento > tam)
            return ELEMENTO_NAO_EXISTENTE;

        while(1) {
            if(*(lista[posicao]) == elemento)
                return posicao;

            if(elemento > *(lista[posicao]))
                inicio = posicao;
            else
                fim = posicao;

            posicao=(inicio+fim)/2;
        }
    }
    else {
        for(i = 0; i < num_elems; i++)
            if(*(lista[i]) == elemento)
                return i;

        return ELEMENTO_NAO_EXISTENTE;
    }
}

int lista_obter_elemento(int posicao, int **lista) {
    return *(lista[posicao]);
}

int lista_inserir(int elemento, int **lista, int tam) {
    int i, num_elems, pos;
    num_elems = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam, 0);

    if(num_elems >= tam)
        return LISTA_CHEIA;

    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    lista[num_elems] = malloc(sizeof(int));
    *(lista[num_elems]) = elemento;

    return SUCESSO;
}

int lista_remover(int elemento, int **lista, int tam) {
    int i, num_elems, pos;

    num_elems = lista_numero_elementos(lista, tam);
    pos = lista_posicao_elemento(elemento, lista, tam, 0);

    if(num_elems <= 0)
        return LISTA_VAZIA;

    if(pos == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    //remocao
    free(lista[pos]);

    //realocar posteriores
    for(i = pos; i < num_elems; i++)
        lista[i] = lista[i + 1];

    lista[i] = NULL;
}

void lista_exibir(int** lista, int tam) {
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

void lista_destruir(int **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++)
        free(lista[i]);
    free(lista);
}

int main () {
    int **lista;
    int tam = 7, elemento = 5, ordenada = 1, pos;

    lista = lista_ler(tam, tam);

    lista_exibir(lista, tam);

    pos = lista_posicao_elemento(elemento, lista, tam, ordenada);

    printf("\n\nElemento %d esta na posicao %d", elemento, pos);

}

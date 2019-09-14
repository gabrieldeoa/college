#ifndef LISTA_DE_INTEIROS
#define LISTA_DE_INTEIROS

#include <stdio.h>
#include <stdlib.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

/*
    Biblioteca para se trabalhar com lista sequencial de inteiros.
    OBS: Anotações somente para ajudar a entender e lembrar o passo-a-passo do algoritmo.
*/

/*
    REPRESENTACAO
    <TIPO> ** <INDENTIFICADOR>
    int **lista;
*/

// CRIACAO DE LISTA - dado um tamanho parametrizado retorna uma lista
int** lista_criar(int tam) {
    int **lista;
    lista = calloc(tam, sizeof(int*[tam]));
    return lista;
}

// CONTAGEM DE ELEMENTOS - dado uma lista e seu tamanho retorna a qtd de elementos validos na mesma.
int lista_numero_elementos(int **lista, int tam) {
    int i, elementos = 0;

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    for(i = 0; i < tam; i++)
        if(lista[i] != NULL)
            elementos++;

    return elementos;
}

// OBTER POSICAO DE UM ELEMENTO - dado uma elemento, a lista e o tamanho da mesma retorna o posicao do elemento.
int lista_posicao_elemento(int elem, int **lista, int tam) {
    int i, num_elems;

    num_elems = lista_numero_elementos(lista, tam);

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    for(i = 0; i < num_elems; i++)
        if(lista[i]!=NULL)
            if(*(lista[i]) == elem)
                return i;

    return ELEMENTO_NAO_EXISTENTE;
}

// OBTER UM ELEMENTO NA LISTA - dada a posicao e a lista retorna o elemento(seu conteudo)
int lista_obter_elemento(int pos, int** lista) {
    return *(lista[pos]);
}

//INSERIR UM ELEMENTO NA LISTA - dado o elemento, a lista e seu tamanho insere um elemento e retorna flag de sucesso
int lista_inserir(int elem, int** lista, int tam) {
    int i, num_elems;

    num_elems = lista_numero_elementos(lista, tam);

    if(num_elems >= tam)
        return LISTA_CHEIA;

    if(lista_posicao_elemento(elem, lista, tam) != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    for(i = 0; i < tam; i++) {
        if(lista[i] == NULL) {
            lista[i] = malloc(sizeof(int));
            *(lista[i]) = elem;
            return SUCESSO;
        }
    }
}

//REMOVER ELEMENTO - dado o elemento, a lista e seu tamanho remove o elemento e retorna flag de sucesso
int lista_remover(int elem, int** lista, int tam) {
    int i, num_elems, pos;

    num_elems = lista_numero_elementos(lista, tam);

    pos = lista_posicao_elemento(elem, lista, tam);

    if(num_elems <= 0) return LISTA_VAZIA;

    if(pos == ELEMENTO_NAO_EXISTENTE) return ELEMENTO_NAO_EXISTENTE;

    free(lista[pos]); // exclusao

    lista[pos] = NULL;

}

// EXIBIR UMA LISTA - dado a lista printa-se seu conteudo
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

// LER UMA LISTA - dado um tamanho maximo da lista e a quantidade de elementos que espera-se ler retorna a lista preenchida
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

// DESTRUIR UMA LISTA - dado a lista e seu tamanho a desaloca da memoria
void lista_destruir(int** lista, int tam) {
    int i;

    for(i = 0; i < tam; i++)
        free(lista[i]);
    free(lista);
}
// EXERCICIO 2
int** lista_realocar(int** lista, int tam, int novo_tam) {
    int** novaLista = lista_criar(novo_tam);
    int i, elemento;
    for(i = 0; i < tam; i++ ) {
        if(lista[i] != NULL)
            elemento = *(lista[i]);
            lista_inserir(elemento, novaLista, novo_tam);
    }

    lista_destruir(lista, tam);

    return novaLista;
}

#endif

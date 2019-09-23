/*
Contrua uma rotina que amplie o tamanho máximo de uma lista já existente,
preservando os valores presentes nela.
Para isso, aloque uma nova lista com o tamanho desejado e transfira os valores da
lista existente para ela e lembre-se de eliminar a lista antiga.
*/

#include "lista.h"

int ** lista_redimensionar(int **lista, int tamanho, int novo_tamanho) {
    int i, elemento;
    int **nova_lista;
    
    nova_lista = lista_criar(novo_tamanho);

    for(i = 0; i < tamanho; i++) {
        if(lista[i] != NULL) {
            elemento = lista_obter_elemento(i, lista);
            lista_inserir(elemento, nova_lista, novo_tamanho);
        }
    }

    lista_destruir(lista, tamanho);

    return nova_lista;
}

#include <stdio.h>
#include <stdlib.h>
#include "list-2-1.h"

main() {
    int **lista, **nova;
    int tam = 3, elemento, pos, opcao;

    lista = lista_ler(tam, tam);

    lista_exibir(lista, tam);


    printf("\nTotal de elementos: %d", lista_numero_elementos(lista, tam));

    printf("\nDigite o elemento a ser buscado na lista: ");
    scanf("%d", &elemento);

    pos = lista_posicao_elemento(elemento, lista, tam);

    printf("\nA posicao do elemento %d e %d \n", elemento, pos);

    lista_remover(elemento, lista, tam);

    lista_exibir(lista, tam);

    printf("\nDigite o elemento a ser inserido na lista: ");
    scanf("%d", &elemento);

    lista_inserir(elemento, lista, tam);

    lista_exibir(lista, tam);

    nova = lista_realocar(lista, tam, tam+1);

    lista_exibir(nova, tam+1);


}

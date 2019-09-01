#include <stdio.h>
#include <stdlib.h>
#include "ListaCaracter.h"

int main () {
    const int TAM = 3;
    char elemento;

    char **listaC = lerListaChar(TAM);

    exibirListaChar(listaC, TAM);

    printf("\nO Tamanho da lista e %d", tamanhoDaListaChar(listaC, TAM));

    printf("\nForneca um elemento e saiba sua posicao na lista: ");
    scanf("\n%c", &elemento);

    printf("\nO elemento %c esta na posicao %d", elemento, posicaoDoElementoChar(elemento, listaC, TAM));

    printf("\nForneca um elemento para ser removido: ");
    scanf("\n%c", &elemento);

    removerElemento(elemento, listaC, TAM);
    exibirListaChar(listaC, TAM);
    printf("\nO Tamanho da lista e %d", tamanhoDaListaChar(listaC, TAM));

    printf("\nForneca um elemento para ser inserido: ");
    scanf("\n%c", &elemento);
    inserirElementoChar(elemento, listaC, TAM);

    printf("\nO Tamanho da lista e %d", tamanhoDaListaChar(listaC, TAM));
    printf("\n\n");
    exibirListaChar(listaC, TAM);
    printf("\n\n");

    destruirListaChar(listaC, TAM);
    exibirListaChar(listaC, TAM);
}

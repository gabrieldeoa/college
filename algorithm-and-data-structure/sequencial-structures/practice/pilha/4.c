#include "3.h"

void pilha_carta_cortar(pilha *p, int posicao_corte) {
    int i, ne;
    pilha auxiliar;

    ne = pilha_carta_numero_elementos(*p);

    pilha_carta_criar(&auxiliar, p->tamanho);

    //loop p/ pegar as cartas a partir do corte ate o topo e adicionar no inicio da pilha
    for(i = posicao_corte; i < ne; i++)
        pilha_carta_inserir(p->elementos[i], &auxiliar);
    //loop p/ pegar abaixo do corte ate o inicio e adicionar no fim da pilha
    for(i = 0; i < posicao_corte; i++)
        pilha_carta_inserir(p->elementos[i], &auxiliar);

    *p = auxiliar;
}
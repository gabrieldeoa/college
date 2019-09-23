#include "pilha.h"

//gabarito do mestre - ele considera que a pilha 1 tenha espaço para comportar a pilha 2
void pilha_empilhar(pilha *p1, pilha *p2) {
    int i, ne;
    ne = pilha_numero_elementos(*p2);

    for(i = 0; i < ne; i++) {
        pilha_inserir(pilha_obter_elemento(i, *p2), p1);
    }

    pilha_destruir(p2);
}

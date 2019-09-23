#include "3.h"

carta pilha_carta_comprar(pilha * p) {
    int ne;
    carta carta;

    ne = pilha_carta_numero_elementos(*p);

    if(ne > 0) {
        carta = pilha_carta_obter_elemento(p->topo, *p);
        pilha_carta_remover(p);
    }

    return carta;
}
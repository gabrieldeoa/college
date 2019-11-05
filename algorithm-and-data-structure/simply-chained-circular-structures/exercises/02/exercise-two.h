#include "../../list/list.h"

void lista_remover_elementos(lista listaUm, lista listaDois) {
    no_enc *noUm, *noDois;

    noUm = listaUm;
    noDois = listaDois;

    do {
        lista_remover(noDois->elemento, &listaUm);
        noDois = noDois->proximo;
    } while(noDois != listaDois);

}
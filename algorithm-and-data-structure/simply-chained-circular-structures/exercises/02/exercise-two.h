#include "../../list/list.h"

void lista_remover_elementos(lista *listaUm, lista listaDois) {
    no_enc *no;

    no = listaDois;

    do {
        lista_remover(no->elemento, listaUm);
        no = no->proximo;
    } while(no != listaDois);

}
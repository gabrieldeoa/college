#include "../../list/list.h"


void lista_exibir_intercalada(lista lista) {
    no_dup_enc *noInicial, *noFinal;

    noInicial = lista;
    noFinal = noInicial->anterior;

    do {
        printf("%d|", noInicial->elemento);
        printf("%d|", noFinal->elemento);

        noInicial = noInicial->proximo;
        noFinal = noFinal->anterior;

        if(noFinal == noInicial)
            printf("%d|", noInicial->elemento);
    } while(noInicial != noFinal && noInicial->anterior != noFinal);
}
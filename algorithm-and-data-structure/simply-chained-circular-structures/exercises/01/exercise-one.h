#include "../../queue/queue.h"

fila fila_unificar_filas(fila filaUm, fila filaDois) {
    no_enc *noUm, * noDois;
    fila filaUnificada;

    noUm = filaUm;
    noDois = filaDois;
    filaUnificada = NULL;

    //insere todos da fila um
    do {
        fila_inserir(noUm->elemento, &filaUnificada);
        noUm = noUm->proximo;
    } while(noUm != filaUm);

    //insere todos da fila dois
    do {
        fila_inserir(noDois->elemento, &filaUnificada);
        noDois = noDois->proximo;
    } while(noDois != filaDois);


    return filaUnificada;
}
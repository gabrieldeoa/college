#include "../../../doubly-chained-structures/queue/queue.h"


void fila_converter_nao_circular_para_circular(fila fila) {
    no_dup_enc *noInicial, *noFinal;

    noInicial = noFinal = fila;

    while(noFinal->proximo != NULL)
        noFinal = noFinal->proximo;

    noInicial->anterior = noFinal;

    noFinal->proximo = noInicial;
}